//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 4
//**************************************************************************

#include <GL/glew.h>
#include "glwidget.h"
#include "Light.h"


Light::Light(){
    ang_1 = 0.0;
    ang_1 = 0.0;
    ang_1 = 0.0;
    ang_1 = 0.0;
    distancia = 10.0;
}

void Light::LightOn_1(){
    GLfloat luz_ambiente [] = {0.3, 0.3, 0.3, 0.0};

    glEnable (GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_ambiente);
    glEnable (GL_LIGHT0);

    GLfloat pos1[] = {distancia, distancia, distancia, 1};
    glPushMatrix();
        glRotatef(ang_z, 0, 0, 1);
        glRotatef(ang_x, 1, 0, 0);
        glRotatef(ang_y, 0, 1, 0);
        glLightfv(GL_LIGHT0, GL_POSITION, pos1);

    glPopMatrix();
}

void Light::LightOn_2(){
    GLfloat luz_difusa [] = {1.0, 1.0, 1.0, 1.0};

    glEnable (GL_LIGHTING);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luz_difusa);
    glEnable (GL_LIGHT1);

    GLfloat pos2[] = {10, 10, 10, 0.0};
    glPushMatrix();
        glRotatef(ang_1, 0, 1, 0);
        glLightfv(GL_LIGHT1, GL_POSITION, pos2);
    glPopMatrix();
}


void Light::LightOff(){
    glDisable(GL_LIGHT0);
    glDisable (GL_LIGHT1);
    glDisable (GL_LIGHTING);
}

void Light::LightOff_1() const{
    glDisable(GL_LIGHT0);
}

void Light::LightOff_2() const{
    glDisable(GL_LIGHT1);
}

void Light::MoverLuzX(){
    ang_x += 15.0;

    if (ang_x == 360.0)
        ang_x = 0.0;
}

void Light::MoverLuzY(){
    ang_y += 15.0;

    if (ang_y == 360.0)
        ang_y = 0.0;
}

void Light::MoverLuzZ(){
    ang_z += 15.0;

    if (ang_z == 360.0)
        ang_z = 0.0;
}

void Light::AumentarDistancia(){
    distancia += 0.1;
}

void Light::DisminuirDistancia(){
    distancia -= 0.1;
}

void Light::MoverLuz1(){
    ang_1 += 15.0;

    if (ang_1 == 360.0)
        ang_1 = 0.0;
}
