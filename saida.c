#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a;
int b;

int main() {
  int temp_bool_1;
  int temp_int_1;

  a = 10;
  b = 13;
  temp_int_1 = a + 5;
  temp_bool_1 = temp_int_1 > b;
  if( temp_bool_1 ) goto if_true;
  goto if_false;
  if_true:
  printf( "%s" , "'a' é maior\n" );
  goto if_fim;
  if_false:
  printf( "%s" , "'b' é maior\n" );
  if_fim:
  printf( "%s" , "Fim\n" );
  return 0;
}

