//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "O3DR.h"
#include <GL/glew.h>
#include <QOpenGLWidget>
#include <cmath>
#include <iostream>
using namespace std;

O3DR::O3DR(){}

O3DR::O3DR(const vector<_vertex3f> &perfil, const unsigned int &revo, const _vertex3f &eje, const double &ini, const double &fin){
    float radio, x, z;
    double angulo;
    unsigned int i, j, k, j_post;
    bool terminado = false, corte = false;

    double ang_ini = ini;
    double ang_fin = fin;
    unsigned int rev = revo;

    if (ang_ini != 0.0 || ang_fin != 360.0){
        corte = true;
    }

    /*
     * Revolución de perfil y creación del vector de vértices.
     */
    for (i = 0; i < perfil.size(); i++){
        radio = perfil[i].x;

        if (radio != eje.x){
            for (j = rev; j > 0; j--){
                angulo = j*( (ang_fin-ang_ini)/rev);
                angulo = angulo * pi/180.0;
                angulo += ang_ini;

                x = radio * cos(angulo);
                z = radio * sin(angulo);

                Vertices.push_back( _vertex3f(x,perfil[i].y,z) );
            }
        }
        else
            Vertices.push_back(perfil[i]);
    }
    /*
     * Descripción del algoritmo DyV:
     * @ i -> Índice del vértice correspondiente al nivel actual de revolución en el perfil. (Nivel indica puntos con igual "y").
     * @ j -> Índice del vértice actual que estamos visitando.
     * @ k -> Índice del vértice que delimita un triángulo formado por j y su posterior (j_post)
     */

    i = 0;

    while (!terminado){

        if (i+rev >= Vertices.size()) // Todos los vértices recorridos (Caso Base).
            terminado = true;

        else if (Vertices[i].x != 0){ // Vértices revolucionados.
            for (j = i; j < i+rev; j++){

                j_post = i+( ((j+1)-i)%rev );

                if (j_post != i || !corte){

                    if (Vertices[i+rev].x != 0){
                        k = j+rev;

                        Triangulos.push_back( _vertex3i(k, j_post, j_post+rev ));
                    }
                    else
                        k = i+rev;

                        Triangulos.push_back( _vertex3i(k, j, j_post ));
                    }
            }


            i = j;
        }

        else{ // Vértices situados en el origen de coordenadas.
            i++;

            for (j = i; j < i+rev; j++){
                j_post = i+( ((j+1)-i)%rev );
                if (j_post != i || !corte) Triangulos.push_back( _vertex3i(j, i-1, j_post) );
            }
        }
    }

}


/*
FUNCION ORIGINAL DE ROTAR

for (i = 0; i < perfil.size(); i++){
        radio = perfil[i].x;

        if (radio != eje.x){
            for (j = rev; j > 0; j--){
                angulo = j*(360.0/rev) * pi/180;

                x = radio * cos(angulo);
                z = radio * sin(angulo);

                Vertices.push_back( _vertex3f(x,perfil[i].y,z) );
            }
        }
        else
            Vertices.push_back(perfil[i]);
    }

ALGORITMO ORIGINAL DE CONSTRUCCION DE CARAS

    i = 0;

    while (!terminado){

        if (i+rev >= Vertices.size()) // Todos los vértices recorridos (Caso Base).
            terminado = true;

        else if (Vertices[i].x != 0){ // Vértices revolucionados.
            for (j = i; j < i+rev; j++){

                j_post = i+( ((j+1)-i)%rev );

                if (Vertices[i+rev].x != 0){
                    k = j+rev;

                    Triangulos.push_back( _vertex3i(k, j_post, j_post+rev ));
                }
                else
                    k = i+rev;

                    Triangulos.push_back( _vertex3i(k, j, j_post ));
            }

            i = j;
        }

        else{ // Vértices situados en el origen de coordenadas.
            i++;

            for (j = i; j < i+rev; j++){
                Triangulos.push_back( _vertex3i(j, i-1, i+( ((j+1)-i)%rev )) );
            }
        }
    }

}


*/



