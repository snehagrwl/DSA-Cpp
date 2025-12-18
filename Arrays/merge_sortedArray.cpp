#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

 vector<int> mergeArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         nums1.resize(m);
         for(int val:nums2){
         nums1.push_back(val);
    }
    sort(nums1.begin(),nums1.end());
    return nums1;
    }
int main(){
    vector<int> arr={1,2,3,0,0,0};
    vector<int> brr={3,4,5};
    mergeArray(arr,3,brr,3);
    for(int val:arr) cout<<val<<" ";
    return 0;
}
