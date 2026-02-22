#include <stdio.h>

#include "listas_circulares.h"


CLista Crear_CLista() {
  CLista lista;
  Nodo* cabeza = NULL;
  lista.cabeza = cabeza;
}

int lista_vacia(CLista lista){
  return lista.cabeza == NULL;
}
void anadir_nodo(CLista* lista, int valor){
  Nodo* nuevo_nodo = crear_nodo(valor);
  if (lista_vacia(*lista)){
    lista -> cabeza = nuevo_nodo;
    nuevo_nodo -> siguiente = nuevo_nodo; // Apunta a sí mismo para formar la circularidad
    return;
  }
  Nodo* temp = lista -> cabeza;
  while (temp -> siguiente != lista -> cabeza){
    temp = temp -> siguiente;
  }
  temp -> siguiente = nuevo_nodo; // El último nodo apunta al nuevo nodo
  nuevo_nodo -> siguiente = lista -> cabeza; // El nuevo nodo apunta a la cabeza
  }

void buscar_dato(CLista lista, int valor){
  if (lista_vacia(lista)){
    printf("La lista esta vacia.\n");
    return;
  }
  Nodo* temp = lista.cabeza;
  do{
    if (temp -> dato == valor){
      printf("El valor %d se encuentra en la lista.\n", valor);
      return; 
    }
  temp = temp -> siguiente;
  }while(temp != lista.cabeza);
  printf("El valor %d no se encuentra en la lista.\n", valor);
}

void eliminar_nodo(CLista* lista, int valor){

}

void eliminar_cabeza(CLista* lista){

}

void eliminar_ultimo(CLista* lista){

}

void vaciar_lista(CLista* lista){

}

void imprimir_lista(CLista lista){
  if (lista_vacia(lista)){
    printf("La lista esta vacia.\n");
    return;
  }
  Nodo* temp = lista.cabeza;
  do{
    printf("%d -> ", temp -> dato);
    temp = temp -> siguiente;
  }while (temp != lista.cabeza);
}