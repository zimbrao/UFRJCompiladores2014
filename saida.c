#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a;
int b;

int main() {
  int temp_int_1;
  int temp_int_2;
  int temp_int_3;
  int temp_int_4;

  temp_int_1 = a + b;
  temp_int_2 = 10 * a;
  temp_int_3 = 1 + temp_int_2;
  temp_int_4 = temp_int_1 * temp_int_3;
  a = temp_int_4;
  printf( "%s" , "hello, world\n" );
  return 0;
}

