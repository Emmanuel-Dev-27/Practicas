let array = [2, 7, 5, 15, -5, -100, 55];

function getMenorMayor(arr) {
  let resultado = [0,0];
  
  for (const n of arr) {
    if (n < resultado[0]) {
      resultado[0] = n;
    }
    if (n > resultado[1]) {
      resultado[1] = n;
    }
  }
  return resultado
}

console.log(getMenorMayor(array))