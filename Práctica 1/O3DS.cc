//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "O3DS.h"
#include <GL/glew.h>
#include <QOpenGLWidget>

using namespace std;

void O3DS::DrawPoints() const{
    if (!Vertices.empty()){
        glPointSize(5);
        glColor3f(0,0,0);

        glBegin(GL_POINTS);
            for (unsigned int i = 0; i<Vertices.size(); i++){
                glVertex3f(Vertices[i].x, Vertices[i].y, Vertices[i].z);
            }
        glEnd();
    }
}
