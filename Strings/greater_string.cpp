#include<iostream>
#include<string>
using namespace std;

int main(void){
  
    string str1="greater string";
    string str2="smaller";
  
    int x=str1.length();
    int y=str2.length();
  
    if(x>y) cout<<" string 1 is greater";
    else cout<<"string 2 is greater";
  
    return 0;
}
