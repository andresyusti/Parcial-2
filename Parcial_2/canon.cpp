#include "canon.h"

canon::canon(float xo_, float yo_, float angulo_, float velocidad_inicial_)
{
    xo = xo_;
    yo = yo_;
    angulo = angulo_;
    velocidad_inicial = velocidad_inicial_;
}

void canon::imprimir_resultados()
{
    cout << xo << endl;
    cout << yo << endl;
    cout << angulo << endl;
    cout << velocidad_inicial << endl;
}

void canon::o_golpea_d(float x_defensivo, float y_defensivo){

    float copiax, copiay, vx, vy, raiz;
    int t, cond;
    cond=0;

    for (velocidad_inicial=0;;velocidad_inicial+=1){
        for (angulo=0; angulo < 90; angulo++){
            vx=velocidad_inicial*cos(angulo*3.14/180);
            vy=velocidad_inicial*sin(angulo*3.14/180);
            for(t=0;;t+=1){
                copiax=xo+vx*t;
                copiay=yo+vy*t-(0.5*9.81*t*t);
                raiz=pow((x_defensivo-copiax),2)+pow((y_defensivo-copiay),2);
                if (sqrt(raiz)<=(0.05*600)){
                    cond=1;
                    break;
                }
                if (copiay < 0) break;
            }
            if (cond == 1) break;

        }
        if (cond==1) break;
    }
    cout << "Para que el canon O golpee el D necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
    cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
}

void canon::d_golpea_o(float x_ofensivo, float y_ofensivo)
{
    float copiax, copiay, vx, vy, raiz;
    int t, cond;
    cond=0;

    for (velocidad_inicial=0;velocidad_inicial<=100;velocidad_inicial+=1){
        for(angulo=0; angulo < 90; angulo++){
            for(t=0;;t+=1){
                vx=velocidad_inicial*cos((180-angulo)*3.14/180);
                vy=velocidad_inicial*sin((180-angulo)*3.14/180);
                copiax=xo+vx*t;
                copiay=yo+vy*t-(0.5*9.81*t*t);
                raiz=pow((x_ofensivo-copiax),2)+pow((y_ofensivo-copiay),2);
                if (sqrt(raiz)<=(0.025*600)){
                    cond=1;
                    break;
                }
                if (copiay < 0) break;
            }
            if (cond==1) break;


        }
        if (cond==1) break;
    }
    cout << "Para que el canon O golpee el D necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
    cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
}

void canon::d_defiende_o(float x_ofensivo, float y_ofensivo, float angulo_ofensivo, float vo_ofensivo)
{
    float copiax, copiay, copiax2, copiay2, vx, vy, vx2, vy2, raiz;
    int t, cond;


    for (velocidad_inicial = 0; ; velocidad_inicial++){
        vx2 = vo_ofensivo*cos(angulo_ofensivo*3.14/180);
        vy2 = vo_ofensivo*sin(angulo_ofensivo*3.14/180);
        for (angulo = 0; angulo < 90; angulo++){
            vx = velocidad_inicial*cos((180-angulo)*3.14/180);
            vy = velocidad_inicial*sin((180-angulo)*3.14/180);
            for (t = 0; ; t++){
                copiax = xo+vx*(t);
                copiay = yo+vy*(t)-(0.5*9.81*(t)*(t));
                copiax2 = x_ofensivo+vx2*(t+2);
                copiay2 = y_ofensivo+vy2*(t+2)-(0.5*9.81*(t+2)*(t+2));
                raiz=pow((copiax-copiax2),2)+pow((copiay-copiay2),2);
                if (sqrt(raiz)<=(0.025*(copiax))){
                    cond=1;
                    break;
                }
                //if (copiax > 583) break;
                if (sqrt(pow((xo-copiax2),2)+pow((yo-copiay2),2))<=(0.5*600)) break;
            }
            if (cond == 1) break;
        }
        if (cond == 1) break;
    }
    cout << "Para que el canon D se defienda de O necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
    cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
    cout << "pocision bala O: " << copiax2 << ", " << copiay2 << endl;

}



