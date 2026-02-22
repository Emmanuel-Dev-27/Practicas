#include <stdio.h>

void mostrar(float valor);

int main(){
  mostrar(10);
  return 0;
}

void mostrar(float valor){
  printf("%f\n", valor);
}