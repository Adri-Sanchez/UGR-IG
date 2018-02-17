#ifndef GLWIDGET_H
#define GLWIDGET_H
//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "O3DS.h"
#include "Cubo.h"
#include "Tetraedro.h"
#include "O3DPLY.h"
#include "O3DR.h"
#include "Peon.h"
#include "Cilindro.h"
#include "Cono.h"
#include "Vaso.h"
#include "VasoInv.h"
#include "Tubo.h"
#include "RelojArena.h"
#include "Esfera.h"
#include "ReguladorWatt.h"
#include "Brazo.h"
#include "Light.h"
#include "Tablero.h"

namespace _gl_widget_ne {

  //const _vertex3f COLORS[]={{0,0,0},{1,0,0},{0,1,0},{0,0,1},{0,1,1},{1,0,1},{1,1,0},{1,1,1}};

  const float TAM = 16.0/9.0;
  const float X_MIN=-TAM;
  const float X_MAX=TAM;
  const float Y_MIN=-1;
  const float Y_MAX=1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=10;

  const float ANGLE_STEP=1;

  // axis
  const int AXIS_SIZE=5000;
}


class _window;

class _gl_widget : public QOpenGLWidget
{
    Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

public slots:
  void idle();

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  // Booleanos para el control del modo de dibujado
  bool PointMode;
  bool LineMode;
  bool FillMode;
  bool ChessMode;
  bool Iluminacion;
  bool Textura;
  bool IluminacionMode;
  int Figure;

  /*
   *---------------------------
   *|    ÍNDICE DE TECLAS    |
   *---------------------------
   *
   *    1 - Cubo
   *    2 - Tetraedro
   *    3 - Open-PLY
   *    4 - Cilindro
   *    5 - Peón
   *    6 - Vaso
   *    7 - Vaso Invertido
   *    8 - Cono
   *    9 - Tubo
   *    G - Esfera
   *
   *    'E' - Regulador de Watt
   *        · 'J' - Incrementar velocidad
   *        · 'K' - Decrementar velocidad
   *        · 'N' - Subir brazos
   *        · 'M' - Bajar brazos
   *        · 'H' - Comenzar animación (Incrementar/Decrementar velocidad indefinidamente)
   *
   *    'R' - Brazo (Regulador de Watt)
   *
   *    PRACTICA 4
   *    'i' - Activar/desactivar iluminación
   *    't' - Activar/desactivar textura
   *    'S' - Alternar entre sombreado plano y Gouraud
   *    F1  - Mover luz 1 (X)
   *    F2  - Mover luz 1 (Y)
   *    F3  - Mover luz 1 (Z)
   *    F4  - Mover luz 2
   *    F5  - Alejar Luz 1
   *    F6  - Acercar Luz 2
   *    F7  - Material 1
   *    F8  - Material 2
   *    F9  - Material 3
   *    F10  - Tablero 1
   *    F11  - Tablero 2
   *    F12  - Tablero 3
   */
  // Figuras creadas
  Cubo cubo;
  Tetraedro tetra;
  O3DPLY Ply;
  Cilindro Rev_1;
  Peon Rev_2;
  Vaso Rev_3;
  VasoInv Rev_4;
  Cono Rev_5;
  Tubo Rev_6;
  RelojArena Rev_7;
  Esfera Rev_8;

  // Práctica 3
  ReguladorWatt Regulador;
  bool animacion, dir_animacion;
  QTimer *timer;
  Brazo brazo;

  // Práctica 4
  Light luz;
  Tablero tabla;
  int Material;
  bool light1, light2;
  bool tableroA, tableroB, tableroC;
};

#endif
