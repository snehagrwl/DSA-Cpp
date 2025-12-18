#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>&nums,int val){
    int count=0;
    int j=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[j]=nums[i];
            cout<<nums[j]<<" ";
            j++;
            count++;
        }
    }
    cout<<endl;
    return count;
}
int main(){
    vector<int>nums={3,2,2,3};
    int val=2;
    cout<<removeElement(nums,val);
}
