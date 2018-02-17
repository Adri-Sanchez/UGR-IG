//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#ifndef O3DR_H
#define O3DR_H

#include <vector>
#include <vertex.h>
#include "O3D.h"

class O3DR : public O3D{
public:
    static constexpr double pi = 3.14159265358;
    O3DR();
    O3DR(const vector<_vertex3f> &perfil, const unsigned int &revo = 12, const _vertex3f &eje = _vertex3f(0,0,0), const double &ang_ini = 0.0, const double &ang_fin = 360.0);
};

#endif
