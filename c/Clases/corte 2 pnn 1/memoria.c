#include <stdio.h>
#include <stdlib.h>

void liberar_memoria(int *p);

int main(){

  int *p;
  int n = 5;

  p = (int *) malloc(n * sizeof(int));

  if (p == NULL) {
      // printf(stderr, "Error al asignar memoria\n");
      return EXIT_FAILURE;
  }

  printf("Dirección de memoria asignada: %p\n", (void*)p);

  for (int i = 0; i < n; i++){
    p[i] = i + 1;
    printf("p[%d] = %d ", i, p[i]);
    printf("Dirección de p[%d]: %p\n", i, (void*)&p[i]);
  }
  
  liberar_memoria(p);

}

void liberar_memoria(int *p){
  free(p);
  p = NULL;
  printf("Memoria liberada\n");
}