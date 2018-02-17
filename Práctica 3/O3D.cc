//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include "O3DS.h"
#include "O3D.h"
#include <GL/glew.h>
#include <QOpenGLWidget>

using namespace std;

void O3D::DrawLines() const{
    if (!Triangulos.empty()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(1.5);

        glBegin(GL_TRIANGLES);
        glColor3f(0,0,1);
            for (unsigned int i = 0; i<Triangulos.size(); i++){
                glVertex3f(Vertices[Triangulos[i]._0].x, Vertices[Triangulos[i]._0].y, Vertices[Triangulos[i]._0].z);
                glVertex3f(Vertices[Triangulos[i]._1].x, Vertices[Triangulos[i]._1].y, Vertices[Triangulos[i]._1].z);
                glVertex3f(Vertices[Triangulos[i]._2].x, Vertices[Triangulos[i]._2].y, Vertices[Triangulos[i]._2].z);
            }
        glEnd();

        glLineWidth(1);

    }
}
void O3D::DrawFill() const{
    if (!Triangulos.empty()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glBegin(GL_TRIANGLES);
        glColor3f(0,255,255);
            for (unsigned int i = 0; i<Triangulos.size(); i++){
                glVertex3f(Vertices[Triangulos[i]._0].x, Vertices[Triangulos[i]._0].y, Vertices[Triangulos[i]._0].z);
                glVertex3f(Vertices[Triangulos[i]._1].x, Vertices[Triangulos[i]._1].y, Vertices[Triangulos[i]._1].z);
                glVertex3f(Vertices[Triangulos[i]._2].x, Vertices[Triangulos[i]._2].y, Vertices[Triangulos[i]._2].z);
            }
        glEnd();
    }
}

void O3D::DrawChess() const{
    if (!Triangulos.empty()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_TRIANGLES);
            for (unsigned int i = 0; i<Triangulos.size(); i++){
                if (i%2 == 0) glColor3f(1,0,0);
                else glColor3f(0,1,0);

                glVertex3f(Vertices[Triangulos[i]._0].x, Vertices[Triangulos[i]._0].y, Vertices[Triangulos[i]._0].z);
                glVertex3f(Vertices[Triangulos[i]._1].x, Vertices[Triangulos[i]._1].y, Vertices[Triangulos[i]._1].z);
                glVertex3f(Vertices[Triangulos[i]._2].x, Vertices[Triangulos[i]._2].y, Vertices[Triangulos[i]._2].z);
            }
        glEnd();
    }
}

