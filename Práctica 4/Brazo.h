//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************
#ifndef BRAZO_H
#define BRAZO_H

#include "Esfera.h"
#include "O3DPLY.h"
#include "Cilindro.h"

class Brazo{
private:
    Cilindro cilindro;
    Esfera esfera;
    O3DPLY beethoven;

    void Transformacion_cilindro() const;
    void Transformacion_esfera() const;
    void Transformacion_beethoven() const;

public:
    Brazo();
    void DrawPoints() const;
    void DrawLines() const;
    void DrawFill() const;
    void DrawChess() const;
};

#endif // BRAZO_H
