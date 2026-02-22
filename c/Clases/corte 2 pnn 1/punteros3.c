#include <stdio.h>

int main() {
  char *dias_semana[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

  int num_dia = sizeof(dias_semana) / sizeof(dias_semana[0]);

  printf("Dias de la semana:\n");
  for (int i = 0; i < num_dia; i++) {
    printf("%d: %s\n", i + 1, dias_semana[i]);
  }

  printf("Notacion de arreglo: %s\n", dias_semana[2]);
  printf("Notacion de puntero: %c\n", *(*(dias_semana + 2) + 2));

  return 0;
}