#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "nodos.h"

// Funciones para manejar nodos
// Crear un nuevo nodo
Nodo* crear_nodo(int valor) {
  Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
  if (nuevo_nodo == NULL) {
    printf("Error al asignar memoria para el nuevo nodo.\n");
    exit(EXIT_FAILURE);
  }
  nuevo_nodo -> dato = valor;
  nuevo_nodo -> siguiente = NULL;
  return nuevo_nodo;
}
