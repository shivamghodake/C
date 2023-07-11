#include<stdio.h>
#include<stdlib.h>
int main(){

  int n = 11;
  int largest;
  int *numarr = (int*)malloc(n * sizeof(int));
  for(int i=0;i<11;i++){
    scanf("%d",&numarr[i]);
  }
  largest = numarr[0];
  for(int i=0;i<11;i++){
    if(numarr[i]>largest){
      largest = numarr[i];
    }
  }
  numarr = (int*)realloc(numarr,5*sizeof(int));
  int smallest = numarr[0];
  for(int i = 0;i<6;i++){
    if(smallest>numarr[i]){
      smallest = numarr[i];
    }
  }
  printf("%d",largest);
  printf("\n%d",smallest);
  return 0;
}


