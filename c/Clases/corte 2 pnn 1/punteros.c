#include <stdio.h>

int main() {
  int *puntero_x;

  int x = 5;

  puntero_x = &x;

  printf("Valor de x: %d\n", x);
  printf("Direccion de x: %p\n", &x);
  printf("Valor del puntero puntero_x: %p\n", puntero_x);
  printf("Valor apuntado por puntero_x: %d\n", *puntero_x);

  *puntero_x = 25;

  printf("\n");

  printf("Nuevo valor de x despues de modificar a traves del puntero: %d\n", x);
  printf("Valor del puntero puntero_x: %p\n", puntero_x);

}