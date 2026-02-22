# Calculadora Matricial

Descripción: Herramienta de consola diseñada para realizar operaciones matemáticas fundamentales con matrices de hasta 10x10. Permite al usuario interactuar mediante un menú para procesar datos matriciales de forma dinámica.

Conceptos Técnicos Aplicados:
> - Manejo de arreglos bidimensionales (matrices).
> - Paso de arreglos a funciones por referencia.
> - Lógica de validación de dimensiones para operaciones matriciales (ej. compatibilidad en multiplicación).
> - Modularización mediante archivos de cabecera (.h) y código fuente (.c).
> - Uso de funciones matemáticas (`math.h`) y manipulación de consola.

Stack: C (Estándar C99/C11), GCC.

Cómo ejecutar:
```bash
gcc CalculadoraMatricial.c matrices.c funciones_consola.c -o CalculadoraMatricial -lm
./CalculadoraMatricial
```

Notas de aprendizaje: En este ejercicio se practicó la organización de código en múltiples archivos y la validación rigurosa de entradas de usuario, además de reforzar los algoritmos algebraicos para manipulación de matrices.
