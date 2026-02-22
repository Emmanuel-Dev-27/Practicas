let i = 0;

while (i < 6) {
  i++;
  if (i === 2) {
    console.log('Aqui deberia ir el "2"');
    continue;
  }
  console.log(i);
}

console.log(' ');

let y = 0

while (y < 6) {
  y++;
  if (y === 4) {
    console.log('Aqui me detengo');
    break;
  }
  console.log(y);
}