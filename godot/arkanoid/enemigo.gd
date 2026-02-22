extends Area2D

var velocidadX = 10
var velocidadY = 10

func _process(delta: float) -> void:
	position += Vector2(velocidadX * delta, velocidadY * delta)
	
	if randi() % 1000 > 990:
		velocidadX = -velocidadX
	if randi() % 1000 > 990:
		velocidadY = -velocidadY
		
	if position.x > 400:
		position.x = 400
	elif position.x < 50:
		position.x = 50
		
	position.y = clampf(position.y, 100, 200)
