#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

vector<string> sort(vector<string>& name,vector<int>& height){
   vector<pair<int,string>> v;
   for(int i = 0; i<name.size(); i++) {
       v.push_back({heights[i], names[i]});
     }
sort(v.begin(),v.end(),greater<>());
vector<string>ans;
for(auto p:v){
ans.push_back(second);
}
return ans;
}
int main(){
  vector<string> name={"Mary","John","Emma"};
  vector<int> height={180,165,170};
  vector<string>sorted_name=sort(name,height);
  for(auto s:sorted_name) cout<<s<<" ";
return 0;
}
 
