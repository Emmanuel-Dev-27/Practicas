#include <stdio.h>

int main(){
  int a = 0;
  int b = 0;

  printf("Suma: %d\n", a + b);
  printf("Resta: %d\n", a - b);
  printf("Multiplicacion: %d\n", a * b);
  //printf("Division: %f\n", (float) a / b);
  //printf("Modulo: %d\n", a % b);

  printf("\n");
  
  printf("Valor de a: %d\n", a);
  printf("Valor de b: %d\n", b);

  printf("\n");
  
  printf("Incremento pos-fija: %d\n", a++);
  printf("Incremento pre-fija: %d\n", ++a);
  printf("Decremento pos-fija: %d\n", b--);
  printf("Decremento pre-fija: %d\n", --b);
  
  printf("\n");

  a += 5; // a = a + 5
  b *= 2; // b = b * 2
  printf("Nuevo valor de a: %d\n", a);
  printf("Nuevo valor de b: %d\n", b);

  printf("\n");


  return 0;
}