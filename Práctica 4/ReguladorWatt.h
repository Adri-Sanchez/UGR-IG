//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************
#ifndef REGULADORWATT_H
#define REGULADORWATT_H

#include "Base.h"
#include "Varilla.h"
#include "Cilindro.h"
#include "Brazo.h"

class ReguladorWatt{
private:
    // Objetos para la construcción del modelo
    Base base;
    Varilla varilla;
    Brazo brazo;
    Cilindro enganche;
    Cilindro tope;
    Cilindro regulador;

    ////////////////////////////////
    ///   Variables del modelo   ///
    ////////////////////////////////
    // Respectivas a la altura del modelo y de sus componentes.
    float alturaTope;
    float alturaMin;
    float alturaMax;
    float incremento_altura;

    // Respectivas a ángulos dentro del modelo
    float angulo;
    float angulo_brazo;
    float angulo_enganche;
    float incremento_angulo;

    // Respectivas a la velocidad del modelo
    float velocidad, umbral_velocidad, incremento_velocidad;
    bool max_velocidad, min_velocidad;
    float dif_velocidad;


    void DrawMode(const int &mode) const;
    void CalculoAngular();
public:
    ReguladorWatt ();
    void DrawPoints() const;
    void DrawLines() const;
    void DrawFill() const;
    void DrawChess() const;
    void IncrementarVelocidad();
    void DecrementarVelocidad();
    void Subir();
    void Bajar();
    void ResetRegulador();

    float getVelocidad();
    float getAltura();
    bool maxVelocidad();
    bool minVelocidad();
};

#endif // REGULADORWATT_H
