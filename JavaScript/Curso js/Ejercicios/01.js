function cualEsMayor(a, b) {
  if (a > b) {
    return a;
  }if (a < b) {
    return b;
  }else {
    return 'iguales';
  }

  // Otra forma
  //return (a > b) ? a: b; 
}

let mayor = cualEsMayor(10, 10);

console.log(mayor);