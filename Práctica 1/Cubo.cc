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
#include <GL/glew.h>
#include <QOpenGLWidget>

Cubo::Cubo(const float &tamanio){
    Vertices.resize(8);
    Triangulos.resize(12);

    tam_arista = tamanio;

    float tam = tam_arista/2.0;

    // Geometría
    Vertices[0] = {-tam, -tam, tam};
    Vertices[1] = {tam, -tam, tam};
    Vertices[2] = {-tam, tam, tam};
    Vertices[3] = {tam, tam, tam};
    Vertices[4] = {-tam, -tam, -tam};
    Vertices[5] = {tam, -tam, -tam};
    Vertices[6] = {-tam, tam, -tam};
    Vertices[7] = {tam, tam, -tam};

    // Definición de Caras
    Triangulos[0] = {0, 1, 2};
    Triangulos[1] = {2, 1, 3};

    Triangulos[2] = {1, 5, 3};
    Triangulos[3] = {5, 7, 3};

    Triangulos[4] = {7, 5, 4};
    Triangulos[5] = {7, 4, 6};

    Triangulos[6] = {6, 4, 0};
    Triangulos[7] = {6, 0, 2};

    Triangulos[8] = {6, 2, 3};
    Triangulos[9] = {6, 3, 7};

    Triangulos[10] = {0, 1, 4};
    Triangulos[11] = {4, 1, 5};
}
