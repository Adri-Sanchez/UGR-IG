//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************

#include "Base.h"
#include <GL/glew.h>

void Base::Transformaciones() const{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glScalef(8,1,8);
}

void Base::DrawPoints() const{
    this->Transformaciones();

    base.DrawPoints();
    glPopMatrix();
}

void Base::DrawLines() const{
    this->Transformaciones();

    base.DrawLines();
    glPopMatrix();
}

void Base::DrawFill() const{
    this->Transformaciones();

    base.DrawFill();
    glPopMatrix();
}

void Base::DrawChess() const{
    this->Transformaciones();

    base.DrawChess();
    glPopMatrix();
}
