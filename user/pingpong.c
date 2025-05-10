#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int pp[2],cp[2];
    char buff[100];
    if(argc > 1){
        fprintf(2,"usage: Sleep command[time ....]\n");
        exit(1);
    }
    pipe(pp),pipe(cp);

    if(fork()==0){
        // dup(pp[1]);
        // close(pp[1]);
    read(cp[0],buff,1);
    fprintf(1,"%d: received ping\n",getpid());
    close(cp[0]);

    write(pp[1],"h",1);
    close(pp[1]);
    }else{
    //   dup(pp[0]);
    //   close(pp[0]);
     
      write(cp[1],"h",1);
      close(cp[1]);

      read(pp[0],buff,1);
      fprintf(1,"%d: received pong\n",getpid());
      close(pp[0]);
    }
    exit(0);
}