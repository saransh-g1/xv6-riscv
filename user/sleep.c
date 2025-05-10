#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"


void local_sleep(int n){
    sleep(n);
    return;
  }
  
int main(int argc,char *argv[]){
    int i;
    if(argc <= 1){
        fprintf(2,"usage: Sleep command[time ....]\n");
        exit(1);
    }

    //conver the string argument to number for this will be using atoi
     for(i=1; i<argc; i++){
        int n= atoi(argv[i]);
        local_sleep(n);
     }
     exit(0);
}

