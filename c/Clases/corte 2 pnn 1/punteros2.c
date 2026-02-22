#include <stdio.h>

void fibonacci(int *x, int n);

int main() {
  int x = 2;
  

  fibonacci(&x, 20);
  printf("\nFinal value of x: %d\n", x);
  
  return 0;
}

void fibonacci(int *x, int n) {
  int y = 0; 
  y = (*x) + 1;
  for (int i = 0; i < n - 1; i++){
    printf("%d ", *x);
    int z = y;
    y = *x;
    *x = z + (*x);
  }
  printf("%d ", *x);
  
}