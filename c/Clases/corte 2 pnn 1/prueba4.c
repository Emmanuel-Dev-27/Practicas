#include <stdio.h>

int main() {
  char saludo[] = "Hola, Mundo!";
  char nombre[9] = "Emmanuel";

  char nat[7];
  nat[0] = 'M';
  nat[1] = 'o';
  nat[2] = 'n';
  nat[3] = 'i';
  nat[4] = 'c';
  nat[5] = 'a';
  nat[6] = '\0';

  /* Mostrar el saludo y el nombre (usar %s con una cadena) */
  printf("%s\n", saludo);
  printf("Nombre: %s\n", nombre);
  printf("Ella: %s\n", nat);
  return 0;
}
