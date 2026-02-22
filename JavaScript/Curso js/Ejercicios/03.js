/**
 * Validar que no sea menor a cero y que el elemento exista en el array
 */

function getByIdx(arr, idx) {
  if (idx < 0 || arr.length <= idx) {
    return 'El elemento no existe';
  }
  return arr[idx];
}

console.log(getByIdx([1,2],1));