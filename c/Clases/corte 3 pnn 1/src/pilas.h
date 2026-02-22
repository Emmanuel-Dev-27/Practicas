#ifndef PILA_H
#define PILAS_H
#include "nodos.h"

typedef struct Pila {
  Nodo* tope;
} Pila;

void inicializar_pila(Pila* pila);

int vacia(Pila* pila);

void añadir(Pila* pila, int valor);

int eliminar_tope(Pila* pila);


#endif