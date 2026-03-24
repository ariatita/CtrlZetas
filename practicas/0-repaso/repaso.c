#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "repaso.h"

enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp) {
    int dx = xp - xc;
    int dy = yp - yc;
    int r2 = rc * rc;
    int distancia2 = dx * dx + dy * dy;
    enum Referencia resultado;

    if(distancia2 == r2) {
        resultado = EN_CIRCUNFERENCIA;
    } else if(distancia2 > r2) {
        resultado = EXTERNO;
    } else if(distancia2 < r2) {
        resultado = INTERNO;
    }
    return resultado;
}

bool digitoEnNumero(long n, short d) {
    int n1;
    if (n == 0) {
        if (d == 0) {
            return true;
        }
    return false; 
    }
    if (n < 0) {
            n = n * -1; // o también n = -n;
        }
    while(n != 0){
        n1 = n % 10;
        if(n1 == d){
            return true;
        }
        n = n / 10;
    }
    return false;
}

//VERSION DE AGUS (UN SOLO RETURN):
// bool digitoEnNumero(long n, short d) {
//     int n1;
//     bool resultado = false;
//     if((n == 0) && (d == 0)) resultado = true;
//     else if((n != 0)) {
//         if(n < 0) n = n * -1;
//         while(n != 0 && !resultado) {
//             n1 = n % 10;
//             if(n1 == d) resultado = true;
//             n = n / 10;
//         }
//     }
//     return resultado;
// }

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p) {
    int dy = p.y - centroC.y;
    int dx = p.x - centroC.x;
    int r2 = rc * rc;
    int distancia2 = dx * dx + dy * dy;
    enum Referencia resultado;

    if(distancia2 == r2) {
        resultado = EN_CIRCUNFERENCIA;
    } else if(distancia2 > r2) {
        resultado = EXTERNO;
    } else if(distancia2 < r2) {
        resultado = INTERNO;
    }
    return resultado;
}

// Función para ordenar jugadores por cantidad de partidos jugados
struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[CANT_JUGADORES]) {
    int max;
    struct Jugador aux;
    for(int i = 0; i < CANT_JUGADORES; i++) {
        max = i;
        for(int j = i + 1; j < CANT_JUGADORES; j++) {
            if(equipo[max].partidosJugados < equipo[j].partidosJugados) max = j;
        }
        aux = equipo[i];
        equipo[i] = equipo[max];
        equipo[max] = aux;
    }
    return equipo;
}

// Función para ordenar jugadores por edad
struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[CANT_JUGADORES]) {
    int min;
    struct Jugador aux;
    for(int i = 0; i < CANT_JUGADORES; i++) {
        min = i;
        for(int j = i + 1; j < CANT_JUGADORES; j++) {
            if(equipo[min].edad > equipo[j].edad) min = j;
        }
        aux = equipo[i];
        equipo[i] = equipo[min];
        equipo[min] = aux;
    }
    return equipo;
}

// Función para calcular el promedio de partidos jugados dada una edad
float promedioDePartidosJugados(struct Jugador equipo[CANT_JUGADORES], int edad) {
    float total = 0;
    int jugadores = 0;
    float promedio = 0;
    for(int i = 0; i < CANT_JUGADORES; i++) {
        if(equipo[i].edad == edad) {
            jugadores++;
            total += equipo[i].partidosJugados;
        }
    }
    promedio = total / jugadores;
    return promedio;
}

Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
    Vivienda mashabitantes;
    int maxHabitantes = 0;
    int posPiso = 0;
    int posDepto= 0;
    for(int i = 0; i < CANT_PISOS; i++) {
        for(int j = 0; j < CANT_DEPARTAMENTOS; j++) {
            if(edificio[i][j] > maxHabitantes) {
                maxHabitantes = edificio[i][j];
                posPiso = i;
                posDepto = j;
            }
        }
    }
    char departamento = 'A' + posDepto;
    mashabitantes.piso = posPiso + 1;
    mashabitantes.depto = departamento;
    return mashabitantes;
}

// ----->Ejemplo Juan Cruz.<-----
// Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){
//     Vivienda masHabitantes;
//     int maxHabitantes = 0;
//     int posicionPiso = 0;
//     int posicionDepto = 0;
//     for(int i = 0; i < CANT_PISOS; i++){
//         for(int j = 0; j < CANT_DEPARTAMENTOS; j++){
//             if(edificio[i][j] > maxHabitantes){
//                 maxHabitantes = edificio[i][j];
//                 posicionPiso = i;
//                 posicionDepto = j;
//             }
//         }
//     }
//     char departamento = 'A' + posicionDepto;
//     masHabitantes.piso = posicionPiso + 1;
//     masHabitantes.depto = departamento;
//     return masHabitantes;
// }

// Función que devuelve el piso con más habitantes
int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
    int pisoConMasPersonas = 0;
    int max = 0;
    int totalxpiso = 0;
    for(int i = 0; i < CANT_PISOS; i++) {
        for(int j = 0; j < CANT_DEPARTAMENTOS; j++) {
            totalxpiso += edificio[i][j];
        }
        if(totalxpiso > max) {
            max = totalxpiso;
            pisoConMasPersonas = i + 1;
        }
        totalxpiso = 0;
    }
    return pisoConMasPersonas;
}

// Función que devuelve el número de departamentos vacíos
int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
    int deptosVacios = 0;
    for(int i = 0; i < CANT_PISOS; i++) {
        for(int j = 0; j < CANT_DEPARTAMENTOS; j++) {
            if(edificio[i][j] == 0) deptosVacios++;
        }
    }
    return deptosVacios;
}

// Función que devuelve el promedio de habitantes por departamento
float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
    float totalHabitantes = 0;
    float totalViviendas = CANT_PISOS * CANT_DEPARTAMENTOS;
    for(int i = 0; i < CANT_PISOS; i++) {
        for(int j = 0; j < CANT_DEPARTAMENTOS; j++) {
            totalHabitantes += edificio[i][j];
        }
    }
    return totalHabitantes / totalViviendas;
}

void cantidadDeViviendasVaciasPorPiso(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS], int vaciasPorPiso[CANT_PISOS]) {
    int viviendasVacias = 0;
    for(int i = 0; i < CANT_PISOS; i++) {
        for(int j = 0; j < CANT_DEPARTAMENTOS; j++) {
            if(edificio[i][j] == 0) viviendasVacias++;
        }
        vaciasPorPiso[i] = viviendasVacias;
        viviendasVacias = 0;
    }
}

void viviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS], Vivienda viviendasVaciasTotales[CANT_PISOS * CANT_DEPARTAMENTOS]) {
    int pos = 0;
    for(int i = 0; i < CANT_PISOS; i++) {
        for(int j = 0; j < CANT_DEPARTAMENTOS; j++) {
            if(edificio[i][j] == 0) {
                viviendasVaciasTotales[pos].piso = i + 1;
                viviendasVaciasTotales[pos].depto = 'A' + j;
                pos++;
            }
        }
    }
}

void procesarArchivo(const char *nombreArchivo) {
    FILE *file = fopen(nombreArchivo, "r");
    if(file == NULL) {
        printf("Error al abrir archivo\n");
        return;
    }
    int cliente, anio, mes;
    float minutos;
    if(fscanf(file, "%d %d %d %f", &cliente, &anio, &mes, &minutos) != 4) {
        fclose(file);
        return;
    }
    while(!feof(file)) {
        int cliente_actual = cliente;
        printf("\nCliente %d\n", cliente_actual);
        while(!feof(file) && cliente == cliente_actual) {
            int anio_actual = anio;
            int total_anio = 0;
            while(!feof(file) && cliente == cliente_actual && anio == anio_actual) {
                total_anio += minutos;
                fscanf(file, "%d %d %d %f", &cliente, &anio, &mes, &minutos);
            }
            printf("  Año %d: %d minutos\n", anio_actual, total_anio);
        }
    }
    fclose(file);
}
