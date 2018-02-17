

//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************
#ifndef VARILLA_H
#define VARILLA_H

#include "Varilla.h"
#include "Cilindro.h"

class Varilla{
private:
    Cilindro varilla;
    Cilindro tope;

    void Transformaciones_Cilindro() const;
    void Transformaciones_Tope() const;

public:
    void DrawPoints() const;
    void DrawLines() const;
    void DrawFill() const;
    void DrawChess() const;

};

#endif // VARILLA_H
