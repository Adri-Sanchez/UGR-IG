//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************

#include "glwidget.h"
#include <QPainter>
#include <QPaintEngine>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QCoreApplication>
#include <QFileDialog>
#include <QTimer>
#include <QOpenGLWidget>
#include <math.h>
#include <vector>
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
  animacion = false;
  timer = new QTimer(this);
  dir_animacion = true;
  Iluminacion = false;
  Material = 0;
  light1 = true;
  light2 = true;
}
//*************************************************************************
//
//*************************************************************************

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  case Qt::Key_P:
      if (PointMode == false){
        PointMode = true;
      }
      else PointMode = false;
  break;
  case Qt::Key_L:
      if (LineMode == false){
        LineMode = true;
      }
      else LineMode = false;
  break;
  case Qt::Key_F:
      if (FillMode == false){
        ChessMode = false;
        FillMode = true;
      }
      else FillMode = false;
  break;
  case Qt::Key_C:
      if (ChessMode == false){
        ChessMode = true;
        FillMode = false;
      }
      else ChessMode = false;
  break;

  case Qt::Key_I: // On/Off Iluminación
      if (Iluminacion == false){
        Iluminacion = true;
      }
      else{
        Iluminacion = false;
        luz.LightOff();
      }
  break;
  case Qt::Key_T: // On/Off Textura
      if (Textura == false){
        Textura = true;
        //---------------
      }
      else Textura = false;;
  break;
  case Qt::Key_S: // Flat/Gouraud
      if (Iluminacion == true){
          if (IluminacionMode == false){
              IluminacionMode = true;
          }
          else{
              IluminacionMode = false;
          }
      }
  break;

  case Qt::Key_0: Figure = 0; break; // Nada
  case Qt::Key_1: Figure = 1; break; // Cubo
  case Qt::Key_2: Figure = 2; break; // Tetraedro
  case Qt::Key_3: Figure = 3;        // Figura PLY
  {
   QString fileName = QFileDialog::getOpenFileName(this,
        tr("Abrir archivo .ply"), QDir::currentPath(), tr("Archivo Ply (*.ply)"));

    /*
       * QString está codificada en UTF-16, std::String en UTF-8
       * Para leer archivos .ply, necesitamos String.
    */
    string utf8 = fileName.toUtf8().constData();

    Ply.loadPly(utf8); }
  break;
  case Qt::Key_4: Figure = 4; break; // Figura por Revolución
  case Qt::Key_5: Figure = 5; break;
  case Qt::Key_6: Figure = 6; break;
  case Qt::Key_7: Figure = 7; break;
  case Qt::Key_8: Figure = 8; break;
  case Qt::Key_9: Figure = 9; break;
  case Qt::Key_G: Figure = 11; break;
  case Qt::Key_E: Figure = 12; break; // Práctica 3 - Regulador de Watt
  case Qt::Key_R: Figure = 13; break; // Examen - Brazo con beethoven
  case Qt::Key_J: if (Figure == 12) Regulador.IncrementarVelocidad(); break;
  case Qt::Key_K: if (Figure == 12) Regulador.DecrementarVelocidad(); break;
  case Qt::Key_N: if (Figure == 12) Regulador.Subir(); break;
  case Qt::Key_M: if (Figure == 12) Regulador.Bajar(); break;
  case Qt::Key_F1: luz.MoverLuzX(); break;  // Práctica 4 - Iluminación
  case Qt::Key_F2: luz.MoverLuzY(); break;
  case Qt::Key_F3: luz.MoverLuzZ(); break;
  case Qt::Key_F4: luz.MoverLuz1(); break;
  case Qt::Key_F5: luz.AumentarDistancia(); break;
  case Qt::Key_F6: luz.DisminuirDistancia(); break;
  case Qt::Key_F7: Material = 1; break;
  case Qt::Key_F8: Material = 2; break;
  case Qt::Key_F9: Material = 3; break;
  case Qt::Key_F10:
      if (Figure == 14 && tableroA){
          glDisable(GL_TEXTURE_2D);
          Figure = 0;
      }
      else{
        Figure = 14;
        tableroA = true;
        tableroB = tableroC = false;
      }
              break; // TABLERO 1
  case Qt::Key_F11:
      if (Figure == 14 && tableroB){
          glDisable(GL_TEXTURE_2D);
          Figure = 0;
      }
      else{
        Figure = 14;
        tableroB = true;
        tableroA = tableroC = false;
      }
      break;
  case Qt::Key_F12:
      if (Figure == 14 && tableroC){
          glDisable(GL_TEXTURE_2D);
          Figure = 0;
      }
      else{
        Figure = 14;
        tableroC = true;
        tableroA = tableroB = false;
      }

  case Qt::Key_Q:
      if (light1){
          light1 = false;
      }
      else{
          light1 = true;
      }
            break;
  case Qt::Key_Z:
      if (light2){
          light2 = false;
      }
      else{
          light2 = true;
      }
            break;
  case Qt::Key_H:{

      if (!animacion){
          connect(timer, SIGNAL(timeout()), this, SLOT(idle()));

          timer->start();

          animacion = true;
      }
      else{
          timer->stop();

          animacion = false;

          delete timer;

          timer = new QTimer(this);
      }
    }
    break;


  }

  update();
}

//**************************************************************************
//
//***************************************************************************

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  //  Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void _gl_widget::draw_axis()
{
  glBegin(GL_LINES);
  // eje X, color rojo
  glColor3f(1,0,0);
  glVertex3f(-AXIS_SIZE,0,0);
  glVertex3f(AXIS_SIZE,0,0);
  // eje Y, color verde
  glColor3f(0,1,0);
  glVertex3f(0,-AXIS_SIZE,0);
  glVertex3f(0,AXIS_SIZE,0);
  // eje Z, color azul
  glColor3f(0,0,1);
  glVertex3f(0,0,-AXIS_SIZE);
  glVertex3f(0,0,AXIS_SIZE);
  glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void _gl_widget::draw_objects()
{
    if (Iluminacion){
        if (light1)
            luz.LightOn_1();
        else
            luz.LightOff_1();

        if (light2)
            luz.LightOn_2();
        else
            luz.LightOff_2();
    }
    else{
        luz.LightOff();
    }
    if (Material == 1){
        cubo.Material1();
    }
    else if (Material == 2){
        cubo.Material2();
    }
    else if (Material == 3){
        cubo.Material3();
    }

    switch (Figure){
    case 1:
        if (Iluminacion){
            if (IluminacionMode){
                cubo.FlatShading();
            }
            else{
                cubo.GouraudShading();
            }

        }
        if (PointMode){
            cubo.DrawPoints();
        }
        if (LineMode){
            cubo.DrawLines();
        }
        if (FillMode){
            cubo.DrawFill();
        }
        if (ChessMode){
            cubo.DrawChess();
        }

    break;
    case 2:
        if (Iluminacion){
            if (IluminacionMode){
                tetra.FlatShading();
            }
            else{
                tetra.GouraudShading();
            }
        }
        if (PointMode){
            tetra.DrawPoints();
        }
        if (LineMode){
            tetra.DrawLines();
        }
        if (FillMode){
            tetra.DrawFill();
        }
        if (ChessMode){
            tetra.DrawChess();
        }

    break;
    case 3:
        if (Iluminacion){
            if (IluminacionMode){
                Ply.FlatShading();
            }
            else{
                Ply.GouraudShading();
            }
        }
        if (PointMode){
            Ply.DrawPoints();
        }
        if (LineMode){
             Ply.DrawLines();
        }
        if (FillMode){
             Ply.DrawFill();
        }
        if (ChessMode){
             Ply.DrawChess();
        }

    break;
    case 4:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_1.FlatShading();
            }
            else{
                Rev_2.GouraudShading();
            }
        }
        if (PointMode){
            Rev_1.DrawPoints();
        }
        if (LineMode){
             Rev_1.DrawLines();
        }
        if (FillMode){
             Rev_1.DrawFill();
        }
        if (ChessMode){
             Rev_1.DrawChess();
        }

    break;
    case 5:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_2.FlatShading();
            }
            else{
                Rev_2.GouraudShading();
            }
        }
        if (PointMode){
            Rev_2.DrawPoints();
        }
        if (LineMode){
             Rev_2.DrawLines();
        }
        if (FillMode){
             Rev_2.DrawFill();
        }
        if (ChessMode){
             Rev_2.DrawChess();
        }

    break;
    case 6:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_3.FlatShading();
            }
            else{
                Rev_3.GouraudShading();
            }
        }
        if (PointMode){
            Rev_3.DrawPoints();
        }
        if (LineMode){
             Rev_3.DrawLines();
        }
        if (FillMode){
             Rev_3.DrawFill();
        }
        if (ChessMode){
             Rev_3.DrawChess();
        }

    break;
    case 7:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_4.FlatShading();
            }
            else{
                Rev_4.GouraudShading();
            }
        }
        if (PointMode){
            Rev_4.DrawPoints();
        }
        if (LineMode){
             Rev_4.DrawLines();
        }
        if (FillMode){
             Rev_4.DrawFill();
        }
        if (ChessMode){
             Rev_4.DrawChess();
        }

    break;
    case 8:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_5.FlatShading();
            }
            else{
                Rev_5.GouraudShading();
            }
        }
        if (PointMode){
            Rev_5.DrawPoints();
        }
        if (LineMode){
             Rev_5.DrawLines();
        }
        if (FillMode){
             Rev_5.DrawFill();
        }
        if (ChessMode){
             Rev_5.DrawChess();
        }

    break;
    case 9:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_6.FlatShading();
            }
            else{
                Rev_6.GouraudShading();
            }
        }
        if (PointMode){
            Rev_6.DrawPoints();
        }
        if (LineMode){
             Rev_6.DrawLines();
        }
        if (FillMode){
             Rev_6.DrawFill();
        }
        if (ChessMode){
             Rev_6.DrawChess();
        }

    break;
    case 10:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_7.FlatShading();
            }
            else{
                Rev_7.GouraudShading();
            }
        }
        if (PointMode){
            Rev_7.DrawPoints();
        }
        if (LineMode){
             Rev_7.DrawLines();
        }
        if (FillMode){
             Rev_7.DrawFill();
        }
        if (ChessMode){
             Rev_7.DrawChess();
        }

    break;
    case 11:
        if (Iluminacion){
            if (IluminacionMode){
                Rev_8.FlatShading();
            }
            else{
                Rev_8.GouraudShading();
            }
        }
        if (PointMode){
            Rev_8.DrawPoints();
        }
        if (LineMode){
             Rev_8.DrawLines();
        }
        if (FillMode){
             Rev_8.DrawFill();
        }
        if (ChessMode){
             Rev_8.DrawChess();
        }

    break;
    case 12:
        if (PointMode){
            Regulador.DrawPoints();
        }
        if (LineMode){
             Regulador.DrawLines();
        }
        if (FillMode){
             Regulador.DrawFill();
        }
        if (ChessMode){
             Regulador.DrawChess();
        }
    break;
    case 13:
        if (PointMode){
            brazo.DrawPoints();
        }
        if (LineMode){
             brazo.DrawLines();
        }
        if (FillMode){
             brazo.DrawFill();
        }
        if (ChessMode){
             brazo.DrawChess();
        }
    break;
    case 14:
        tabla.Load();
        if (tableroA){
            tabla.DrawA();
        }
        else if (tableroB){
            tabla.DrawB();
        }
        else if (tableroC){
            tabla.DrawC();
        }
    break;
    default: break;
    }
}


void _gl_widget::idle(){
   bool max;
   bool min;

    if (dir_animacion){
        Regulador.IncrementarVelocidad();

        max = Regulador.maxVelocidad();

        if (max)
            dir_animacion = false;

    }
    else if (!dir_animacion){
        Regulador.DecrementarVelocidad();

        min = Regulador.minVelocidad();
        if (min)
            dir_animacion = true;

    }

    update();
}
//*************************************************************************
//
//*************************************************************************

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_axis();
  draw_objects();
}

//*************************************************************************
//
//*************************************************************************

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


//*************************************************************************
//
//*************************************************************************

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
    }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  glewExperimental = GL_TRUE;
  int err = glewInit();
  if (GLEW_OK != err){
    std::cerr << "Error: " << glewGetErrorString(err) << "\n";
    exit (-1);
    }

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;
}

