let array = [2, 7, 5, 15, -5, -100, 55];

function cuantosPositivos(arr) {
  let resultado = [0,0];
  
  for (const n of arr) {
    if (n < 0) {
      resultado[0] = resultado[0] + 1;
    }
    if (n > 0) {
      resultado[1] = resultado[1] + 1;
    }
  }
  return resultado
}

console.log(cuantosPositivos(array))