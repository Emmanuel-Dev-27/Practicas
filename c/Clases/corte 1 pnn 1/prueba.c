#include <stdio.h>

int main() {
  float epsilon = 1.0;
  while (1.0 + epsilon / 2.0 > 1.0){
    epsilon /= 2.0;
  }
  printf("%e\n", epsilon);
  return 0;
}

void prueba(float var){
  var += 2;
  printf("%f\n", var);
}
