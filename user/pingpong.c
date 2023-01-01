#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  //printf("%d\n", getpid());
  int pid;
  //printf("%d\n", pid);
  int p1[2];
  int p2[2];
  char *s = "\0";
  pipe(p1);
  pipe(p2);
  //printf("%d\n", getpid());
  pid = fork();
  if ( pid > 0) {
    write(p1[1], "ping", 4);
    wait(0);
    read(p2[0], s, 4);
    if (memcmp(s,"pong", 4)==0){
     printf("%d", getpid());
     write(1, ":recevied pong\n",15);
     exit(0);
    }
  }
  if (pid == 0){
    read(p1[0], s, 4);
    if (memcmp(s,"ping", 4)==0){
      printf("%d", getpid());
      write(1, ":received ping\n",15);
      write(p2[1], "pong", 4);
      exit(0);
    }  
  }
  
  exit(0);
}


