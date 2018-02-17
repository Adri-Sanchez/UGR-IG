//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 4
//**************************************************************************
#ifndef TABLERO_H
#define TABLERO_H

#include "Cubo.h"
#include <QImage>

class Tablero{
private:
    Cubo tablero;
    QImage Imagen;

    void Transformaciones() const;
public:
    void DrawA() const;
    void DrawB() const;
    void DrawC() const;
    void Load();
};

#endif
