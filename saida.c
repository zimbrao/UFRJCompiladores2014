#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[256];
char b[256];
char c[256];

int main() {
  char temp_string_1[256];
  char temp_string_2[256];

  strncpy( a, "hello", 255 );
  a[255] = 0;
  strncpy( b, "world", 255 );
  b[255] = 0;

  strncpy( temp_string_1, a, 255 );
  strncat( temp_string_1, ", ", 255 );
  temp_string_1[255] = 0;


  strncpy( temp_string_2, temp_string_1, 255 );
  strncat( temp_string_2, b, 255 );
  temp_string_2[255] = 0;

  strncpy( c, temp_string_2, 255 );
  c[255] = 0;
  printf( "%s" , c );
  printf( "%s" , "\n" );
  return 0;
}

