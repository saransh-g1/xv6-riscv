#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"


// void prime(int div, int num[],int length){

//   if(length==0){
//      return;
//   }
//    int p[2];
//    pipe(p);
//    int selectedNum[280];
 
//    if(fork()==0){
//       read(p[0], &selectedNum, length);  
//       fprintf(1,"Prime %d\n",selectedNum[0]);
//       int buffer[280];
//       int buflength=0;
//       for(int i=1;i<length; i++){
//         if(selectedNum[i]%div!=0){
//           buffer[buflength++]=selectedNum[i];
//          }
//       }
//       close(p[0]);
//       prime(buffer[0],buffer,buflength);
//    }else{
//     int *n;
//     n=num;
//     close(p[0]);
//     write(p[1],n,length);
//     close(p[1]);
//    }
//    return;
// }


void prime(int div){
  if(div==0){
      return;
  }
  for(int i=0; i<div; i++){
    if(i!=0){
     
    }
     int p[2];
     pipe(p);
     close(p[1]);
     read(p[0],&div,1);
     fprintf(1,"prime %d\n",div);
     close(p[0]);
     write(p[1],&div,1);
     close(p[1]);
  }
       
  
}
int main(int argc, char *argv[]){
   // int num[278];
    if(argc != 1 && !strcmp(argv[1],"prime")){
        fprintf(2,"usage: Prime command [...]\n");
        exit(1);
      }
    
    // for(int i=0; i<278; i++){
    //     num[i]=i+2;
    // }
        prime(30);

      exit(0);
}