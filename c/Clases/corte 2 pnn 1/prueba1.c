#include <stdio.h>

int numero[5];
char letra[10];
float temperatura[7];

int main(){
  int digitos_pares[] = {2, 4, 6, 8};
  int numero[5] = {10, 20, 30, 40, 50};
  char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
  float temperatura[7] = {36.5, 37.0, 38.2, 39.1, 36.8, 37.5, 38.0};

  printf("Tamaño de un elemento en bytes %zu\n", sizeof(numero[0]));
  printf("Tamaño del arreglo vocales %zu\n", sizeof(vocales)/sizeof(vocales[0]));

  printf("\n");

  printf("Tamaño en bytes del arreglo digitos_pares: %zu\n", sizeof(digitos_pares));
  printf("numero de elementos del arreglo digitos_pares: %d\n", sizeof(digitos_pares)/sizeof(digitos_pares[0]));
  return 0;
}