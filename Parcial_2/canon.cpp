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

void canon::o_golpea_d(float x_defensivo, float y_defensivo, int cond){

    float copiax, copiay, vx, vy, raiz;
    int t;

    for (velocidad_inicial=0;;velocidad_inicial+=1){
        for (angulo=0; angulo < 90; angulo++){
            vx=velocidad_inicial*cos(angulo*3.14/180);
            vy=velocidad_inicial*sin(angulo*3.14/180);
            for(t=0;;t+=1){
                copiax=xo+vx*t;
                copiay=yo+vy*t-(0.5*9.81*t*t);
                raiz=pow((x_defensivo-copiax),2)+pow((y_defensivo-copiay),2);
                if (sqrt(raiz)<=(0.05*x_defensivo)){
                    cond += 1;
                    cout << "Para que el canon O golpee el D necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
                    cout << "\n_________________________________________________________________________________________________\n\n\n";
                    break;
                }
                if (copiay < 0) break;
            }
            if (cond == 3) break;

        }
        if (cond == 3) break;
    }

}

void canon::d_golpea_o(float x_ofensivo, float y_ofensivo, int cond)
{
    float copiax, copiay, vx, vy, raiz;
    int t;



    for (velocidad_inicial=0; ;velocidad_inicial+=1){
        for(angulo=0; angulo < 90; angulo++){
            for(t=0;;t+=1){
                vx=velocidad_inicial*cos((180-angulo)*3.14/180);
                vy=velocidad_inicial*sin((180-angulo)*3.14/180);
                copiax=xo+vx*t;
                copiay=yo+vy*t-(0.5*9.81*t*t);
                raiz=pow((x_ofensivo-copiax),2)+pow((y_ofensivo-copiay),2);
                if (sqrt(raiz)<=(0.025*xo)){
                    cond += 1;
                    cout << "Para que el canon O golpee el D necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
                    cout << "\n_________________________________________________________________________________________________\n\n\n";

                    break;
                }
                if (copiay < 0) break;
            }
            if (cond == 3) break;


        }
        if (cond == 3) break;
    }

}

void canon::d_defiende_o(float x_ofensivo, float y_ofensivo, float angulo_ofensivo, float vo_ofensivo)
{
    float copiax, copiay, copiax2, copiay2, vx, vy, vx2, vy2, raiz;
    int t, cond = 0;


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
                    cond += 1;
                    cout << "Para que el canon D se defienda de O necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
                    cout << "pocision bala O: " << copiax2 << ", " << copiay2 << endl;
                    cout << "\n_________________________________________________________________________________________________\n\n\n";
                    break;
                }
                if (sqrt(pow((xo-copiax2),2)+pow((yo-copiay2),2))<=(0.5*xo)) break;
            }
            if (cond == 3) break;
        }
        if (cond == 3) break;
    }


}

void canon::d_defiendo_o2(float x_ofensivo, float y_ofensivo, float angulo_ofensivo, float vo_ofensivo, int cond)
{
    float copiax, copiay, aucopiax, aucopiay, copiax2, copiay2, vx, vy, vx2, vy2, raiz;
    int t, t2, cond2 = 0;


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
                for (t2 = t; ; t2++){
                    aucopiax = xo+vx*(t2);
                    aucopiay = yo+vy*t2-(0.5*9.81*(t2)*(t2));
                    if (sqrt(pow((x_ofensivo - aucopiax),2)+pow((y_ofensivo - aucopiay),2)) < 0.025*xo){
                        cond2 = 1;
                        break;
                    }
                    if (aucopiay < 0){
                        break;
                    }
                }

                if (cond2){
                    cond2 = 0;
                    break;
                }
                if (sqrt(raiz)<=(0.025*(xo - copiax2))){

                    if (sqrt(pow((xo-copiax2),2)+pow((yo-copiay2),2))<=(0.05*xo)){
                        cout << sqrt(pow((xo-copiax2),2)+pow((yo-copiay2),2)) << endl;
                        cout << "No es posible defenderse con el disparo: " << endl;
                        cout << "pocision bala D: " << copiax << ", " << copiay << endl;
                    }
                    else{
                        cout << "Para que el canon D se defienda de O necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                        cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
                        cout << "pocision bala O: " << copiax2 << ", " << copiay2 << endl;
                        cout << "\n_________________________________________________________________________________________________\n\n\n";
                        cond += 1;
                    }
                    break;
                }
                if (sqrt(pow((xo-copiax2),2)+pow((yo-copiay2),2))<=(0.5*xo)) break;
            }
            if (cond == 3) break;
        }
        if (cond == 3) break;
    }
}

void canon::o_defiende_d(float x_defensivo, float y_defensivo, float angulo_defensivo, float vo_defensivo, float bala_ox, float bala_oy)
{
    float copiax, copiay, copiax2, copiay2, copiax3, copiay3, vx, vy, vx2, vy2, vx3, vy3, auxvo, auxangulo, t, cond = 0;
    for (auxvo = 0; ; auxvo++){
        vx2 = velocidad_inicial*cos(angulo*3.14/180);
        vy2 = velocidad_inicial*sin(angulo*3.14/180);
        vx3 = vo_defensivo*cos((180-angulo_defensivo)*3.14/180);
        vy3 = vo_defensivo*sin((180-angulo_defensivo)*3.14/180);
        for (auxangulo = 0; auxangulo < 90; auxangulo++){
            vx = auxvo*cos(auxangulo*3.14/180);
            vy = auxvo*sin(auxangulo*3.14/180);
            for (t = 0; ; t++){                                               //Segundo disparo ofensivo
                copiax = xo+vx*t;
                copiay = yo+vy*(t)-(0.5*9.81*(t)*(t));
                copiax2 = xo+vx2*(t+3);                                       //Primer disparo ofensivo
                copiay2 = yo+vy2*(t+3)-(0.5*9.81*(t+3)*(t+3));
                copiax3 = x_defensivo+vx3*(t+1);                              //Disparo defensivo
                copiay3 = y_defensivo+vy3*(t+1)-(0.5*9.81*(t+1)*(t+1));

                if (sqrt(pow((copiax2 - copiax3),2)+pow((copiay2 - copiay3),2)) < 0.025*x_defensivo) break;

                else if (sqrt(pow((copiax3 - copiax),2)+pow((copiay3 - copiay),2)) <= 0.005*x_defensivo){
                    cout << "Para que el canon D se defienda de O necesita una velocidad de:" << auxvo << " en un tiempo: " << t << " con un angulo de: " << auxangulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << copiax << ", " << copiay << endl;
                    cout << "pocision bala D: " << copiax3 << ", " << copiay3 << endl;
                    cout << "\n_________________________________________________________________________________________________\n\n\n";
                    cond += 1;
                    break;
                }

            }
            if (cond == 3) break;
        }
        if (cond == 3) break;
    }
}



