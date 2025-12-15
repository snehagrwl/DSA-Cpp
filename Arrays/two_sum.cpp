#include <iostream>
#include <vector>
using namespace std;

void two_sum(vector<int>& arr, int target) {
    int size = arr.size();
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] + arr[j] == target) {
                cout << "Indices: " << i << " and " << j << endl;
                return;
            }
        }
    }
    cout << "Could not find pair" << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    two_sum(arr, target);
    return 0;
}
