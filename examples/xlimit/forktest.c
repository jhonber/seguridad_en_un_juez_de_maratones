#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
  puts("Hola 1");
  fork();
  puts("Hola 2");
  fork();
  puts("Hola 3");
  puts("This program finished correctly");
  return 0;
}
