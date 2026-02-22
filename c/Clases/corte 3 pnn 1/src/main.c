#include <stdio.h>
#include "listas_circulares.h"

int main() {
  CLista lista = Crear_CLista();
  anadir_nodo(&lista, 10);
  anadir_nodo(&lista, 20);
  anadir_nodo(&lista, 30);
  printf("Lista circular: ");
  imprimir_lista(lista);
  return 0;
}