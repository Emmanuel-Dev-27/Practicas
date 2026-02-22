#ifndef LISTAS_CIRCULARES_H
#define LISTAS_CIRCULARES_H

#include "nodos.h"

typedef struct {
  Nodo* cabeza;
}CLista;

CLista Crear_CLista();//

int lista_vacia(CLista lista);//

void anadir_nodo(CLista* lista, int valor);//

void buscar_dato(CLista lista, int valor);

void eliminar_nodo(CLista* lista, int valor);

void eliminar_cabeza(CLista* lista);

void eliminar_ultimo(CLista* lista);

void vaciar_lista(CLista* lista);

void imprimir_lista(CLista lista);//


#endif