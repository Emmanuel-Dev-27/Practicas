extends Node2D

var raquetaIzquierda: Area2D
var raquetaDerecha: Area2D

var pelota: Area2D

var puntosIzquierda: int = 0
var puntosDerecha: int = 0

var enPartida: bool = false

var cifras = [
	load("res://imagenes/0.png"),
	load("res://imagenes/1.png"),
	load("res://imagenes/2.png"),
	load("res://imagenes/3.png"),
	load("res://imagenes/4.png"),
	load("res://imagenes/5.png"),
	load("res://imagenes/6.png"),
	load("res://imagenes/7.png"),
	load("res://imagenes/8.png"),
	load("res://imagenes/9.png")
]

var speed = 300

func _ready() -> void:
	raquetaIzquierda = $RaquetaIzquierda
	raquetaDerecha   = $RaquetaDerecha
	pelota           = $Pelota
	terminarPartida()

func _process(delta: float) -> void:
	# Raqueta Izquierda
	if Input.is_action_pressed("arriba1"):
		if raquetaIzquierda.position.y > 15:
			raquetaIzquierda.position.y -= speed * delta
		
	if Input.is_action_pressed("abajo1"):
		if raquetaIzquierda.position.y < 225:
			raquetaIzquierda.position.y += speed * delta
	
	# Raqueta Derecha
	if Input.is_action_pressed("arriba2") or Input.is_action_pressed("ui_up"):
		if raquetaDerecha.position.y > 15:
			raquetaDerecha.position.y -= speed * delta
		
	if Input.is_action_pressed("abajo2") or Input.is_action_pressed("ui_down"):
		if raquetaDerecha.position.y < 225:
			raquetaDerecha.position.y += speed * delta
	
	if not enPartida and Input.is_action_just_pressed("inicioPartida"):
		comenzarPartida()
		
	if Input.is_action_just_pressed("reiniciarPartida"):
		comenzarPartida()
		
	if enPartida and Input.is_action_just_pressed("terminarPartida"):
		terminarPartida()
	
func anotarPuntosDerecha() -> void:
	puntosDerecha += 1 
	pelota.position = Vector2(85, 125)
	pelota.indicarVelocidad(
		100 + 10 * (puntosDerecha + puntosIzquierda), 
		-100 - 10 * (puntosDerecha + puntosIzquierda))
	print("Jugador 2: " + str(puntosDerecha))
	actualizarPuntos()

func anotarPuntosIzquierda() -> void:
	puntosIzquierda += 1 
	pelota.position = Vector2(372-85, 125)
	pelota.indicarVelocidad(
		-100 - 10 * (puntosDerecha + puntosIzquierda), 
		-100 - 10 * (puntosDerecha + puntosIzquierda))
	print("Jugador 1: " + str(puntosIzquierda))
	actualizarPuntos()

func actualizarPuntos() -> void:
	$CifraIzquierda1.texture = cifras[ int(puntosIzquierda / 10.0 ) ]
	$CifraIzquierda2.texture = cifras[ puntosIzquierda % 10 ]
	$CifraDerecha1.texture   = cifras[ int(puntosDerecha / 10.0 ) ]
	$CifraDerecha2.texture   = cifras[ puntosDerecha % 10 ]
	   
	if puntosDerecha >= 5 or puntosIzquierda >= 5:
		terminarPartida()

func comenzarPartida() -> void:
	$TInicio.visible = false
	$TInstrucciones.visible = false
	pelota.position = Vector2(85,125)
	pelota.indicarVelocidad(100,100)
	puntosDerecha = 0
	puntosIzquierda = 0
	actualizarPuntos()
	enPartida = true

func terminarPartida() -> void:
	$TInicio.visible = true
	$TInstrucciones.visible = true
	pelota.indicarVelocidad(0,0)
	
