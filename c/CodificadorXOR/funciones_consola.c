#include "funciones_consola.h"
#include <stdio.h>

void limpiar_pantalla(){
	printf("\033[2J\033[H");
  fflush(stdout);
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void esperar_enter(){
    printf("Presiona Enter para continuar...");
    // limpiar_buffer();
    getchar();
}

int entrada_invalida(int scanf_res){
  if (scanf_res != 1) {
      limpiar_pantalla();
      printf("Entrada invalida. Intente de nuevo.\n");
      return 1;
  }
  return 0;
}