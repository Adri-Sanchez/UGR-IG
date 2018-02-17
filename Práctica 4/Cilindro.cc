//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "Cilindro.h"
#include "O3DR.h"
#include <vector>
#include "vertex.h"

Cilindro::Cilindro(){
    std::vector<_vertex3f> perfil;

    perfil.push_back( _vertex3f(0.0, -0.5, 0.0) );
    perfil.push_back( _vertex3f(0.5, -0.5, 0.0) );
    perfil.push_back( _vertex3f(0.5,  0.5, 0.0) );
    perfil.push_back( _vertex3f(0.0,  0.5, 0.0) );

    O3DR R(perfil, 24, _vertex3f(0,0,0), 0.0, 360.0);

    this->Vertices   = R.Vertices;
    this->Triangulos = R.Triangulos;

    this->CalculoNormales();
}
