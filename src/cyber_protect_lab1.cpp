//#include <iostream>
#include<stdio.h>

void swap(int* a, int* b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int fast_sort(int* begin, int* end){
  if((end-begin)<1)
    return 0;
  int* compare=begin+(end-begin)/2;
  int i=0,j=0;

  do{
    while(*(begin+i)<*compare)
      i++;
    while(*(end-j)>*compare)
      j++;
    if((begin+i)<(end-j)){
      swap(begin+i,end-j);
      i++;
      j++;
    }
  }while((begin+i) < (end-j));
  //swap(compare,end-j);
  if(begin<end-j)
    fast_sort(begin,begin+i);
  if(begin+i<end)
    fast_sort(end-j,end);
  return 0;
}


int main(){
  int mas[]={5,2,7,9,2,45,876,2};
  fast_sort(&mas[0],&mas[7]);
  for(int i=0;i<8;i++)
    printf("%d", mas[i]);
  return 0;
}
