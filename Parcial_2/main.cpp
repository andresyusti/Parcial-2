#include <canon.h>

int main()
{
    int condicion = 0;
    float posx, posy;
    canon *canon_ofensivo;
    canon *canon_defensivo;

    canon_defensivo = new canon(600, 100, 0, 0);
    canon_ofensivo = new canon(0, 100, 0, 0);
    canon_defensivo->imprimir_resultados();
    cout << "__________________" << endl;
    canon_ofensivo->imprimir_resultados();

    while (condicion != 6){
        cout << "\nIngresar que desea hacer:\n\nofensivo golpea defensivo 1.\ndefensivo golpea ofensivo 2.\ndefensivo se defiende de ofensivo 3.\ndefensivo se defiende de ofensivo sin danarlo 4.\nofensivo proteje su primer disparo 5.\nsalir 6." << endl;
        cin >> condicion;

        if (condicion == 1) canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 0);

        if (condicion == 2) canon_defensivo->d_golpea_o(canon_ofensivo->xo, canon_ofensivo->yo, 0);

        if (condicion == 3){
            canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 2);
            canon_defensivo->d_defiende_o(canon_ofensivo->xo, canon_ofensivo->yo, canon_ofensivo->angulo, canon_ofensivo->velocidad_inicial);
        }

        if (condicion == 4){
            canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 2);
            canon_defensivo->d_defiendo_o2(canon_ofensivo->xo, canon_ofensivo->yo, canon_ofensivo->angulo, canon_ofensivo->velocidad_inicial, 0);
        }

        if (condicion == 5){
            canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 2);
            canon_defensivo->d_defiendo_o2(canon_ofensivo->xo, canon_ofensivo->yo, canon_ofensivo->angulo, canon_ofensivo->velocidad_inicial, 2);
            canon_ofensivo->o_defiende_d(canon_defensivo->xo, canon_defensivo->yo, canon_defensivo->angulo, canon_defensivo->velocidad_inicial, posx, posy);
        }

    }

    return 0;
}

