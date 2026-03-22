#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"

int testPersonasVaciasPorPiso(int vaciasPorPiso[CANT_PISOS], int viviendasQueEstanVaciasPorPiso[]);
void inicializar(Vivienda aInicializar[]);
int testViviendasVacias(Vivienda viviendasVacias[CANT_PISOS * CANT_DEPARTAMENTOS], Vivienda viviendasQueEstanVacias[]);

int main() {
    imprimir_titulo("Tests de Ejercicio 5");
    int edificio[CANT_PISOS][CANT_DEPARTAMENTOS] = {
            {3, 5, 2, 1, 0},
            {2, 4, 3, 0, 4},
            {1, 0, 1, 2, 1},
            {0, 1, 0, 0, 0},
            {1, 3, 2, 1, 1},
            {2, 2, 0, 1, 3},
            {1, 0, 0, 2, 1},
            {0, 0, 1, 1, 1}};

    //Vivienda con mas habitantes:
    Vivienda masHabitantes;
    masHabitantes.piso = 1;
    masHabitantes.depto = 'B';

    //Viviendas vacias por piso:
    int vaciasPorPiso[CANT_PISOS];
    int viviendasQueEstanVaciasPorPiso[] = {1, 1, 1, 4, 0, 1, 2, 2};

    //Viviendas que estan vacias:
    Vivienda viviendasVaciasTotales[CANT_PISOS * CANT_DEPARTAMENTOS];
    inicializar(viviendasVaciasTotales);
    Vivienda viviendasQueEstanVacias[] = {
        {1, 'E'},
        {2, 'D'},
        {3, 'B'},
        {4, 'A'},
        {4, 'C'},
        {4, 'D'},
        {4, 'E'},
        {6, 'C'},
        {7, 'B'},
        {7, 'C'},
        {8, 'A'},
        {8, 'B'},
    };

    //TESTS:
    Vivienda resultado = viviendaConMasHabitantes(edificio);
    assert(resultado.depto == masHabitantes.depto);
    assert(resultado.piso == masHabitantes.piso);

    //Piso con mas habitantes:
    assert(pisoConMasHabitantes(edificio) == 2);

    //Numero de departamentos vacios:
    assert(cantidadDeViviendasVacias(edificio) == 12);

    //Promedio de personas por edificio??
    assert((int)(promedioHabitantesPorVivienda(edificio) * 1000) == 1325);

    //Personas vacias por piso:
    cantidadDeViviendasVaciasPorPiso(edificio, vaciasPorPiso);
    assert(testPersonasVaciasPorPiso(vaciasPorPiso, viviendasQueEstanVaciasPorPiso));

    //Viviendas Vacias:
    viviendasVacias(edificio, viviendasVaciasTotales);
    assert(testViviendasVacias(viviendasVaciasTotales, viviendasQueEstanVacias));
    return 0;
}


int testPersonasVaciasPorPiso(int vaciasPorPiso[CANT_PISOS], int viviendasQueEstanVaciasPorPiso[]) {
    int resultado = 1;
    int i = 0;
    while(i < CANT_PISOS && resultado == 1) {
        if(vaciasPorPiso[i] != viviendasQueEstanVaciasPorPiso[i]) resultado = 0;
        i++;
    }
    return resultado;
}

int testViviendasVacias(Vivienda viviendasVaciasTotales[CANT_PISOS * CANT_DEPARTAMENTOS], Vivienda viviendasQueEstanVacias[]) {
    int i = 0;
    int resultado = 1;
    while(viviendasVaciasTotales[i].piso != 0 && resultado == 1) {
        if(viviendasVaciasTotales[i].piso != viviendasQueEstanVacias[i].piso || viviendasVaciasTotales[i].depto != viviendasQueEstanVacias[i].depto) resultado = 0;
        i++;
    }
    return resultado;
}

void inicializar(Vivienda aInicializar[]) {
    int totalViviendas = CANT_PISOS * CANT_DEPARTAMENTOS;
    for (int i = 0; i < totalViviendas; i++) {
        aInicializar[i].piso = 0;
        aInicializar[i].depto = '0';
    }
}