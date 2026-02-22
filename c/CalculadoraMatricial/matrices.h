#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <math.h>


void menu_de_opciones();
int obtener_opcion();


#define max 10

void leer_matriz(int matriz[max][max], int fila, int columna);

void imprimir_matriz(int matrizA[max][max], int fila, int columna);

int dimension_valida(int filasA, int columnasA, int filasB, int columnasB, int operacion);

void limpiar_matriz(int matriz[max][max]);


void suma_resta_matrices(int matrizA[max][max], int matrizB[max][max], int resultado[max][max], int fila, int columna, int operacion);

void multiplicar_matriz(int matrizA[max][max], int matrizB[max][max], int resultado[max][max], int filasA, int columnasA, int columnasB);

void multiplicar_matriz_escalar(int matrizA[max][max], int fila, int columna, int escalar);

void trasponer_matriz(int matrizA[max][max], int resultado[max][max], int fila, int columna);

#endif