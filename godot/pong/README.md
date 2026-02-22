# Pong Multiplayer

Descripción: Versión local para dos jugadores del juego clásico Pong. Incluye un sistema de puntuación visual, aceleración progresiva de la pelota y gestión de estados de partida (inicio, reinicio y fin).

Conceptos Técnicos Aplicados:
> - Detección de colisiones mediante `Area2D`.
> - Gestión de entradas para múltiples jugadores (Input Mapping).
> - Sistema de puntuación con representación gráfica mediante texturas dinámicas.
> - Lógica de aceleración de proyectiles basada en eventos de anotación.
> - Carga dinámica de recursos (`load`).

Stack: Godot Engine 4 (GDScript).

Cómo ejecutar:
1. Abrir `project.godot` en Godot Editor 4.x.
2. Ejecutar la escena `pong.tscn`.
3. Controles: `W/S` para Jugador 1 y `Flechas` o `UI Up/Down` para Jugador 2.

Notas de aprendizaje: Se reforzó el manejo de sistemas de coordenadas, la gestión de inputs simultáneos y la actualización de UI basada en el estado lógico del juego.
