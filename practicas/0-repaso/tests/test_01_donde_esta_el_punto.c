#include <stdio.h>
#include <assert.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Test de Ejercicio 1");
    assert(dondeEstaElPunto(0, 0, 2, 1, 1 ) == INTERNO);
    assert(dondeEstaElPunto(0, 0, 1, 1, 1 ) == EXTERNO);
    assert(dondeEstaElPunto(0, 0, 1, 1, 0 ) == EN_CIRCUNFERENCIA);
    printf("El ejercicio 1 pasó los tests✅\n");
    return 0;
}
