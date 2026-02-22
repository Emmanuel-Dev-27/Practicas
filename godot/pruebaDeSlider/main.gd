extends Node2D

@onready var zona = $Gestos
@onready var label = $Label

func _ready() -> void:
	label.text = "Esperando gesto..."

func _process(delta: float) -> void:
	cortarGolpear(delta)
	
func cortarGolpear(delta) -> void:
	var posicion_anterior: Vector2
	var gesto_iniciado: bool = false

	const UMBRAL_VELOCIDAD_Y: float = 1500.0
	
	if zona.pressing:
		var pos_actual = get_global_mouse_position()

		if not gesto_iniciado:
			gesto_iniciado = true
			posicion_anterior = pos_actual
			label.text = "Analizando..."
		else:
			# El gesto ya está en marcha. Calculemos la velocidad.
			# Evitamos la división por cero si el juego se congela por un instante.
			if delta > 0:
				var desplazamiento = pos_actual - posicion_anterior
				var velocidad = desplazamiento / delta
				
				if velocidad.y < -UMBRAL_VELOCIDAD_Y:
					label.text = "Deslizando ARRIBA (rápido)"
				
				elif velocidad.y > UMBRAL_VELOCIDAD_Y:
					label.text = "Deslizando ABAJO (rápido)"

			posicion_anterior = pos_actual
	else:
		if gesto_iniciado:
			gesto_iniciado = false
			label.text = "Esperando gesto..."
