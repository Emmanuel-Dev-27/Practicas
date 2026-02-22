#1 DETECCION DEL SISTEMA OPERATIVO
ifeq ($(OS),Windows_NT)
	SHELL := cmd.exe
	MKDIR = if not exist $(1) mkdir $(1)
	TARGET =  bin/programa.exe
	CLEAN = if exist build rmdir /s /q build && if exist bin rmdir /s /q bin
else
	MKDIR = mkdir -p $(1)
	RM = rm -rf build bin
	TARGET = bin/programa
	CLEAN = rm -rf build bin
endif


#Declaracion del Compilador
CC = gcc

#Declaracion de las banderas
CFLAGS = -Wall -Wextra -g -Iinclude

# Rutas de archivos (usa / siempre, el Makefile las convertirá donde sea necesario)
SRC = src/main.c src/listas_circulares.c src/nodos.c
OBJ = $(SRC:src/%.c=build/%.o)


#Regla Para construir el ejecutable
all: $(TARGET)

$(TARGET): $(OBJ)
	@$(call MKDIR, bin)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

#Regla para compilar .c a .o
build/%.o: src/%.c
	@$(call MKDIR, build)
	$(CC) $(CFLAGS) -c $< -o $@ 


clean:
	@$(CLEAN)