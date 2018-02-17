//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************
#ifndef BASE_H
#define BASE_H

#include "Cubo.h"

class Base{
private:
    Cubo base;

    void Transformaciones() const;
public:

    void DrawPoints() const;
    void DrawLines() const;
    void DrawFill() const;
    void DrawChess() const;

};

#endif
