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

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <vector>
#include <vertex.h>

struct Vertex{
    float x;
    float y;
    float z;
};

class O3DS{
public:
    std::vector<Vertex> Vertices;

    void DrawPoints() const;
};

#endif

