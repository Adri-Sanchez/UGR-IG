//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#ifndef O3DPLY_H
#define O3DPLY_H

#include <string>
#include "O3D.h"


class O3DPLY : public O3D{
public:
    O3DPLY(const string &ply = "");
    void loadPly(const string &ply);
};

#endif
