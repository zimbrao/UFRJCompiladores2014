#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[256];

int main() {

  strncpy( a, "hello, world", 255 );
  a[255] = 0;
  printf( "%s" , a );
  printf( "%s" , "\n" );
  return 0;
}

