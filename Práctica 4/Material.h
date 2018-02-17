//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 4
//**************************************************************************

#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glew.h>
#include "glwidget.h"
#include "vertex.h"
#include <vector>

class Material{
private:
    _vertex4f ambient,
              diffuse,
              specular;
    float shininess;
public:
    Material(const _vertex4f &amb, const _vertex4f &diff, const _vertex4f &spec, float shine);
    void UsarMaterial() const;
};

#endif
