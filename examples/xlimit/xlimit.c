#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MEM (1)      // MEMORY FLAG
#define TIM (1<<1)  // TIME FLAG
#define PRC (1<<2)  // CHILDRENS FLAG

struct rlimit exec_time, proc_mem, proc_child;
int options;

void usage(char *pname){
  printf("Usage :%s [options] program <ARGUMENTS> \n", pname);
  puts("The options avaible are:");
  puts("\t -t <max execution time in seconds>");
  puts("\t -m <max process memory in bytes>");
  puts("\t -c <max number of childrens>");
  // For future implementations
}


int parse_options(int argc, char **argv){
  int op;
  options = 0;
  while( (op = getopt(argc,argv, "t:m:c:")) != -1){
    switch (op) {
      case 't':
        options |= TIM;
        exec_time.rlim_max = exec_time.rlim_cur = atoi(optarg);
        break;
      case 'm':
        options |= MEM;
        proc_mem.rlim_max = proc_mem.rlim_cur = atoi(optarg);
        break;
      case 'c':
        options |= PRC;
        proc_child.rlim_max = proc_child.rlim_cur = atoi(optarg);
        break;
    } 
  }

  if(optind >= argc){
    usage(argv[0]);
    exit(1);
  }
  
  return optind;
}



int main (int argc, char **argv){

  if( argc > 1){
    int lim = atoi(argv[1]);
    struct rlimit rl = {lim, lim};
    char command[100];
    *command = 0; 
    int i = parse_options(argc, argv);
    int ini = i;
    for(; i < argc; i++){
      strcat(command,argv[i]);
      strcat(command," ");
    }
    if(options & MEM){
      setrlimit(RLIMIT_DATA,  &proc_mem);
      setrlimit(RLIMIT_STACK, &proc_mem);
    }
    if(options & TIM){
      setrlimit(RLIMIT_CPU, &exec_time);
    }
    if(options & PRC){
      setrlimit(RLIMIT_NPROC, &proc_child);
    }
    if(execv(argv[ini],&argv[ini]) < 0) {
      fprintf(stderr,"ERROR");
    }

    //system(command);
    return 0;
  }

  usage(argv[0]);
  return 1;
}
