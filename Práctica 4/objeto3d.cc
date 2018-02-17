//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#include <O3DS.h>
#include <GL/glew.h>
#include <QOpenGLWidget>

using namespace std;

objeto3d::objeto3d(){
    objeto_definido = false;
}

bool objeto3d::Empty() const{
    return objeto_definido;
}

objeto3d::Cubo(const float &tamanio){
    Vertices.resize(8);
    Aristas.resize(12);
    Triangulos.resize(12);

    Cubo::tam_arista = tamanio;
    objeto_definido = true;
    draw_mode = 0;

    float tam = tam_arista/2.0;

    Vertices[0] = {-tam, -tam, tam};
    Vertices[1] = {tam, -tam, tam};
    Vertices[2] = {-tam, tam, tam};
    Vertices[3] = {tam, tam, tam};
    Vertices[4] = {-tam, -tam, -tam};
    Vertices[5] = {tam, -tam, -tam};
    Vertices[6] = {-tam, tam, -tam};
    Vertices[7] = {tam, tam, -tam};
}

objeto3d::Tetraedro(const float &tam_arista, const float &altura){
    Vertices.resize(4);
    Aristas.resize(6);
    Triangulos.resize(4);

   Tetraedro::tam = tam;
   Tetraedro::altura = altura;
   objeto_definido = true;
   draw_mode = 0;
}

void objeto3d::DrawMode(const int &mode){
    if (objeto_definido){
        draw_mode = mode;
    }
}

void objeto3d::Draw(){
    if (objeto_definido){
        switch (draw_mode){
        case 1: // Vértices
            glBegin(GL_POINTS);

                for (unsigned int i = 0; i<Vertices.size(); i++){
                    glVertex3f(Vertices[i].x, Vertices[i].y, Vertices[i].z);
                }

            glEnd();
        break;

        case 2: // Aristas
            glBegin(GL_LINES);

                for (unsigned int i = 0; i<Aristas.size(); i++){
                   glVertex3f(Vertices[Aristas[i]._0].x, Vertices[Aristas[i]._0].y, Vertices[Aristas[i]._0].z);
                   glVertex3f(Vertices[Aristas[i]._1].x, Vertices[Aristas[i]._1].y, Vertices[Aristas[i]._1].z);
                }

            glEnd();
        break;

        case 3: // Caras
            glBegin(GL_TRIANGLES);

                for (unsigned int i = 0; i<Triangulos.size(); i++){
                   glVertex3f(Triangulos[i]._0->x, Triangulos[i]._0->y, Triangulos[i]._0->z);
                   glVertex3f(Triangulos[i]._1->x, Triangulos[i]._1->y, Triangulos[i]._1->z);
                   glVertex3f(Triangulos[i]._2->x, Triangulos[i]._2->y, Triangulos[i]._2->z);
                }

            glEnd();
        break;

        case 4: // Ajedrez
            glBegin();

            glEnd();
        break;

        default: break;
        }
    }
}



