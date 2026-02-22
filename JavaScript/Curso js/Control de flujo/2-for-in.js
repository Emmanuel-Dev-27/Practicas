let user = {
  id: 1,
  name: 'nat',
  age: 20,
  animal: 'tardigrado',
};

for (let prop in user) {
  console.log(prop);
}

console.log(' ');

for (let prop in user) {
  console.log(prop,':', user[prop]);
}

console.log(' ');

// Codigo antiguo

let animales =['Gato', 'Perro','Dragon'];

for (let animal in animales) {
  console.log(animal, animales[animal]);
}