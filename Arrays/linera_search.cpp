#include <iostream>
using namespace std;

void linearSearchAll(int A[], int n, int key) {
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            cout << "Found at index " << i << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Element not found.\n";
}

int main() {
    int A[] = {5, 7, 2, 7, 1, 7};
    int n = 6;
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    linearSearchAll(A, n, key);

    return 0;
}
