//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 1
//**************************************************************************

#ifndef O3D_H
#define O3D_H

#include <vector>
#include <vertex.h>
#include "O3DS.h"

class O3D : public O3DS{
private:
    std::vector<int> NumNormales;
public:
    std::vector<_vertex3i> Triangulos;
    std::vector<_vertex3f> Normales;
    std::vector<_vertex3f> NormalesVertices;

    void DrawLines() const;
    void DrawFill() const;
    void DrawChess() const;
    void FlatShading() const;
    void GouraudShading() const;
    void CalculoNormales();
    void Material1() const;
    void Material2() const;
    void Material3() const;
};

#endif

