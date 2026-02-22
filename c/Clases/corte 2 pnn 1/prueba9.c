#include <stdio.h>
#include <string.h>

int main(){
  char cad1[] = "apple";
  char cad2[] = "banana";
  char cad3[] = "apple";

  if (strcmp(cad1, cad2) < 0)
  {
    printf("%s es mayor que %s\n", cad1, cad2);
  }
  if (strcmp(cad1, cad3) == 0)
  {
    printf("%s es igual a %s\n", cad1, cad3);
  }
  return 0;
  
}