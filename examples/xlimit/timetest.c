#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define curtime (clock() - start_time) / (double) CLOCKS_PER_SEC

/**
  This code run as a long as you have specified

  usage: ./name time_in_seconds
*/

int main(int argc, char **argv){

  if(argc != 2){
    printf("Usage: %s time_in_seconds\n",argv[0]);
    return 1;
  }

  clock_t start_time = clock();
  double until = (double) atoi(argv[1]);
  while(curtime < until);

  puts("This program finished correctly");
  return 0;
}
