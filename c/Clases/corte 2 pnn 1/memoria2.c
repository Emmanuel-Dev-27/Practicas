#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);

int main(){
  int (* operacion)(int x, int y);

  operacion = suma;
  printf("Suma: %d\n", operacion(5, 3));

  operacion = resta;
  printf("Resta: %d\n", operacion(5, 3));
  
  operacion = multiplicacion;
  printf("Multiplicación: %d\n", operacion(5, 3));
  return 0;
}

int suma(int a, int b){
    return a + b;
}

int resta(int a, int b){
    return a - b;
}

int multiplicacion(int a, int b){
    return a * b;
}