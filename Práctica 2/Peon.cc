//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "O3DR.h"
#include "Peon.h"
#include "vertex.h"
#include <GL/glew.h>
#include <QOpenGLWidget>

Peon::Peon(){
    std::vector<_vertex3f> perfil;

    perfil.push_back(_vertex3f(0.0, -1.4, 0.0));
    perfil.push_back(_vertex3f(1.0, -1.4, 0.0));
    perfil.push_back(_vertex3f(1.0, -1.1, 0.0));
    perfil.push_back(_vertex3f(0.5, -0.7, 0.0));
    perfil.push_back(_vertex3f(0.4, -0.4, 0.0));
    perfil.push_back(_vertex3f(0.4,  0.5, 0.0));
    perfil.push_back(_vertex3f(0.5,  0.6, 0.0));
    perfil.push_back(_vertex3f(0.3,  0.6, 0.0));
    perfil.push_back(_vertex3f(0.5,  0.8, 0.0));
    perfil.push_back(_vertex3f(0.55, 1.0, 0.0));
    perfil.push_back(_vertex3f(0.5,  1.2, 0.0));
    perfil.push_back(_vertex3f(0.3,  1.4, 0.0));
    perfil.push_back(_vertex3f(0.0,  1.4, 0.0));

    O3DR R(perfil, 48, _vertex3f(0,0,0), 0.0, 360.0);

    this->Triangulos = R.Triangulos;
    this->Vertices   = R.Vertices;
}
