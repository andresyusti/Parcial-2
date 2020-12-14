#include <canon.h>

int main()
{
    int condicion = 0;
    float distancia, altura_canon_ofensivo, altura_canon_defensivo;
    canon *canon_ofensivo;
    canon *canon_defensivo;

    cout << "Ingresar los valores:\n\ndistancia entre los canones: ";
    cin >> distancia;
    cout << "Altura del canon ofensivo: ";
    cin >> altura_canon_ofensivo;
    cout << "Altura del canon defensivo: ";
    cin >> altura_canon_defensivo;

    canon_ofensivo = new canon(0, altura_canon_ofensivo, 0, 0);
    canon_defensivo = new canon(distancia, altura_canon_defensivo, 0, 0);

    while (condicion != 6){
        cout << "\nIngresar que desea hacer:\n\nofensivo golpea defensivo 1.\ndefensivo golpea ofensivo 2.\ndefensivo se defiende de ofensivo 3.\ndefensivo se defiende de ofensivo sin danarlo 4.\nofensivo protege su primer disparo 5.\nsalir 6." << endl;
        cin >> condicion;

        if (condicion == 1) canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 0);

        if (condicion == 2) canon_defensivo->d_golpea_o(canon_ofensivo->xo, canon_ofensivo->yo, 0);

        if (condicion == 3){
            cout << "Datos del canon O golpeando al D.\n";
            cout << "_________________________________________________________________________________________________\n";
            canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 2);
            cout << "Datos del canon D protegiendose de O.\n";
            cout << "_________________________________________________________________________________________________\n";
            canon_defensivo->d_defiende_o(canon_ofensivo->xo, canon_ofensivo->yo, canon_ofensivo->angulo, canon_ofensivo->velocidad_inicial);
        }

        if (condicion == 4){
            cout << "Datos del canon O golpeando al D.\n";
            cout << "_________________________________________________________________________________________________\n";
            canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 2);
            cout << "Datos del canon D protegiendose de O.\n";
            cout << "_________________________________________________________________________________________________\n";
            canon_defensivo->d_defiendo_o2(canon_ofensivo->xo, canon_ofensivo->yo, canon_ofensivo->angulo, canon_ofensivo->velocidad_inicial, 0);
        }

        if (condicion == 5){
            cout << "Datos del canon O golpeando al D.\n";
            cout << "_________________________________________________________________________________________________\n";
            canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo, 2);
            cout << "Datos del canon D protegiendose de O.\n";
            cout << "_________________________________________________________________________________________________\n";
            canon_defensivo->d_defiendo_o2(canon_ofensivo->xo, canon_ofensivo->yo, canon_ofensivo->angulo, canon_ofensivo->velocidad_inicial, 2);
            cout << "Datos del canon O protegiendo su bala de D.\n";
            cout << "_________________________________________________________________________________________________\n";
            canon_ofensivo->o_defiende_d(canon_defensivo->xo, canon_defensivo->yo, canon_defensivo->angulo, canon_defensivo->velocidad_inicial);
        }


    }

    return 0;
}

