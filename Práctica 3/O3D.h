//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#ifndef O3D_H
#define O3D_H

#include <vector>
#include <vertex.h>
#include "O3DS.h"

class O3D : public O3DS{
public:
    std::vector<_vertex3i> Triangulos;

    void DrawLines() const;
    void DrawFill() const;
    void DrawChess() const;

};

#endif

