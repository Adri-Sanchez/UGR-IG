//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "Esfera.h"
#include "O3DR.h"
#include <vector>
#include "vertex.h"

Esfera::Esfera(){
    std::vector<_vertex3f> perfil;
    float radio, angulo, x, y;
    int rev = 36;

    radio  = 0.5;

    for (int i = 0; i <= rev; i++){
        angulo = i*(180/rev); // Necesitamos únicamente 180º para representar un perfil.

        angulo += 270;        // Sumamos 270º para corresponder a la parte inferior de nuestro perfil.

        x = radio * cos(angulo * pi/180);
        y = radio * sin(angulo * pi/180);

        perfil.push_back( _vertex3f(x, y, 0.0) );
    }

    O3DR R(perfil, 48, _vertex3f(0,0,0), 0.0, 360.0);

    this->Vertices   = R.Vertices;
    this->Triangulos = R.Triangulos;

     this->CalculoNormales();
}
