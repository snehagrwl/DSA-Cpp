#include<iostream>
using namespace std;
int factorial(int n) {
    if(n<0){
        cout<<"Enter positive number";
        return -1; 
    }
    if(n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    cout<<"Enter the number: ";
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}
