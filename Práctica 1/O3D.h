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

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <vector>
#include <vertex.h>
#include "O3DS.h"

struct Triangle{
    int _0;
    int _1;
    int _2;
};

class O3D : public O3DS{
public:
    std::vector<Triangle> Triangulos;

    void DrawLines() const;
    void DrawFill() const;
    void DrawChess() const;

};

#endif

