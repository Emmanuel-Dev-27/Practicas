function createUser(name, email, activo) {
  return{
    email,
    name,
    activo,
    recuperarClave: function () {
      console.log('Recuperando clave...');
    },
  };
}

let user = createUser('Emmanuel', 'encr@gmail.com', true);
let user1 = createUser('Nat', 'nat@gmail.com', true);

console.log(user, user1);