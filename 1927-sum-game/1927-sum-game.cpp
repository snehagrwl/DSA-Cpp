class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int half=n/2;
        int sumFirst=0;
        int sumSecond=0;
        int questionFirst=0;
        int questionSecond=0;
        for(int i=0;i<half;i++){
            if(num[i]=='?'){
                questionFirst++;
            }
            else{
                sumFirst+=num[i]-'0';
            }
            
        }
        for(int i=half;i<n;i++){
            if(num[i]=='?') questionSecond++;
            else sumSecond+=num[i]-'0';
        }
        int diffSum=sumFirst-sumSecond;
        int diffQuestion=questionSecond-questionFirst;

        if(diffSum*2==diffQuestion*9){
            return false;
        }
        return true;
    }
};