#include "matrices.h"
#include "funciones_consola.h"


void menu_de_opciones(){
  printf("----- Calculadora Matricial -----\n");
  printf("1. Sumar matrices\n");
  printf("2. Restar matrices\n");
  printf("3. Multiplicar matrices\n");
  printf("4. Multiplicar matriz por escalar\n");
  printf("5. Transponer matriz\n");
  printf("6. Salir\n");
  printf("---------------------------------\n");
  printf("Seleccione una opcion: ");
}

int obtener_opcion(){
  int scanf_res;
  int opcion;
  do{
    menu_de_opciones();
    scanf_res = scanf(" %d", &opcion);

    if (entrada_invalida(scanf_res)) {
      printf("Opcion invalida. Intenta de nuevo.\n");
      limpiar_buffer();
      continue;
    }
  } while (entrada_invalida(scanf_res));
  return opcion;
}

void leer_matriz(int matriz[max][max], int fila, int columna){
  
  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++) {
      printf("Elemento [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void imprimir_matriz(int matrizA[max][max], int fila, int columna){
  printf("La matriz es:\n");
  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++) {
      printf("%d ", matrizA[i][j]);
    }
    printf("\n");
  }
}

int dimension_valida(int filasA, int columnasA, int filasB, int columnasB, int operacion){
  
  if (operacion == 1) { // Suma o resta
    if (filasA != filasB || columnasA != columnasB) {
      limpiar_pantalla();
      printf("Error: Las matrices deben tener las mismas dimensiones para sumar o restar.\n");
      return 0;
    }
  } else if (operacion == 2) { // Multiplicacion
    if (columnasA != filasB) {
      limpiar_pantalla();
      printf("Error: El numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda matriz para multiplicar.\n");
      return 0;
    }
  }
  return 1;
}

void limpiar_matriz(int matriz[max][max]){
  for (int i = 0; i < max; i++){
    for (int j = 0; j < max; j++){
      matriz[i][j] = 0;
    }
  }
}


void suma_resta_matrices(int matrizA[max][max], int matrizB[max][max], int resultado[max][max], int fila, int columna, int operacion){
  for (int i = 0; i < fila; i++){
    for (int j = 0; j < columna; j++){
      resultado[i][j] = matrizA[i][j] + (pow(-1,operacion) * matrizB[i][j]);
    }
  }
}

void multiplicar_matriz(int matrizA[max][max], int matrizB[max][max], int resultado[max][max], int filasA, int columnasA, int columnasB) {
    
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void multiplicar_matriz_escalar(int matrizA[max][max], int fila, int columna, int escalar){
  
  for (int i = 0; i < fila; i++){
    for (int j = 0; j < columna; j++){
      matrizA[i][j] = matrizA[i][j] * escalar;
    }
    printf("\n");
  }
}

void trasponer_matriz(int matrizA[max][max], int resultado[max][max], int fila, int columna){
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            resultado[j][i] = matrizA[i][j];
        }
    }
}