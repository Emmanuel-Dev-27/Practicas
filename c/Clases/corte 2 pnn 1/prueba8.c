#include <stdio.h>
#include <string.h>



int main(){
  char palabra1[] = "Hola";
  char palabra2[] = " mundo";

  strcat(palabra1,palabra2);
  printf("antes de la comprobacion: %s\n", palabra1);

  if(sizeof(palabra1) > strlen(palabra1) + strlen(palabra2)){
    strcat(palabra1,palabra2);
    printf("%s", palabra1);
  }
  else { return 0; }

  return 0;
}
