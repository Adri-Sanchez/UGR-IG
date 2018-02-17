//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "RelojArena.h"
#include "O3DR.h"
#include <vector>
#include "vertex.h"

RelojArena::RelojArena(){
    std::vector<_vertex3f> perfil;

    float radio, angulo, x, y;
    int rev = 15;

    perfil.push_back( _vertex3f(0.0, -0.5, 0.0) );
    perfil.push_back( _vertex3f(0.5, -0.5, 0.0) );

    radio  = perfil[1].x;

    for (int i = 0; i < rev; i++){
        angulo = i*(90/rev);

        x = radio * cos(angulo * pi/180);
        y = radio * sin(angulo * pi/180);

        perfil.push_back( _vertex3f(x, y-0.5, 0.0) );
    }

     perfil.push_back( _vertex3f(0.0, 0.0, 0.0) );

    for (int i = 1; i <= rev; i++){
        angulo = i*(90/rev);

        angulo+=270;

        x = radio * cos(angulo * pi/180);
        y = radio * sin(angulo * pi/180);

        perfil.push_back( _vertex3f(x, y+0.5, 0.0) );
    }

    perfil.push_back( _vertex3f(0.0, 0.5, 0.0) );

    O3DR R(perfil, 48, _vertex3f(0,0,0), 0.0, 360.0);

    this->Vertices   = R.Vertices;
    this->Triangulos = R.Triangulos;
}
