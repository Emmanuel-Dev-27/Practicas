#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "nodos.h"

// Insertar un nodo al inicio de la lista
void insertar_inicio(Nodo** cabeza, int valor) {
  Nodo* nuevo_nodo = crear_nodo(valor);
  nuevo_nodo -> siguiente = *cabeza;
  *cabeza = nuevo_nodo;
}

// Insertar un nodo al final de la lista
void insertar_final(Nodo** cabeza, int valor){
  Nodo* nuevo_nodo = crear_nodo(valor);

  if (*cabeza == NULL){
    *cabeza = nuevo_nodo;
  }

  Nodo* actual = *cabeza;
  while (actual -> siguiente != NULL){
    actual = actual -> siguiente;
  }
  actual -> siguiente = nuevo_nodo;
}

// Insertar un nodo despues de un nodo dado
void insertar_despues(Nodo* nodo_anterior, int valor){
  if (nodo_anterior == NULL){
    printf("El nodo anterior no puede ser NULL.\n");
    return;
  }
  Nodo* nuevo_nodo = crear_nodo(valor);
  nuevo_nodo -> siguiente = nodo_anterior -> siguiente;
  nodo_anterior -> siguiente = nuevo_nodo;
}

// Eliminar un nodo por valor
void eliminar_nodo(Nodo** cabeza, int valor){
  Nodo *temporal = *cabeza, *previo = NULL;

  // Si el nodo a eliminar es la cabeza
  if (temporal != NULL && temporal -> dato == valor){
    *cabeza = temporal -> siguiente;
    free(temporal);
    return;
  }

  // Buscar el nodo a eliminar
  while (temporal != NULL && temporal -> dato != valor){
    previo = temporal;
    temporal = temporal -> siguiente;

  }

  // Si el valor no se encuentra en la lista
  if (temporal == NULL) {
    printf("El valor %d no se encontro en la lista.\n", valor);
    return;
  }
  previo -> siguiente = temporal -> siguiente;
  free(temporal);
}

// Imprimir la lista
void imprimir_lista(Nodo* cabeza){
  while (cabeza != NULL){
    printf("%d -> ", cabeza -> dato);
    cabeza = cabeza -> siguiente;
  }
  printf("NULL\n");
}

// Buscar un nodo por valor
Nodo* buscar_nodo(Nodo* cabeza, int valor){
  Nodo* actual = cabeza;
  while (actual != NULL){
    if (actual -> dato == valor){
      return actual;
    }
    actual = actual -> siguiente;
  }
  return NULL;
}

// Liberar toda la lista desde el inicio
void liberar_lista(Nodo** cabeza){
  Nodo* actual = *cabeza;
  Nodo* siguiente;
  while (actual != NULL){
    siguiente = actual -> siguiente;
    free(actual);
    actual = siguiente;
  }
  *cabeza = NULL;
}

// Liberar la lista desde el final empezando por el final
void liberar_lista_desde_final(Nodo** cabeza){
  if (*cabeza == NULL) return;

  Nodo* actual = *cabeza;
  Nodo* previo = NULL;

  // Moverse al final de la lista
  while (actual -> siguiente != NULL){
    previo = actual;
    actual = actual -> siguiente;
  }

  // Si solo hay un nodo
  if (previo == NULL){
    free(*cabeza);
    *cabeza = NULL;
    return;
  }

  // Desconectar el ultimo nodo y liberarlo
  previo -> siguiente = NULL;
  free(actual);

  // Llamada recursiva para liberar el resto de la lista
  liberar_lista_desde_final(cabeza);
}

