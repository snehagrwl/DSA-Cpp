class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int left=0;
        int max_len=0;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            while(freq[s[i]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            max_len=max(max_len,i-left+1);
        }
        return max_len;
    }
};