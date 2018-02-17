//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "O3DPLY.h"
#include "file_ply_stl.h"
#include <GL/glew.h>
#include <QOpenGLWidget>

using namespace std;

O3DPLY::O3DPLY(const string &ply){

    if (ply != ""){
        this->loadPly(ply);
    }
}

void O3DPLY::loadPly(const string &ply){
    _file_ply File_ply;

    if (File_ply.open(ply)){
        File_ply.read(Vertices, Triangulos);
    }

    File_ply.close();

    this->CalculoNormales();
}
