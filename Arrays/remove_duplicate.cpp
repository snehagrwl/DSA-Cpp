#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    if(arr.empty()) return 0;

    int j = 0;  // index of last unique element

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int main() {
    vector<int> arr = {1,1,2,2,3};
    int newLength = removeDuplicates(arr);

    for(int i = 0; i < newLength; i++){
        cout << arr[i] << " ";
    }
  return 0;
}
