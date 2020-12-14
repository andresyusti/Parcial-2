#include "bala.h"

bala::bala(float x, float y, float vx, float vy)
{
    posx = x;
    posy = y;
    velx = vx;
    vely = vy;
}

void bala::calcular_velocidades(float velo, float angulo)
{
    velx = velo*cos(angulo*3.14/180);
    vely = velo*sin(angulo*3.14/180);
}

void bala::calcular_posiciones(float poscanonx, float poscanony, float t)
{
    posx = poscanonx+velx*t;
    posy = poscanony+vely*t-(0.5*9.81*t*t);
}


