#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "nodos.h"
#include "pilas.h"

// Inicializar la pila
void inicializar_pila(Pila* pila) {
  pila -> tope = NULL;
}

// Verificar si la pila esta vacia
int vacia(Pila* pila) {
  return pila -> tope == NULL;
}

// Añadir un elemento a la pila
void añadir(Pila* pila, int valor) {
  Nodo* nuevo_nodo = crear_nodo(valor);

  if (nuevo_nodo == NULL) {
    printf("Error al asignar memoria para el nuevo nodo de la pila.\n");
    exit(EXIT_FAILURE);
  }

  nuevo_nodo -> siguiente = pila -> tope;
  pila -> tope = nuevo_nodo;
  printf("Se añadio %d a la pila.\n", valor);
}

// eliminar un elemento de la pila
int eliminar_tope(Pila* pila) {
  if (vacia(pila)){
    printf("La pila esta vacia.\n");
    return INT_MIN; //libreria <limits.h>
  }
  Nodo* temp = pila -> tope;
  int valor = temp -> dato;
  pila -> tope = pila -> tope -> siguiente;
  free (temp);
  temp = NULL;
  return valor;
}
