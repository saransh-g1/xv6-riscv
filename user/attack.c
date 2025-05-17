#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"

int
main(int argc, char *argv[])
{
  char *end = sbrk(PGSIZE*32);
  printf("this is the memory,%s",end);
  fprintf(2,"%s",end);
  exit(0);
}
