# Arkanoid

Descripción: Implementación del clásico juego Arkanoid utilizando Godot. El sistema genera niveles dinámicamente basados en plantillas de cadenas de texto y gestiona la física de la pelota y el bate, así como la destrucción de ladrillos por grupos.

Conceptos Técnicos Aplicados:
> - Instanciación dinámica de escenas (`PackedScene`, `instantiate`).
> - Generación de niveles mediante mapas de caracteres (String-based level design).
> - Uso de grupos para la detección lógica de colisiones y conteo de objetivos.
> - Temporizadores (`Timer`) para eventos programados (generación de enemigos).
> - Manipulación de propiedades visuales en tiempo de ejecución (`modulate`).

Stack: Godot Engine 4 (GDScript).

Cómo ejecutar:
1. Abrir `project.godot` en Godot Editor 4.x.
2. Presionar `F5` o el botón de "Play" para iniciar la escena principal `arkanoid.tscn`.

Notas de aprendizaje: Se practicó la lógica de diseño de niveles matricial y la gestión de ciclos de vida de nodos mediante código, además de la interacción básica entre cuerpos físicos y áreas.
