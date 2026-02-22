#ifndef LISTAS_SIMPLES_H
#define LISTAS_SIMPLES_H

#include "nodos.h"

void eliminar_nodo(Nodo** cabeza, int valor);


Nodo* buscar_nodo(Nodo* cabeza, int valor);

void insertar_inicio(Nodo** cabeza, int valor);
void insertar_final(Nodo** cabeza, int valor);
void insertar_despues(Nodo* nodo_anterior, int valor);

void liberar_lista(Nodo** cabeza);
void liberar_lista_desde_final(Nodo** cabeza);
void imprimir_lista(Nodo* cabeza);


#endif