#include "matrices.h"
#include "funciones_consola.h"

int main() {
  int opcion;

  int filasA, columnasA;
  int filasB, columnasB;
  int matrizA[max][max];
  int matrizB[max][max];
  int resultado[max][max];

  do{

    limpiar_matriz(matrizA);
    limpiar_matriz(matrizB);
    limpiar_matriz(resultado);

    limpiar_pantalla();
    opcion = obtener_opcion();

    switch (opcion)
    {
    case 1:
      printf("Ingresa las filas de las matrices a sumar \n");
      scanf("%d", &filasA);
      printf("Ingresa las columnas de las matrices a sumar \n");
      scanf("%d", &columnasA); 

      printf("Ingresa los elementos de la primera matriz %dx%d:\n", filasA, columnasA);
      leer_matriz(matrizA, filasA, columnasA);

      printf("Ingresa los elementos de la segunda matriz %dx%d:\n", filasA, columnasA);
      leer_matriz(matrizB, filasA, columnasA);
      suma_resta_matrices(matrizA, matrizB, resultado,filasA, columnasA, 0);

      imprimir_matriz(resultado, filasA, columnasA);

      esperar_enter();

      break;
    case 2:      
      printf("Ingresa las filas de las matrices a restar \n");
      scanf("%d", &filasA);
      printf("Ingresa las columnas de las matrices a restar \n");
      scanf("%d", &columnasA); 

      printf("Ingresa los elementos de la primera matriz %dx%d:\n", filasA, columnasA);
      leer_matriz(matrizA, filasA, columnasA);

      printf("Ingresa los elementos de la segunda matriz %dx%d:\n", filasA, columnasA);
      leer_matriz(matrizB, filasA, columnasA);
      suma_resta_matrices(matrizA, matrizB, resultado,filasA, columnasA, 1);

      imprimir_matriz(resultado, filasA, columnasA);

      esperar_enter();

      break;
    case 3:
      printf("Ingresa el numero de filas de la primera matriz: ");
      scanf("%d", &filasA);
      printf("Ingresa el numero de columnas de la primera matriz: ");
      scanf("%d", &columnasA);

      printf("ingresa el numero de filas de la segunda matriz: ");
      scanf("%d", &filasB);
      printf("Ingresa el numero de columnas de la segunda matriz: ");
      scanf("%d", &columnasB);

      if (!dimension_valida(filasA, columnasA, filasB, columnasB, 2)){
        esperar_enter();
        break;
      }
      printf("Ingresa los elementos de la primera matriz %dx%d:\n", filasA, columnasA);
      leer_matriz(matrizA, filasA, columnasA);
      printf("Ingresa los elementos de la segunda matriz %dx%d:\n", filasB, columnasB);
      leer_matriz(matrizB, filasB, columnasB);
      
      multiplicar_matriz(matrizA, matrizB, resultado, filasA, columnasA, columnasB);

      limpiar_pantalla();

      printf("La matriz resultante es:\n");
      imprimir_matriz(resultado, filasA, columnasB);
      esperar_enter();

      break;
    case 4:
      int escalar;

      printf("Ingresa el escalar: ");
      scanf("%d", &escalar);

      printf("Ingresa el numero de filas: ");
      scanf("%d", &filasA);
      printf("Ingresa el numero de columnas: ");
      scanf("%d", &columnasA);

      printf("Ingresa los elementos de la matriz %dx%d:\n", filasA, columnasA);
      leer_matriz(matrizA, filasA, columnasA);

      multiplicar_matriz_escalar(matrizA, filasA, columnasA, escalar);

      limpiar_pantalla();

      printf("La matriz resultante es:\n");

      imprimir_matriz(matrizA, filasA, columnasA);

      esperar_enter(); 

      break;
    case 5:
      printf("Ingresa el numero de filas: ");
      scanf("%d", &filasA);
      printf("Ingresa el numero de columnas: ");
      scanf("%d", &columnasA);  

      printf("Ingresa los elementos de la matriz %dx%d:\n", filasA, columnasA);
      leer_matriz(matrizA, filasA, columnasA);

      trasponer_matriz(matrizA, resultado, filasA, columnasA);
      limpiar_pantalla();
      printf("La matriz transpuesta es:\n");
      imprimir_matriz(resultado, columnasA, filasA);
      esperar_enter();

      break;
    case 6:
      printf("Saliendo del programa...\n");
      break;  
    
    default:
      break;
    }

  } while (opcion != 6);

  return 0;
}
