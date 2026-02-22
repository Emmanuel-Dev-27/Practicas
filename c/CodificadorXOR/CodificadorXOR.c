#include <stdio.h>
#include <string.h>
#include "funciones_consola.h"


void codificar_decodificar(char mensaje[], char clave[], char resultado[]);


int main() {
  const int MAX_MENSAJE = 300;
  const int MAX_CLAVE = 20;

  char mensaje[MAX_MENSAJE + 1];
  char clave[MAX_CLAVE + 1];
  char resultado[MAX_MENSAJE + 1];

  int opcion;

  do
  {
    limpiar_pantalla();
    printf("Menu:\n");
    printf("1. Codificar mensaje\n");
    printf("2. Decodificar mensaje\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    limpiar_buffer();

    switch (opcion)
    {
    case 1:
      printf("Ingrese el mensaje a codificar (Maximo de %d caracteres): ", MAX_MENSAJE);
      fgets(mensaje, sizeof(mensaje), stdin);
      mensaje[strcspn(mensaje, "\n")] = '\0';
      printf("Ingrese la clave de codificacion (Maximo de %d caracteres): ", MAX_CLAVE);
      fgets(clave, sizeof(clave), stdin);
      clave[strcspn(clave, "\n")] = '\0'; 

      codificar_decodificar(mensaje, clave, resultado);

      printf("Mensaje codificado: \n%s\n", resultado);
      esperar_enter();
      break;
    case 2:
      printf("Ingrese el mensaje a decodificar (Maximo de %d caracteres): ", MAX_MENSAJE);
      fgets(mensaje, sizeof(mensaje), stdin);
      mensaje[strcspn(mensaje, "\n")] = '\0';

      printf("Ingrese la clave de decodificacion (Maximo de %d caracteres): ", MAX_CLAVE);
      fgets(clave, sizeof(clave), stdin);
      clave[strcspn(clave, "\n")] = '\0';

      codificar_decodificar(mensaje, clave, resultado);

      printf("Mensaje decodificado: \n%s\n", resultado);

      esperar_enter();
    
    break;
    case 3:
      printf("Saliendo del programa.\n");
      break;
    

    case 9:
      //mostrar todos los valores de 32 a 126
      char msg[2];
      char res[2];
      char key[2];
      key[0] = 65; // 'A'
      key[1] = '\0';
      for (int i = 32; i <= 126; ++i) {
        key[0] = (char)i;
        printf("Clave usada: %c = %d \n", key[0], key[0]);

        for (int j = 32; j < 126; j++){
          msg[0] = j;
          msg[1] = '\0';

          codificar_decodificar(msg, key, res);
          
          char decoded[2];
          codificar_decodificar(res, key, decoded);
          
          printf("   %c = %d  |   %d = %c    |     %d = %c\n", msg[0], j, (unsigned char)res[0], res[0], (unsigned char)decoded[0], decoded[0]);
          
          if (msg[0] != decoded[0]){
            printf("Error\n");
            esperar_enter();
          }
        }
        esperar_enter();

      }
      esperar_enter();
    break;
    case 0:
      strncpy(mensaje, "Emmanuel", sizeof(mensaje) - 1);
      mensaje[sizeof(mensaje) - 1] = '\0';
      strncpy(clave, "Nat", sizeof(clave) - 1);
      clave[sizeof(clave) - 1] = '\0';

      codificar_decodificar(mensaje, clave, resultado);
      printf("Mensaje codificado: \n%s\n", resultado);

      codificar_decodificar(resultado, clave, resultado);
      printf("Mensaje decodificado: \n%s\n", resultado);
      
      esperar_enter();
      break;

    default:
      printf("Opcion invalida. Intente de nuevo.\n");
      esperar_enter();
      break;
    }
  } while (opcion != 3);

  return 0;
}

void codificar_decodificar(char mensaje[], char clave[], char resultado[]) {
  int longitud_mensaje = (int) strlen(mensaje);
  int longitud_clave = (int) strlen(clave);

  if (longitud_clave == 0) {
    printf("Error: La clave no puede estar vacia.\n");
    resultado[0] = '\0';
    return;
  }

  for (int i = 0; i < longitud_mensaje; i++) {
    unsigned char char_mensaje = (unsigned char) mensaje[i];
    unsigned char char_clave = (unsigned char) clave[i % longitud_clave];

    unsigned char m = char_mensaje - 32;
    unsigned char k = char_clave - 32;
    unsigned char res = m ^ k;

    resultado[i] = (res % 95) + 32;

    // printf("Debug: cm=%d m=%d, cc=%d k=%d, r=%d, c=%c\n", char_mensaje, m, char_clave, k, resultado[i], resultado[i]);
    
  }
  resultado[longitud_mensaje] = '\0';
}