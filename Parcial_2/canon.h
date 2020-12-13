#ifndef CANON_H
#define CANON_H
#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;


class canon
{
public:
    float xo;
    float yo;
    float angulo;
    float velocidad_inicial;

    canon *canoon;
    canon(float xo_, float yo_, float angulo_, float velocidad_inicial_);
    void o_golpea_d(float x_defensivo, float y_defensivo, int cond);
    void d_golpea_o(float x_ofensivo, float y_ofensivo, int cond);
    void d_defiende_o(float x_ofensivo, float y_ofensivo,float angulo_ofensivo, float vo_ofensivo);
    void d_defiendo_o2(float x_ofensivo, float y_ofensivo, float angulo_ofensivo, float vo_ofensivo, int cond);
    void o_defiende_d(float x_defensivo, float y_defensivo, float angulo_defensivo, float vo_defensivo, float bala_ox, float bala_oy);
    void imprimir_resultados();
};

#endif // CANON_H
