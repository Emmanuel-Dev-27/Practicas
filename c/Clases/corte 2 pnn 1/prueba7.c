#include <stdio.h>
#include <string.h>

int main(){
  char palabra[] = "Palabra";

  char destino[5];

  strncpy(destino, palabra, 5); // no garantiza el caracter nulo

  destino[4] = '\0';

  printf("%s", destino);

  return 0;
}
