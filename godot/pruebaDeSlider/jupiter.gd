extends Sprite2D

@onready var parent = $".."

func _ready() -> void:
	parent.pressing = false
	pass
	
func _process(delta: float) -> void:
	if parent.pressing:
		if get_global_mouse_position().distance_to(parent.global_position):
			position = get_global_mouse_position() - parent.global_position
			parent.posVector.x = position.x
			parent.posVector.y = position.y

func _on_button_button_down() -> void:
	parent.pressing = true

func _on_button_button_up() -> void:
	parent.pressing = false
