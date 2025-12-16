#include<iostream>
#include<vector>
using namespace std;
void move_zero(vector<int>& arr){
    int j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j++;
        }
    }

    while(j<arr.size()){
        arr[j]=0;
        j++;
    }
}
int main(){
    vector<int> arr={0,1,0,3,13};
    move_zero(arr);
    for(int val:arr){
        cout<<val<<" ";
    }
    return 0;
}
