// CONST
const MODES = {
  DRAW: 'draw',
  ERASE: 'erase',
  RECTANGLE: 'rectangle',
  ELLIPSE: 'ellipse',
  PICKER: 'picker'
}

// UTILITIES
const $ = selector => document.querySelector(selector);
const $$ = selector => document.querySelectorAll(selector);

// ELEMENTS
const $canvas = $('#canvas'); // El $ en la variable es solo para saber que es un elemento del DOM
const $colorPicker = $('#color-picker');
const $clearBtn = $('#clear-btn');
const $drawBtn = $('#draw-btn');
const $rectangleBtn = $('#rectangle-btn');
const $eraseBtn = $('#erase-btn');
const $pickerBtn = $('#picker-btn');
const $ellipseBtn = $('#ellipse-btn')

const ctx = $canvas.getContext('2d');

// STATE
let isDrawing = false;
let isShiftPress = false;
let startX, startY
let lastX = 0;
let lastY = 0;
let mode = MODES.DRAW; // erase, rectangle, ellipse, picker
let imageData

// EVENTS
$canvas.addEventListener('mousedown', startDrawing);
$canvas.addEventListener('mousemove', draw);
$canvas.addEventListener('mouseup', stopDrawing);
$canvas.addEventListener('mouseleave', stopDrawing);

$colorPicker.addEventListener('change', handleChangeColor);
$clearBtn.addEventListener('click', clearCanvas);

document.addEventListener('keydown', handleKeyDown)
document.addEventListener('keyup', handleKeyUp)

$pickerBtn.addEventListener('click', () => {
  setMode(MODES.PICKER)
})

$rectangleBtn.addEventListener('click', () => {
  setMode(MODES.RECTANGLE)
})

$drawBtn.addEventListener('click', () => {
  setMode(MODES.DRAW)
})

$eraseBtn.addEventListener('click', () => {
  setMode(MODES.ERASE)
})

$ellipseBtn.addEventListener('click', () => {
  setMode(MODES.ELLIPSE)
})

// METHODS
function startDrawing(event) {
  isDrawing = true;

  const { offsetX, offsetY } = event;
  
  [startX, startY] = [offsetX, offsetY];
  [lastX, lastY] = [offsetX, offsetY];

  imageData = ctx.getImageData(
    0, 0, $canvas.width, $canvas.height
  );
}

function draw(event) {
  
  if (!isDrawing) return;
  
  const { offsetX, offsetY } = event;
  
  if (mode == MODES.DRAW || mode == MODES.ERASE) {
    // Comenzar el trazado
    ctx.beginPath();
  
    // Mover el trazado a las cordenadas actuales
    ctx.moveTo(lastX, lastY);
  
    // dibujar una linea entre coordenadas actuales y las nuevas
    ctx.lineTo(offsetX, offsetY);
  
    ctx.stroke();
  
    // Actualizar las ultimas cordenadas
    [lastX, lastY] = [offsetX, offsetY];

    return
  }

  if (mode == MODES.RECTANGLE) {
    ctx.putImageData(imageData, 0, 0)
    let width = offsetX - startX;
    let height = offsetY - startY;

    if (isShiftPress) {
      const sideLength = Math.min(
        Math.abs(width),
        Math.abs(height)
      )
      width = width > 0 ? sideLength : -sideLength;
      height = height > 0 ? sideLength : -sideLength;
    }

    ctx.beginPath();
    ctx.rect(startX, startY, width, height);
    ctx.stroke()
    return
  }

}

function stopDrawing() {
  isDrawing = false;
}

function handleChangeColor() {
  const { value } = $colorPicker;
  ctx.strokeStyle = value;
  console.log (value)
}

function clearCanvas() {
  ctx.clearRect(0, 0, $canvas.width, $canvas.height)
}

async function setMode(newMode) {
  let previousMode = mode;
  mode = newMode;
  // Para limpiar el boton activo actual
  $('button.active')?.classList.remove('active');
  
  if (mode == MODES.DRAW) {
    $drawBtn.classList.add('active');
    $canvas.style.cursor = 'cell';
    ctx.globalCompositeOperation = 'source-over';
    ctx.lineWidth = 2;
    return
  }
  
  if (mode == MODES.RECTANGLE) {
    $rectangleBtn.classList.add('active');
    $canvas.style.cursor = 'crosshair';
    ctx.globalCompositeOperation = 'source-over';
    ctx.lineWidth = 2;
    
    return
  }

  if (mode == MODES.ERASE) {
    $eraseBtn.classList.add('active');
    $canvas.style.cursor = 'url("./cursors/erase.png") 0 24, auto';
    ctx.globalCompositeOperation = 'destination-out';
    ctx.lineWidth = 20;
    return 
  }

  if (mode == MODES.PICKER) {
    $pickerBtn.classList.add('active');
    const eyeDropper = new window.EyeDropper();

    try {
      const result = await eyeDropper.open();
      const { sRGBHex } = result;
      ctx.strokeStyle = sRGBHex;
      $colorPicker.value = sRGBHex;
      setMode(previousMode)
    } catch (error) {
      // Si ha ocurrido un error o el usuario no ha seleccionado ningun color
    }

    $canvas.style.cursor = 'url("./cursors/picker.png") 0 24, auto';
    
    return
  }
}

function handleKeyDown({ key }) {
  isShiftPress = key == 'Shift';
  
  if (key == '+') {
    ctx.lineWidth = ctx.lineWidth + 1 
  }
  
  if (key == '-' ) {
    ctx.lineWidth = ctx.lineWidth - 1 
  }  
}

function handleKeyUp({ key }) {
  if (key == 'Shift')isShiftPress = false;
}

//INIT
setMode(MODES.DRAW);

// show picker if browser has support
if (typeof window.EyeDropper !== 'undefined') {
  $pickerBtn.removeAttribute('disabled')
}


console.log("Si estoy funcionando")