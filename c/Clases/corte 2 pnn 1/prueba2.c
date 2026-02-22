#include <stdio.h>

int main()
{
  int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };
  for (int i = 0; i < 6; i++)
  {
    printf("Elemento en fila 0, columna %d: %d\n", i, matriz[0][i]);
  }

  printf("\n");
  return 0;
}
