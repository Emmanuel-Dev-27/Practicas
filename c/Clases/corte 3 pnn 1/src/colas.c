#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "colas.h"

Cola makeStack(){
  Cola cola;
  cola.inicio = NULL;
  cola.final = NULL;
  return cola;
}

void Insertar_Cola(Cola* cola, int dato){
  Nodo* nuevo = crear_nodo(dato);
  if (cola_vacia(*cola)){
    cola -> final = nuevo;
    cola -> inicio = nuevo;
    return;
  }
  Nodo* penultimo = cola -> final;
  cola -> final = nuevo;
  penultimo -> siguiente = nuevo;
  return;
}

void imprimir_cola(Cola cola){
  if (cola_vacia(cola)){
    printf("Cola vacia \n");
    return;
  }
  Nodo* temp = cola.inicio;
  while (temp->siguiente != NULL)
  {
    printf("%d \t", temp -> dato);
    temp = temp ->siguiente;
  }
  printf("%d\n", temp -> dato);
}

int cola_vacia(Cola cola){
  return cola.final == NULL;
}

void dequeve(Cola* cola){
  if (cola_vacia(*cola)){
    printf("Nada que eliminar \n");
    return;
  }
  Nodo* temp = cola->inicio;
  cola->inicio = temp->siguiente;
  
  free(temp);
  temp = NULL;
}

void vaciar_cola(Cola* cola){
  if(cola_vacia(*cola)){
    printf("la Cola ya se encuetra vacia\n");
    return;
  }
  while (cola->inicio != NULL){
    dequeve(cola);
  }
  printf("Cola vaciada\n");
}