# Prueba de Slider y Gestos

Descripción: Proyecto experimental diseñado para detectar y categorizar gestos táctiles o de ratón (deslizamientos rápidos hacia arriba o abajo) mediante el análisis de la velocidad del vector de movimiento en tiempo real.

Conceptos Técnicos Aplicados:
> - Análisis cinemático simple (Velocidad = Desplazamiento / Delta).
> - Implementación de umbrales para la detección de "gestos rápidos".
> - Uso de `@onready` para referencias de nodos y `@export` para variables expuestas al editor.
> - Procesamiento de eventos táctiles/ratón en áreas específicas.

Stack: Godot Engine 4 (GDScript).

Cómo ejecutar:
1. Abrir `project.godot` en Godot Editor 4.x.
2. Ejecutar la escena `main.tscn`.
3. Hacer clic y arrastrar rápidamente hacia arriba o abajo para ver la detección en la etiqueta.

Notas de aprendizaje: Este ejercicio permitió entender la importancia del `delta` en el cálculo de físicas manuales y cómo implementar lógica de reconocimiento de patrones de entrada básicos.
