class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0,length = 0;
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i] == s[i-1]){
                length++;
            } else{
                length = 1;
            }
            ans += length;
        }
        return ans%1000000007;
    }
};