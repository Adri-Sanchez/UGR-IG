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
#include <cmath>
#include "Material.h"

using namespace std;

void O3D::CalculoNormales(){
    _vertex3f u, v, w;
    float longitud;
    vector<_vertex3f> aux;

    NormalesVertices.resize(Vertices.size(), _vertex3f(0.0, 0.0, 0.0));
    NumNormales.resize(Vertices.size(), 0);

    for (unsigned int i = 0; i < Triangulos.size(); i++){
        u( Vertices[Triangulos[i]._1].x - Vertices[Triangulos[i]._0].x
         , Vertices[Triangulos[i]._1].y - Vertices[Triangulos[i]._0].y
         , Vertices[Triangulos[i]._1].z - Vertices[Triangulos[i]._0].z );

        v( Vertices[Triangulos[i]._2].x - Vertices[Triangulos[i]._0].x
         , Vertices[Triangulos[i]._2].y - Vertices[Triangulos[i]._0].y
         , Vertices[Triangulos[i]._2].z - Vertices[Triangulos[i]._0].z );

      /*
       * |uy  uz|        |ux  uz|         |ux  uy|
       * |vy  vz| * i  - |vx  vz| * j   + |vx  vy| * k  = u x v = w
       *
       *  Producto vectorial
       */

        w(  (u.y * v.z) - (u.z * v.y)
         ,-((u.x * v.z) - (u.z * v.x))
         ,  (u.x * v.y) - (u.y * v.x));

        longitud = sqrt( w.x*w.x + w.y*w.y + w.z*w.z );

        w.x /= longitud;
        w.y /= longitud;
        w.z /= longitud;



        Normales.push_back(w);
    }
    aux.resize(Vertices.size());

    for (unsigned int i = 0; i < Triangulos.size(); i++){
        aux[Triangulos[i]._0] += Normales[i];
        aux[Triangulos[i]._1] += Normales[i];
        aux[Triangulos[i]._2] += Normales[i];
    }

    for (unsigned int i = 0; i < aux.size(); i++){

        longitud = sqrt( pow(aux[i].x, 2) + pow(aux[i].y, 2) + pow(aux[i].z, 2) );

        NormalesVertices[i].x = aux[i].x/longitud;
        NormalesVertices[i].y = aux[i].y/longitud;
        NormalesVertices[i].z = aux[i].z/longitud;
    }

}

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

void O3D::FlatShading() const{
    if (!Triangulos.empty()){

       // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glShadeModel(GL_FLAT);

        glBegin(GL_TRIANGLES);

            for (unsigned int i = 0; i<Triangulos.size(); i++){
                glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
                glVertex3f(Vertices[Triangulos[i]._0].x, Vertices[Triangulos[i]._0].y, Vertices[Triangulos[i]._0].z);
                glVertex3f(Vertices[Triangulos[i]._1].x, Vertices[Triangulos[i]._1].y, Vertices[Triangulos[i]._1].z);
                glVertex3f(Vertices[Triangulos[i]._2].x, Vertices[Triangulos[i]._2].y, Vertices[Triangulos[i]._2].z);
            }
        glEnd();
    }
}

void O3D::GouraudShading() const{
    if (!Triangulos.empty()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glShadeModel(GL_SMOOTH);

        glBegin(GL_TRIANGLES);
            for (unsigned int i = 0; i<Triangulos.size(); i++){
                glNormal3f(NormalesVertices[Triangulos[i]._0].x, NormalesVertices[Triangulos[i]._0].y, NormalesVertices[Triangulos[i]._0].z);
                glVertex3f(Vertices[Triangulos[i]._0].x, Vertices[Triangulos[i]._0].y, Vertices[Triangulos[i]._0].z);
                glNormal3f(NormalesVertices[Triangulos[i]._1].x, NormalesVertices[Triangulos[i]._1].y, NormalesVertices[Triangulos[i]._1].z);
                glVertex3f(Vertices[Triangulos[i]._1].x, Vertices[Triangulos[i]._1].y, Vertices[Triangulos[i]._1].z);
                glNormal3f(NormalesVertices[Triangulos[i]._2].x, NormalesVertices[Triangulos[i]._2].y, NormalesVertices[Triangulos[i]._2].z);
                glVertex3f(Vertices[Triangulos[i]._2].x, Vertices[Triangulos[i]._2].y, Vertices[Triangulos[i]._2].z);

            }
        glEnd();
    }
}

void O3D::Material1() const{
    _vertex4f amb = {0.135, 0.225, 0.1575, 1.0};
    _vertex4f dif = {0.54, 0.89, 0.63, 1.0};
    _vertex4f spe = {0.316228, 0.316228, 0.316228, 1.0};

    Material mat(amb, dif, spe, 0.1);

    mat.UsarMaterial();
}

void O3D::Material2() const{
    _vertex4f amb = {0.1745, 0.01175, 0.01175, 1.0};
    _vertex4f dif = {0.61424, 0.04136, 0.04136, 1.0};
    _vertex4f spe = {0.727811, 0.626959, 0.626959, 1.0};

    Material mat(amb, dif, spe, 0.6);

    mat.UsarMaterial();
}

void O3D::Material3() const{
    _vertex4f amb = {0.24725, 0.1995, 0.0745, 1.0};
    _vertex4f dif = {0.75164, 0.60648, 0.22648, 1.0};
    _vertex4f spe = {0.628281, 0.555802, 0.366065, 1.0};

    Material mat(amb, dif, spe, 0.4);

    mat.UsarMaterial();
}

