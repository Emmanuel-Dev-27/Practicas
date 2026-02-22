#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Prototipos de funciones
void generar_relampago();                    // Generar relampago
long tiempo_relampago();                     // Tiempo del relampago
long tiempo_trueno();                        // Retraso del sonido
float distancia_relampago(long t1, long t2); // Distancia del relampago

// Variables globales
long tiemp1 = 0;
long tiemp2 = 0;
float dist = 0.0;

// Función principal
int main(){
  srand((unsigned) time(NULL));               // Inicializar semilla aleatoria

  generar_relampago();                        // Esperar relampago
  tiemp1 = tiempo_relampago();                // Marcar tiempo del relampago
  tiemp2 = tiempo_trueno();                   // Simular retardo del trueno
  dist = distancia_relampago(tiemp1, tiemp2); // Calcular distancia

  printf("Tiempo del relampago en ticks: %ld\n", tiemp1);
  printf("Tiempo del sonido en ticks: %ld\n", tiemp2);
  printf("La distancia del relampago es: %.2f metros\n", dist);

  return 0;
}

// Definición de funciones
void generar_relampago(){
  int numero;

  do {
    numero = rand() % 20000 + 1;
  } while (numero != 1000);
}

// Funcion sencilla para que sea mas legible
long tiempo_relampago(){
  return clock();
}

long tiempo_trueno(){
  int valor_aleatorio = rand() % 30000 + 1;

  for (int j = 0; j < valor_aleatorio; j++){
    for ( register unsigned int h = 0; h < 5000; h++){}
  }
  return clock();
}

float distancia_relampago(long t1, long t2){
  float segundos = (float)((t2 - t1) / 18.2);
  float resultado = segundos * 330;
  return resultado;
}