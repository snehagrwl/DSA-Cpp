#include<iostream>
#include<string>

using namespace std;
string addStrings(string num1, string num2) {
    int Num1=stoi(num1);
    int Num2=stoi(num2);
    int ans=Num1+Num2;
    string ans2=to_string(ans);
       return ans2; 
}
int main(){
    cout<<addStrings("11","11");
}
