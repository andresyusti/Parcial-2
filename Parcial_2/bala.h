#ifndef BALA_H
#define BALA_H
#include<math.h>

class bala
{
public:
    float posx;
    float posy;
    float velx;
    float vely;
    bala(float x, float y, float vx, float vy);
    void calcular_velocidades(float velo, float angulo);
    void calcular_posiciones(float poscanonx, float poscanony, float t);
};

#endif // BALA_H
