//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#ifndef TETRAEDRO_H
#define TETRAEDRO_H

#include "O3D.h"

class Tetraedro : public O3D{
private:
    float tam_arista;
    float altura;

public:
    Tetraedro(const float &tam_arista =1.0, const float &altura =1.0);

};

#endif

