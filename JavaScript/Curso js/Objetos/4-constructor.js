function Usuario() {
  this.id = 1;
  this.recuperarClave = function () { // metodo
    console.log('recuperando');
  }
}

let usuario = new Usuario();

console.log(usuario);