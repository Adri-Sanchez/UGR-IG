//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "O3D.h"
#include "Cubo.h"
#include "O3DS.h"
#include "vertex.h"
#include <GL/glew.h>
#include <QOpenGLWidget>

Cubo::Cubo(const float &tamanio){
    Vertices.resize(8);
    Triangulos.resize(12);

    tam_arista = tamanio;

    float tam = tam_arista/2.0;

    // Geometría
    Vertices[0] = _vertex3f(-tam, -tam, tam);
    Vertices[1] = _vertex3f(tam, -tam, tam);
    Vertices[2] = _vertex3f(-tam, tam, tam);
    Vertices[3] = _vertex3f(tam, tam, tam);
    Vertices[4] = _vertex3f(-tam, -tam, -tam);
    Vertices[5] = _vertex3f(tam, -tam, -tam);
    Vertices[6] = _vertex3f(-tam, tam, -tam);
    Vertices[7] = _vertex3f(tam, tam, -tam);

    // Definición de Caras
    Triangulos[0] = _vertex3i(0, 1, 2);
    Triangulos[1] = _vertex3i(2, 1, 3);

    Triangulos[2] = _vertex3i(1, 5, 3);
    Triangulos[3] = _vertex3i(5, 7, 3);

    Triangulos[4] = _vertex3i(7, 5, 4);
    Triangulos[5] = _vertex3i(7, 4, 6);

    Triangulos[6] = _vertex3i(6, 4, 0);
    Triangulos[7] = _vertex3i(6, 0, 2);

    Triangulos[8] = _vertex3i(6, 2, 3);
    Triangulos[9] = _vertex3i(6, 3, 7);

    Triangulos[10] = _vertex3i(0, 1, 4);
    Triangulos[11] = _vertex3i(4, 1, 5);

    this->CalculoNormales();
}
