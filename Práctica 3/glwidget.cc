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
  case Qt::Key_F10: Figure = 10; break;
  case Qt::Key_F11: Figure = 11; break;
  case Qt::Key_T: Figure = 12; break; // Práctica 3 - Regulador de Watt
  case Qt::Key_R: Figure = 13; break; // Examen - Brazo con beethoven
  case Qt::Key_J: if (Figure == 12) Regulador.IncrementarVelocidad(); break;
  case Qt::Key_K: if (Figure == 12) Regulador.DecrementarVelocidad(); break;
  case Qt::Key_N: if (Figure == 12) Regulador.Subir(); break;
  case Qt::Key_M: if (Figure == 12) Regulador.Bajar(); break;

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

    switch (Figure){
    case 1:
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
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;
}

