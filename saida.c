#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int x_int;
  double x_double;
  float x_float;

  int temp_bool_1;
  int temp_bool_2;
  int temp_bool_3;
  int temp_bool_4;
  int temp_bool_5;
  int temp_bool_6;
  int temp_int_1;
  int temp_int_2;
  int temp_int_3;

  x_int = 0;
L_for_cond_1:
  temp_bool_5 = x_int <= 20;
  temp_bool_6 = !temp_bool_5;
  if( temp_bool_6 ) goto L_for_fim_1;
  temp_int_1 = x_int * x_int;
  temp_int_2 = temp_int_1 % 3;
  temp_bool_1 = temp_int_2 == 0;
  temp_bool_2 = !temp_bool_1;
  if( temp_bool_2 ) goto L_passo_pipe_1;
  temp_int_3 = x_int % 2;
  temp_bool_3 = temp_int_3 == 0;
  temp_bool_4 = !temp_bool_3;
  if( temp_bool_4 ) goto L_passo_pipe_1;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );
L_passo_pipe_1:
  x_int = x_int + 1;
  goto L_for_cond_1;
L_for_fim_1:
  return 0;
}

