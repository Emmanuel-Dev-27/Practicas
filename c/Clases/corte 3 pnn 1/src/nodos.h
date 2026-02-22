#ifndef NODOS_H
#define NODOS_H


typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* crear_nodo(int valor);


// Estructura para la pila

#endif