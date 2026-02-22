#include <stdio.h>

int main() {
  int numero = 10;
  int *puntero_numero = &numero;
  int **puntero_doble = &puntero_numero;

  printf("Valor de numero: %d\n", numero);
  printf("Valor a traves de puntero_numero: %d\n", *puntero_numero);
  printf("Valor a traves de puntero_doble: %d\n", **puntero_doble);
  return 0;
}