#include<iostream>
using namespace std;
int largest(int *arr,int size){
    int largest=INT16_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}
int main(){
 
  int arr[5]={1,4,8,2,7};
  cout<<largest(arr,5);
  return 0;
}
