//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 4
//**************************************************************************

#include "Tablero.h"
#include <GL/glew.h>
#include "glwidget.h"
#include <QImage>



void Tablero::Transformaciones() const{
   // glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-0.0051);
    glScalef(5,5,0.01);
}

void Tablero::Load(){


     if (Imagen.load("imagen.png")==false) cout << "Image not loaded" << endl;

     Imagen=Imagen.mirrored(false,true);
     //
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     // parametros de aplicacion de la textura
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
     // asignacion de la textura
     glTexImage2D(GL_TEXTURE_2D,0,4,Imagen.width(),Imagen.height(),0,GL_BGRA,GL_UNSIGNED_BYTE,Imagen.bits());
}

void Tablero::DrawA() const{
    this->Transformaciones();

    tablero.DrawFill();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-2.5, 2.5 , 0.0); //
        glTexCoord2f(1.0, 1.0);
        glVertex3f(2.5, 2.5, 0.0); //
        glTexCoord2f(1.0, 0.0);
        glVertex3f(2.5, -2.5, 0.0); //
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-2.5, -2.5, 0.0); //
    glEnd();
}

void Tablero::DrawB() const{
    this->Transformaciones();

    tablero.DrawFill();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.5);
        glVertex3f(-2.5, -2.5, 0.0); //
        glTexCoord2f(1.0, 0.5);
        glVertex3f(2.5, -2.5, 0.0); //
        glTexCoord2f(1.0, 1.0);
        glVertex3f(2.5, 0.5, 0.0); //
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-2.5, 0.5, 0.0); //
    glEnd();
}

void Tablero::DrawC() const{
    this->Transformaciones();

    tablero.DrawFill();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-0.5, 0.5 , 0.0); //
        glTexCoord2f(1.0, 1.0);
        glVertex3f(0.5, 0.5, 0.0); //
        glTexCoord2f(1.0, 0.0);
        glVertex3f(0.5, -0.5, 0.0); //
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-0.5, -0.5, 0.0); //
    glEnd();
}

