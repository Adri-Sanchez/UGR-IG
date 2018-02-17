#ifndef GLWIDGET_H
#define GLWIDGET_H
//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
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

namespace _gl_widget_ne {

  //const _vertex3f COLORS[]={{0,0,0},{1,0,0},{0,1,0},{0,0,1},{0,1,1},{1,0,1},{1,1,0},{1,1,1}};

  const float X_MIN=-1;
  const float X_MAX=1;
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
  int Figure;

  /*
   *---------------------------
   *|    ÍNDICE DE FIGURAS    |
   *---------------------------
   *
   * 1 - Cubo
   * 2 - Tetraedro
   * 3 - Open-PLY
   * 4 - Cilindro
   * 5 - Peón
   * 6 - Vaso
   * 7 - Vaso Invertido
   * 8 - Cono
   * 9 - Tubo
   * F10 - Reloj Arena / Diábolo
   * F11 - Esfera
   * 'T' - Regulador de Watt
   * 'R' - Brazo (Regulador de Watt)
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
};

#endif
