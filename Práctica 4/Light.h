//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 4
//**************************************************************************

#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glew.h>
#include "glwidget.h"
#include "vertex.h"

class Light{
private:
    float ang_x, ang_y, ang_z, ang_1;
    float distancia;
public:
    Light();
    void LightOff();
    void LightOff_1() const;
    void LightOff_2() const;
    void LightOn_1();
    void LightOn_2();
    void MoverLuzX();
    void MoverLuzY();
    void MoverLuzZ();
    void AumentarDistancia();
    void DisminuirDistancia();
    void MoverLuz1();
};

#endif
