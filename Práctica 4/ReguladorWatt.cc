//**************************************************************************
//
// Adrián Sánchez Cerrillo
// Grupo A1 - Ingeniería Informática
// adrisanchez@correo.ugr.es
//
// Informática Gráfica - Práctica 3
//**************************************************************************

#include "ReguladorWatt.h"
#include <GL/glew.h>
#include <cmath>

ReguladorWatt::ReguladorWatt(){
    ResetRegulador();
}

/*
 * DrawMode
 *
 * Método que, dependiendo del argumento por referencia constante 'mode', realiza un modo determinado de dibujado.
 * Este método es de visibilidad privada, se llamará desde las respectivas funciones Draw(Points,Lines..) para no
 * modificar el nombre de las funciones con las que dibujar.
 */
void ReguladorWatt::DrawMode(const int &mode) const{
    glMatrixMode(GL_MODELVIEW);

    // Base

    switch (mode){
        case 1: base.DrawPoints(); break;
        case 2: base.DrawLines(); break;
        case 3: base.DrawFill(); break;
        case 4: base.DrawChess(); break;
        default: break;
    }
    glPushMatrix(); // 1
        glRotatef(angulo, 0, 1, 0);

        // Eje Central
        glPushMatrix(); // 2
            glTranslatef(0,1,0);

            switch (mode){
                case 1: varilla.DrawPoints(); break;
                case 2: varilla.DrawLines(); break;
                case 3: varilla.DrawFill(); break;
                case 4: varilla.DrawChess(); break;
                default: break;
            }
        glPopMatrix(); // 2

    // Brazos
    glPushMatrix(); // 3
        glTranslatef(0, 13.5, 0);

        glPushMatrix(); // 4

            glRotatef(angulo_brazo, 0, 0, 1);

            switch (mode){
                case 1: brazo.DrawPoints(); break;
                case 2: brazo.DrawLines(); break;
                case 3: brazo.DrawFill(); break;
                case 4: brazo.DrawChess(); break;
                default: break;
            } // Brazo 1

        glPopMatrix(); // 4

        glPushMatrix(); // 5

            glRotatef(-angulo_brazo, 0, 0, 1);

            glRotatef(180, 0, 1, 0);

            switch (mode){
                case 1: brazo.DrawPoints(); break;
                case 2: brazo.DrawLines(); break;
                case 3: brazo.DrawFill(); break;
                case 4: brazo.DrawChess(); break;
                default: break;
            } // Brazo 2

        glPopMatrix(); // 5

    glPopMatrix(); // 3


    // Tope
    glTranslatef(0, alturaTope, 0);
    glPushMatrix(); // 6

        glScalef(1.5, 1, 1.5);

        switch (mode){
            case 1: tope.DrawPoints(); break;
            case 2: tope.DrawLines(); break;
            case 3: tope.DrawFill(); break;
            case 4: tope.DrawChess(); break;
            default: break;
        }

    glPopMatrix(); // 6

    glPushMatrix(); // 7
    glTranslatef(-0.58, -3.5, 0);
    glScalef(0.15, 6, 0.15);

    switch (mode){
        case 1: tope.DrawPoints(); break;
        case 2: tope.DrawLines(); break;
        case 3: tope.DrawFill(); break;
        case 4: tope.DrawChess(); break;
        default: break;
    }

    glPopMatrix(); // 7


    // Enganches

    glPushMatrix(); // 8

    glRotatef(angulo_enganche, 0, 0, 1);
    glTranslatef(0, 2.25, 0);
    glScalef(0.15, 4.5, 0.15);

    switch (mode){
        case 1: enganche.DrawPoints(); break;
        case 2: enganche.DrawLines(); break;
        case 3: enganche.DrawFill(); break;
        case 4: enganche.DrawChess(); break;
        default: break; // Enganche 1
    }

    glPopMatrix(); // 8

    glPushMatrix(); // 9
    glRotatef(180, 0, 1, 0);
    glRotatef(angulo_enganche, 0, 0, 1);
    glTranslatef(0, 2.25, 0);
    glScalef(0.15, 4.5, 0.15);

    switch (mode){
        case 1: enganche.DrawPoints(); break;
        case 2: enganche.DrawLines(); break;
        case 3: enganche.DrawFill(); break;
        case 4: enganche.DrawChess(); break;
        default: break; // Enganche 2
    }

    glPopMatrix(); // 9

    glPopMatrix(); // 1*/
}


void ReguladorWatt::DrawPoints() const{
    this->DrawMode(1);
}

void ReguladorWatt::DrawLines() const{
    this->DrawMode(2);
}

void ReguladorWatt::DrawFill() const{
    this->DrawMode(3);
}

void ReguladorWatt::DrawChess() const{
    this->DrawMode(4);
}

void ReguladorWatt::IncrementarVelocidad(){

    if (velocidad > 0){            // La velocidad puede ser negativa o positiva (Dependiendo de la dirección de giro).
        if (!max_velocidad){
            dif_velocidad = angulo;

            velocidad += incremento_velocidad;

            if (velocidad > umbral_velocidad){                // Se establece una velocidad umbral, a partir de dicha velocidad (de giro), el modelo comenzará a subir
                alturaTope = alturaTope + incremento_altura;
                CalculoAngular(); // Mediante el método privado CalculoAngular(), se realiza una actualización de los ángulos del modelo dependiendo de los atributos.
                velocidad += 0.01;
            }

            angulo += velocidad;

            if (alturaTope >= alturaMax){
                max_velocidad = true;
                dif_velocidad = angulo - dif_velocidad;
                velocidad = dif_velocidad;
            }
         }
        else{
            angulo+=velocidad;
        }
    }
    else{ // Si el modelo gira hacia el lado contrario (velocidad negativa), con los cálculos presentados posteriormente se "frenará" poco a poco. (Mientras la velocidad sea negativa)
        velocidad += incremento_velocidad;

        if (velocidad < -umbral_velocidad && alturaTope > alturaMin){
            alturaTope = alturaTope - incremento_altura;
            CalculoAngular();
            velocidad += 0.01;
        }

        angulo += velocidad;

        if (alturaTope < alturaMax){
            min_velocidad = false;
        }
    }
}

void ReguladorWatt::DecrementarVelocidad(){

    if (velocidad > 0){
        velocidad -= incremento_velocidad;

        if (velocidad > umbral_velocidad && alturaTope > alturaMin){
            alturaTope = alturaTope - incremento_altura;
            CalculoAngular();
            velocidad -= 0.01;
        }

        angulo += velocidad;

        if (alturaTope < alturaMax){
            max_velocidad = false;
        }
    }
    else{

        if (!min_velocidad){
            dif_velocidad = angulo;
            velocidad -= incremento_velocidad;

            if (velocidad < -umbral_velocidad){
                alturaTope = alturaTope + incremento_altura;
                CalculoAngular();
                velocidad -= 0.01;
            }

            angulo += velocidad;

            if (alturaTope >= alturaMax){
                min_velocidad = true;
                dif_velocidad = angulo - dif_velocidad;
                velocidad = dif_velocidad;
            }
        }
        else{
            angulo += velocidad;
        }
    }
}

void ReguladorWatt::Subir(){

    if (!max_velocidad){
        alturaTope = alturaTope + incremento_altura;
        min_velocidad = false;
        CalculoAngular();
    }

    if (alturaTope >= alturaMax){
        max_velocidad = true;
    }
}



void ReguladorWatt::Bajar(){

    if (!min_velocidad){
        alturaTope = alturaTope - incremento_altura;
        max_velocidad = false;
        CalculoAngular();
    }

    if (alturaTope <= 8.0){
        min_velocidad = true;
    }
}

void ReguladorWatt::CalculoAngular(){
    // Para el cálculo de los ángulos, procedemos con el teorema del coseno.
    float tam_enganche = 4.5;
    float tam_brazo    = 4.5;
    float dif_altura   = (alturaMax - alturaTope) + 1;

    angulo_brazo = 180 - acos( (pow(tam_brazo, 2) + pow(dif_altura,2) - pow(tam_enganche, 2)) / (2*(dif_altura)*tam_brazo)    ) * (180/3.1415926535);
    angulo_enganche =    acos( (pow(tam_enganche, 2) + pow(dif_altura,2) - pow(tam_brazo, 2)) / (2*(dif_altura)*tam_enganche) ) * (180/3.1415926535);
}

bool ReguladorWatt::maxVelocidad(){ return max_velocidad; }

bool ReguladorWatt::minVelocidad(){ return min_velocidad; }

float ReguladorWatt::getVelocidad(){ return velocidad; }

float ReguladorWatt::getAltura(){ return alturaTope; }

void ReguladorWatt::ResetRegulador(){
    angulo = 0.0;
    velocidad = 0.0;
    alturaTope = 8.0;
    max_velocidad = min_velocidad = false;
    dif_velocidad = 0.0;
    umbral_velocidad = 10.0;                                     // Valores por defecto: Umbral(10) Incremento(Umbral/100.0)
    incremento_velocidad = umbral_velocidad/100.0;
    alturaMin = alturaTope;
    alturaMax = 12.5;
    incremento_altura = 0.05;
    CalculoAngular();
}
