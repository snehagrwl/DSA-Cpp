class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        int count=0;
        string best="";
        for (int right=0;right<s.size();right++){
            if(s[right]=='1'){
                count++;
            }
            while(count>k || (count==k && s[left]=='0')){
                if(s[left]=='1') count--;
                left++;
            }

            if(count==k){
                string curr=s.substr(left,right-left+1);
                if(best=="") best=curr;
                else if(curr.length()<best.length()) best=curr;
                else if(curr.length()==best.length() && curr<best) best=curr;
            }
        }
        return best;
    }
};