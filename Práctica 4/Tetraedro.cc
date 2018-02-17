//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "Tetraedro.h"
#include "O3D.h"
#include "O3DS.h"
#include <GL/glew.h>
#include <QOpenGLWidget>

Tetraedro::Tetraedro(const float &tam_arista, const float &altura){
    Vertices.resize(4);
    Triangulos.resize(4);

   // Geometría
    Vertices[0] = _vertex3f(0              ,  altura/2,               0);
    Vertices[1] = _vertex3f(0              , -altura/2,    tam_arista/2);
    Vertices[2] = _vertex3f(tam_arista/2   , -altura/2,   -tam_arista/2);
    Vertices[3] = _vertex3f(-tam_arista/2  , -altura/2,   -tam_arista/2);

    Triangulos[0] = _vertex3i(0, 1, 2);
    Triangulos[1] = _vertex3i(0, 2, 3);
    Triangulos[2] = _vertex3i(0, 3, 1);
    Triangulos[3] = _vertex3i(3, 1, 2);

     this->CalculoNormales();

}
