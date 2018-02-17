//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************

#include "Brazo.h"
#include <GL/glew.h>

Brazo::Brazo(){
    beethoven.loadPly("ply/beethoven.ply"); // EXAMEN
}

void Brazo::Transformacion_cilindro() const{
    glPushMatrix();

    glTranslatef(0, 3.5, 0);
    glScalef(0.3, 7.5, 0.3);
}

void Brazo::Transformacion_esfera() const{
    glPushMatrix();

    glTranslatef(0, 7.5, 0);
    glScalef(1.5, 1.5, 1.5);
}

void Brazo::Transformacion_beethoven() const{ // EXAMEN
    glPushMatrix();

    glTranslatef(1.10, 7.5, 0);
    glRotatef(-90, 0, 0, 1);
    glScalef(0.06, 0.06, 0.06);
}

void Brazo::DrawPoints() const{
    glMatrixMode(GL_MODELVIEW);

    // Esfera
    Transformacion_esfera();
    esfera.DrawPoints();
    glPopMatrix();

    // Beethoven (EXAMEN)
    Transformacion_beethoven();
    beethoven.DrawPoints();
    glPopMatrix();

    // Cilindro
    Transformacion_cilindro();
    cilindro.DrawPoints();
    glPopMatrix();
}

void Brazo::DrawLines() const{
    glMatrixMode(GL_MODELVIEW);

    // Esfera
    Transformacion_esfera();
    esfera.DrawLines();
    glPopMatrix();

    // Beethoven (EXAMEN)
    Transformacion_beethoven();
    beethoven.DrawLines();
    glPopMatrix();

    // Cilindro
    Transformacion_cilindro();
    cilindro.DrawLines();
    glPopMatrix();
}

void Brazo::DrawFill() const{
    glMatrixMode(GL_MODELVIEW);

    // Esfera
    Transformacion_esfera();
    esfera.DrawFill();
    glPopMatrix();

    // Beethoven (EXAMEN)
    Transformacion_beethoven();
    beethoven.DrawFill();
    glPopMatrix();

    // Cilindro
    Transformacion_cilindro();
    cilindro.DrawFill();
    glPopMatrix();
}

void Brazo::DrawChess() const{
    glMatrixMode(GL_MODELVIEW);

    // Esfera
    Transformacion_esfera();
    esfera.DrawChess();
    glPopMatrix();

    // Beethoven (EXAMEN)
    Transformacion_beethoven();
    beethoven.DrawChess();
    glPopMatrix();

    // Cilindro
    Transformacion_cilindro();
    cilindro.DrawChess();
    glPopMatrix();
}
