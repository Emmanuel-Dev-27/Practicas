/**
 * Nombre: ancho x alto
 * 8K 7680 x 4320
 * 4K 3940 x 2160
 * WQHD 2560 x 1440
 * FHD 1920 x 1080
 * HD 1280 x 720
 */

function resolucion(ancho, alto) {
  if (ancho >= 7680) {
    if (alto < 4320) {
      return false;
    }
  return '8K';

  } else if (ancho >= 3940) {
      if (alto < 2160) {
        return false;
      }
    return '4K';

  } else if (ancho >= 2560) {
      if (alto < 1440) {
        return false;
      }
    return 'WQHD';
  
  } else if (ancho >= 1980) {
    if (alto < 1080) {
      return false;
    }
  return 'FHD';

  } else if (ancho >= 1280) {
    if (alto < 720) {
      return false;
    }
  return 'HD';
  
  } else {
    return false;
  }
}



let calidad = resolucion (3220, 2000);

console.log(calidad);