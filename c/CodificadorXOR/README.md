# Codificador XOR

Descripción: Programa que permite cifrar y descifrar mensajes de texto utilizando un algoritmo basado en la operación lógica XOR. Utiliza una clave simétrica rotativa para transformar cada carácter dentro del rango ASCII imprimible.

Conceptos Técnicos Aplicados:
> - Operaciones a nivel de bits (Bitwise XOR).
> - Manipulación de cadenas de caracteres (`string.h`).
> - Aritmética modular para el tratamiento de claves rotativas.
> - Representación de caracteres y rangos ASCII (desplazamiento para mantener caracteres legibles).
> - Aseguramiento de buffer y limpieza de entrada de consola.

Stack: C (Estándar C99/C11), GCC.

Cómo ejecutar:
```bash
gcc CodificadorXOR.c funciones_consola.c -o CodificadorXOR
./CodificadorXOR
```

Notas de aprendizaje: Se reforzó el entendimiento de cómo funcionan los cifrados simétricos básicos y la importancia de manejar correctamente los tipos de datos `unsigned char` para evitar problemas con la representación de bits en operaciones lógicas.
