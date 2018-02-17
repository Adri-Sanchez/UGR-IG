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
#include "Material.h"


Material::Material(const _vertex4f &amb, const _vertex4f &diff, const _vertex4f &spec, float shine){
    this->ambient  = amb;
    this->diffuse  = diff;
    this->specular = spec;
    this->shininess = shine;
}

void Material::UsarMaterial() const{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,  (GLfloat *) &ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  (GLfloat *) &diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess*128.0);

    glPopMatrix();
}
