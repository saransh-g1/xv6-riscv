#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"


int
main(int argc, char *argv[])
{
  char buf[64];

  if(argc != 2){
    printf("Usage: secret the-secret\n");
    exit(1);
  }
  char *end = sbrk(PGSIZE*32);
  end = end + 9 * PGSIZE;
  char *peak= end;

  strcpy(end, "my very very very secret pw is:   ");
  strcpy(end+32, argv[1]);
  strcpy(buf,peak);
  exit(0);
}

