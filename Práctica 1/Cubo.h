//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#ifndef CUBO_H
#define CUBO_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include "O3D.h"

class Cubo : public O3D{
private:
    float tam_arista;

public:
    Cubo (const float &tamanio = 1.0);

};

#endif
