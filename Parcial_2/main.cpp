#include <canon.h>

void d_defiendo_o2(float xo, float ho, float hd, float ao, float d);

int main()
{
    int condicion;
    canon *canon_ofensivo;
    canon *canon_defensivo;

    canon_defensivo = new canon(600, 100, 0, 0);
    canon_ofensivo = new canon(0, 100, 0, 0);
    canon_defensivo->imprimir_resultados();
    cout << "__________________" << endl;
    canon_ofensivo->imprimir_resultados();

    cout << "\nIngresar que desea hacer:\n\nofensivo golpea defensivo 1.\ndefensivo golpea ofensivo 2.\ndefensivo se defiendo de ofensivo 3." << endl;
    cin >> condicion;

    if (condicion == 1) canon_ofensivo->o_golpea_d(canon_defensivo->xo, canon_defensivo->yo);

    if (condicion == 2) canon_defensivo->d_golpea_o(canon_ofensivo->xo, canon_ofensivo->yo);

    if (condicion == 3){
        canon_ofensivo->angulo = 39;
        canon_ofensivo->velocidad_inicial = 75;
        canon_defensivo->d_defiende_o(canon_ofensivo->xo, canon_ofensivo->yo, canon_ofensivo->angulo, canon_ofensivo->velocidad_inicial);
    }

    return 0;
}

