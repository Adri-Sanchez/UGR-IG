//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************

#include "Varilla.h"
#include <GL/glew.h>

void Varilla::Transformaciones_Cilindro() const{
    glPushMatrix();
    glTranslatef(0.0, 6.0, 0.0);
    glScalef(0.5, 12.0, 0.5);
}

void Varilla::Transformaciones_Tope() const{
    glPushMatrix();
    glTranslatef(0, 12.5, 0);
    glScalef(1.5, 1, 1.5);
}

void Varilla::DrawPoints() const{
    glMatrixMode(GL_MODELVIEW);

    // Cilindro central
    Transformaciones_Cilindro();
    varilla.DrawPoints();
    glPopMatrix();

    // Cilindro tope;
    Transformaciones_Tope();
    tope.DrawPoints();
    glPopMatrix();
}

void Varilla::DrawLines() const{
    glMatrixMode(GL_MODELVIEW);

    // Cilindro central
    Transformaciones_Cilindro();
    varilla.DrawLines();
    glPopMatrix();

    // Cilindro tope;
    Transformaciones_Tope();
    tope.DrawLines();
    glPopMatrix();
}

void Varilla::DrawFill() const{
    glMatrixMode(GL_MODELVIEW);

    // Cilindro central
    Transformaciones_Cilindro();
    varilla.DrawFill();
    glPopMatrix();

    // Cilindro tope;
    Transformaciones_Tope();
    tope.DrawFill();
    glPopMatrix();
}

void Varilla::DrawChess() const{
    glMatrixMode(GL_MODELVIEW);

    // Cilindro central
    Transformaciones_Cilindro();
    varilla.DrawChess();
    glPopMatrix();

    // Cilindro tope;
    Transformaciones_Tope();
    tope.DrawChess();
    glPopMatrix();
}
