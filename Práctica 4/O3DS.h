//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#ifndef O3DS_H
#define O3DS_H

#include <vector>
#include <vertex.h>

class O3DS{
public:
    std::vector<_vertex3f> Vertices;

    void DrawPoints() const;
};

#endif

