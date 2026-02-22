#ifndef COLAS_H
#define COLAS_H

#include "nodos.h"

typedef struct {
  Nodo* inicio;
  Nodo* final;
} Cola;

Cola makeStack();

void Insertar_Cola(Cola* cola, int dato);

void imprimir_cola(Cola cola);

int cola_vacia(Cola cola);

void dequeve(Cola* cola);

void vaciar_cola(Cola* cola);

#endif