#include <stdio.h>
#include <string.h>

int main() {
  char fuente[] = "Programacion";
  char destino1[15];
  char destino2[5];

  strcpy(destino1, fuente);
  printf("Destino1: %s\n", destino1);

  strncpy(destino2, fuente, sizeof(destino2) - 1);
  destino2[sizeof(destino2) - 1] = '\0';
  printf("Destino2: %s\n\n", destino2);

  // Concatenar cadenas
  char s1[30] = "Hola, ";
  char s2[] = "Mundo";
  char s3[] = " C!";

  strcat(s1, s2);
  printf("Concatenacion 1: %s\n", s1);
  strncat(s1, s3, 3);
  printf("Concatenacion 2: %s\n", s1);
  return 0;
}