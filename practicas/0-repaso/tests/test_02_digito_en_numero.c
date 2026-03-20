#include <stdio.h>
#include <assert.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Test de Ejercicio 2");
    assert(digitoEnNumero(987, 6) == false);
    assert(digitoEnNumero(987, 7)== true);
    printf("El ejercicio 2 pasó los tests✅\n");
    return 0;
}
