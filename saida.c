#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a;
int b;

int main() {
  int temp_int_1;
  int temp_int_2;
  int temp_int_3;

  a = 10;
  b = 3;
  printf( "%s" , "total: " );
  temp_int_1 = a * 4;
  temp_int_2 = b * 2;
  temp_int_3 = temp_int_1 + temp_int_2;
  printf( "%d" , temp_int_3 );
  printf( "%s" , "\n" );
  return 0;
}

