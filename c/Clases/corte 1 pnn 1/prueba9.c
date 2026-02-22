//operadores a nivel de bits
#include <stdio.h>  

int main(){
  unsigned char a = 181;      //1011 0101
  unsigned char b = 100;      //0110 0100

  printf("a & b: %d\n", a & b);   //0010 0100 = 36
  printf("a | b: %d\n", a | b);   //1111 0101 = 245
  printf("a ^ b: %d\n", a ^ b);   //1101 0001 = 209
  printf("~(a ^ b): %d\n", (unsigned char) ~(a ^ b));//0010 1110 = 46
  printf("~a: %d\n", ~a);         //0100 1010 = -182
  printf("b << 1: %d\n", b << 1); //1100 1000 = 200
  printf("b >> 1: %d\n", b >> 1); //0011 0010 = 50

  return 0;
}