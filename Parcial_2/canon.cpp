#include "canon.h"

canon::canon(float xo_, float yo_, float angulo_, float velocidad_inicial_)
{
    xo = xo_;
    yo = yo_;
    angulo = angulo_;
    velocidad_inicial = velocidad_inicial_;
}

void canon::o_golpea_d(float x_defensivo, float y_defensivo, int cond){

    float t;

    bala_ofensiva = new bala(0, 0, 0, 0);

    for (velocidad_inicial=0;;velocidad_inicial+=1){
        for (angulo=0; angulo < 90; angulo++){
            bala_ofensiva->calcular_velocidades(velocidad_inicial, angulo);
            for(t=0;;t+=1){
                bala_ofensiva->calcular_posiciones(xo, yo, t);
                if (bala_ofensiva->posy < 0) break;
                if (sqrt(pow((x_defensivo - bala_ofensiva->posx), 2)+pow((y_defensivo - bala_ofensiva->posy), 2)) <= (0.05*x_defensivo)){
                    cond += 1;
                    cout << "Para que el canon O golpee el D necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << bala_ofensiva->posx << ", " << bala_ofensiva->posy << endl;
                    cout << "\n_________________________________________________________________________________________________\n\n\n";
                    break;
                }

            }
            if (cond == 3) break;

        }
        if (cond == 3) break;
    }

}

void canon::d_golpea_o(float x_ofensivo, float y_ofensivo, int cond)
{
    int t;

    bala_defensiva = new bala(0, 0, 0, 0);

    for (velocidad_inicial=0; ;velocidad_inicial+=1){
        for(angulo=0; angulo < 90; angulo++){
            bala_defensiva->calcular_velocidades(velocidad_inicial, (180 - angulo));
            for(t=0;;t+=1){
                bala_defensiva->calcular_posiciones(xo, yo, t);
                if (bala_defensiva->posy < 0) break;
                if (sqrt(pow((x_ofensivo - bala_defensiva->posx), 2) + pow((y_ofensivo - bala_defensiva->posy), 2)) <= (0.025*xo)){
                    cond += 1;
                    cout << "Para que el canon D golpee el O necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << bala_defensiva->posx << ", " << bala_defensiva->posy << endl;
                    cout << "\n_________________________________________________________________________________________________\n\n\n";

                    break;
                }
            }
            if (cond == 3) break;


        }
        if (cond == 3) break;
    }

}

void canon::d_defiende_o(float x_ofensivo, float y_ofensivo, float angulo_ofensivo, float vo_ofensivo)
{
    int t, cond = 0;

    bala_ofensiva = new bala(0, 0, 0, 0);
    bala_defensiva = new bala(0, 0, 0, 0);

    for (velocidad_inicial = 0; ; velocidad_inicial++){
        bala_ofensiva->calcular_velocidades(vo_ofensivo, angulo_ofensivo);
        for (angulo = 0; angulo < 90; angulo++){
            bala_defensiva->calcular_velocidades(velocidad_inicial, (180 - angulo));
            for (t = 0; ; t++){
                bala_defensiva->calcular_posiciones(xo, yo, t);
                bala_ofensiva->calcular_posiciones(x_ofensivo, y_ofensivo, (t+2));
                if (sqrt(pow((xo - bala_ofensiva->posx),2)+pow((yo - bala_ofensiva->posy),2)) <= (0.5*xo)) break;
                if (sqrt(pow((bala_ofensiva->posx - bala_defensiva->posx), 2) + pow((bala_ofensiva->posy - bala_defensiva->posy), 2)) <= (0.025*(xo))){
                    cond += 1;
                    cout << "Para que el canon D se defienda de O necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << bala_defensiva->posx << ", " << bala_defensiva->posy << endl;
                    cout << "pocision bala O: " << bala_ofensiva->posx << ", " << bala_ofensiva->posy << endl;
                    cout << "\n_________________________________________________________________________________________________\n\n\n";
                    break;
                }
            }
            if (cond == 3) break;
        }
        if (cond == 3) break;
    }


}

void canon::d_defiendo_o2(float x_ofensivo, float y_ofensivo, float angulo_ofensivo, float vo_ofensivo, int cond)
{
    int t, t2, cond2 = 0;

    bala_ofensiva = new bala(0, 0, 0, 0);
    bala_defensiva = new bala(0, 0, 0, 0);
    bala_ofensiva_aux = new bala(0, 0, 0, 0);

    for (velocidad_inicial = 0; ; velocidad_inicial++){
        bala_ofensiva->calcular_velocidades(vo_ofensivo, angulo_ofensivo);
        for (angulo = 0; angulo < 90; angulo++){
            bala_defensiva->calcular_velocidades(velocidad_inicial, (180 - angulo));
            for (t = 0; ; t++){
                bala_defensiva->calcular_posiciones(xo, yo, t);
                bala_ofensiva->calcular_posiciones(x_ofensivo, y_ofensivo, (t+2));
                for (t2 = t; ; t2++){
                    bala_ofensiva_aux->calcular_posiciones(xo, yo, t2);
                    if (sqrt(pow((x_ofensivo - bala_ofensiva_aux->posx),2)+pow((y_ofensivo - bala_ofensiva_aux->posy),2)) <= 0.025*xo){
                        cond2 = 1;
                        break;
                    }
                    if (bala_ofensiva_aux->posy < 0){
                        break;
                    }
                }

                if (cond2){
                    cond2 = 0;
                    break;
                }
                if (sqrt(pow((xo - bala_ofensiva->posx), 2)+pow((yo - bala_ofensiva->posy), 2))<=(0.5*xo)) break;
                if (sqrt(pow((bala_defensiva->posx - bala_ofensiva->posx), 2) + pow((bala_defensiva->posy - bala_ofensiva->posy), 2)) <= (0.025*(xo))){

                    if (sqrt(pow((xo - bala_ofensiva->posx), 2)+pow((yo - bala_ofensiva->posy), 2)) <= (0.05*xo)){
                        cout << "No es posible defenderse con el disparo: " << endl;
                        cout << "pocision bala D: " << bala_defensiva->posx << ", " << bala_defensiva->posy << endl;
                        break;
                    }
                    else{
                        cout << "Para que el canon D se defienda de O necesita una velocidad de:" << velocidad_inicial << " en un tiempo: " << t << " con un angulo de: " << angulo <<  endl;
                        cout << "Y la posicion donde impacta es de: " << bala_defensiva->posx << ", " << bala_defensiva->posy << endl;
                        cout << "pocision bala O: " << bala_ofensiva->posx << ", " << bala_ofensiva->posy << endl;
                        cout << "\n_________________________________________________________________________________________________\n\n\n";
                        cond += 1;
                    }
                    break;
                }
            }
            if (cond == 3) break;
        }
        if (cond == 3) break;
    }
}

void canon::o_defiende_d(float x_defensivo, float y_defensivo, float angulo_defensivo, float vo_defensivo)
{
    float t, cond = 0, auxvel, auxangulo;

    bala_ofensiva = new bala(0, 0, 0, 0);
    bala_defensiva = new bala(0, 0, 0, 0);
    bala_ofensiva_aux = new bala(0, 0, 0, 0);

    for (auxvel = 0; ; auxvel++){
        bala_ofensiva->calcular_velocidades(velocidad_inicial, angulo);
        bala_defensiva->calcular_velocidades(vo_defensivo, (180 - angulo_defensivo));
        for (auxangulo = 0; auxangulo < 90; auxangulo++){
            bala_ofensiva_aux->calcular_velocidades(auxvel, auxangulo);
            for (t = 0; ; t++){
                bala_ofensiva_aux->calcular_posiciones(xo, yo, (t));
                bala_ofensiva->calcular_posiciones(xo, yo, (t+3));
                bala_defensiva->calcular_posiciones(x_defensivo, y_defensivo, (t+1));

                if (sqrt(pow((bala_ofensiva->posx - bala_ofensiva_aux->posx), 2)+pow((bala_ofensiva->posy - bala_ofensiva_aux->posy), 2)) <= 0.005*x_defensivo) break;

                if (sqrt(pow((bala_ofensiva->posx - bala_defensiva->posx), 2)+pow((bala_ofensiva->posy - bala_defensiva->posy), 2)) < 0.025*x_defensivo) break;

                else if (sqrt(pow((bala_defensiva->posx - bala_ofensiva_aux->posx), 2)+pow((bala_defensiva->posy - bala_ofensiva_aux->posy), 2)) <= 0.005*x_defensivo){
                    cout << "Para que el canon O defienda su primer disparo del O necesita una velocidad de:" << auxvel << " en un tiempo: " << t << " con un angulo de: " << auxangulo <<  endl;
                    cout << "Y la posicion donde impacta es de: " << bala_ofensiva_aux->posx << ", " << bala_ofensiva_aux->posy << endl;
                    cout << "pocision bala D: " << bala_defensiva->posx << ", " << bala_defensiva->posy << endl;
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




