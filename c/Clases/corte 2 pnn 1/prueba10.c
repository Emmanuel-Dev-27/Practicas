#include <stdio.h>

void imprimirMatriz(int arr[][3], int filas);

int main(){
  int matriz[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  imprimirMatriz(matriz, 3);

  printf("\n\n");

  return 0;
}

void imprimirMatriz(int arr[][3], int filas){
  for(int i = 0; i < filas; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}