#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // para tolower()

// Prototipos de funciones
void pausar_ejecucion();
void mostrar_saldos();
void limpiar_pantalla();
char opcion_jugador(); // Obtener opcion del jugador (par, impar, salir)
void salir_juego();
int  monto_apuesta();
int  entrada_invalida(int scanf_res); // Verificar si la entrada es invalida
int  numero_ruleta();
void procesar_apuesta(char opcion, int apuesta, int resultado);
void bienvenida();
void saldo_para_continuar(); // Verificar si el jugador o la banca se quedaron sin saldo
void ronda_actual();

// Variables globales
int  saldo_jugador = 1000;
int  saldo_banca = 10000;
char opcion;
int  apuesta;
int  resultado;

// Función principal
int main()
{
  srand((unsigned) time(NULL));

  bienvenida();
  pausar_ejecucion();
  limpiar_pantalla();

  do{
    ronda_actual();

    saldo_para_continuar();
    mostrar_saldos(); 

    opcion = opcion_jugador();
    apuesta = monto_apuesta();
    resultado = numero_ruleta();
    procesar_apuesta(opcion, apuesta, resultado);
    
  } while (1);
  return 0;
}

// Funciones

void ronda_actual(){
  static int ronda = 0;
  ronda++;
  printf("Ronda %d\n\n", ronda);
}

// Verificar si el jugador o la banca se quedaron sin saldo
void saldo_para_continuar(){
  if (saldo_jugador <= 0){
    printf("\nTe has quedado sin saldo. Fin del juego.\n");
    pausar_ejecucion();
    salir_juego();
  }

  if (saldo_banca <= 0){
    printf("\nLa banca se ha quedado sin saldo. Felicidades, has ganado el juego!\n");
    pausar_ejecucion();
    salir_juego();
  }
}

void bienvenida(){
  limpiar_pantalla();
  printf("Bienvenido al Casino!\n\n");
  printf("Tienes un saldo inicial de $%d\n", saldo_jugador);
  printf("La banca tiene un saldo inicial de $%d\n\n", saldo_banca);
}

void procesar_apuesta(char opcion, int apuesta, int resultado){
  int es_par = (resultado % 2 == 0);
    
  // Condiciones de perdida
  if ((opcion == 'p' && !es_par) || (opcion == 'i' && es_par) || resultado == 0) {
    saldo_jugador -= apuesta;
    saldo_banca += apuesta;

    resultado == 0 
    ? printf("\nLo siento, la bola cayo en 0. Perdiste $%d\n\n", apuesta)
    : printf("\nLo siento, perdiste $%d\n\n", apuesta);

    pausar_ejecucion();
    limpiar_pantalla();

    return;
  }
  
  // Condiciones de victoria
  if ((opcion == 'p' && es_par) || (opcion == 'i' && !es_par)) {
    saldo_jugador += apuesta;
    saldo_banca -= apuesta;
    printf("\nFelicidades! Ganaste $%d\n", apuesta);
    pausar_ejecucion();
    limpiar_pantalla();
    return;
  } 
}

int numero_ruleta(){
  int numero = rand() % 37; 
  printf("\nEl resultado de la ruleta es: %d\n", numero);
  
  return numero;
}

// Obtener monto de apuesta
int monto_apuesta(){
  int apuesta_local;
  int scanf_res;

  do {
    printf("Ingresa el monto a apostar: ");
    scanf_res = scanf(" %d", &apuesta_local);
    
    if (entrada_invalida(scanf_res)) {
      continue;
    }

    if (apuesta_local <= 0) {
      limpiar_pantalla();
      printf("El monto debe ser mayor a 0.\n");
      continue;
    }

    if (apuesta_local > saldo_jugador) {
      limpiar_pantalla();
      printf("No puedes apostar mas de tu saldo.\n");
      printf("Tu saldo actual es $%d\n", saldo_jugador);
      continue;
    }

    if (apuesta_local > saldo_banca) {
      limpiar_pantalla();
      printf("La banca no tiene suficiente saldo para cubrir esa apuesta.\n");
      printf("Elige un monto menor o igual a $%d\n", saldo_banca);
      continue;
    }

  } while (apuesta_local <= 0 || apuesta_local > saldo_jugador || apuesta_local > saldo_banca);

  return apuesta_local;
}

// Obtener opcion del jugador (par, impar, salir)
char opcion_jugador(){
  char opcion_local;
  int scanf_res;

  do
  {
    printf("\nApostar a par (p), impar (i) o salir (s): ");
    scanf_res = scanf(" %c", &opcion_local);
    
    if (entrada_invalida(scanf_res)) {
      continue;
    }
    
    // convertir a minuscula para simplificar comparaciones
    opcion_local = tolower(opcion_local);
    
    if (opcion_local == 's'){
      salir_juego();
    }

    if (opcion_local != 'p' && opcion_local != 'i') {
      limpiar_pantalla();
      printf("Opcion no valida. Usa 'p', 'i' o 's'.\n");
      continue;
    }
  } while (opcion_local != 'p' && opcion_local != 'i');
  
  return opcion_local;
}

// Verificar si la entrada del scanf es invalida
int entrada_invalida(int scanf_res){
  if (scanf_res != 1) {
      limpiar_pantalla();
      printf("Entrada invalida. Intenta de nuevo.\n");
      return 1;
  }
  return 0;
}

void salir_juego(){
  limpiar_pantalla();

  printf("Saldos finales\n\n");
  mostrar_saldos();

  printf("\nGracias por jugar. Saludos!\n");
  pausar_ejecucion();
  exit(0);
}

void mostrar_saldos(){
  printf("Saldo jugador: $%d\n", saldo_jugador);
  printf("Saldo banca:   $%d\n", saldo_banca);
}

void pausar_ejecucion(){
  printf("\nPresiona Enter para continuar...");
  while(getchar() != '\n' && getchar() != EOF);
  getchar();
}

void limpiar_pantalla(){
	printf("\033[2J\033[H");
  fflush(stdout);
}