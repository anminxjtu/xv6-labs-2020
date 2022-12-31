#include "kernel/types.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{
  int n;
  if (argc == 1){
    write(1,"Please input parameter!\n",24);
    exit(1);
  }
  else{
    n = atoi(argv[1]);
    sleep(n);
    exit(0);
  }
}
