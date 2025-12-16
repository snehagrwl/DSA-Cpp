#include <iostream>
using namespace std;
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    int freq[26] = {0};
    // Count frequency
    for(char val : s) {
        freq[val - 'a']++;
        
    }
    for(int i=0;i<s.size();i++){
        cout<<freq[i]<<" ";
    }
    cout<<endl;
    // Find first non-repeating character
    for(char val : s) {
        if(freq[val - 'a'] == 1) {
            cout << "First non-repeating character: " << val;
            return 0;
        }
    }
    cout << "No non-repeating character found";
    return 0;
}
