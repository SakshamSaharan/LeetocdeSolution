class Solution {
public:
    bool isPalindrome(string s) {
        bool pali = true;
        string res = "";
        for(int i=0;i<s.size();i++){
            if(! isalnum(s[i])){
                continue;
            } 
            else{
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    int x = s[i] - 'A';
                    s[i] = 'a' + x;
                }
                res += s[i];
            }
        }
        int j = res.size()-1;
        int i = 0;
        while(j > i){
            if(res[j] != res[i]){
                pali = false;
                break;
            }
            i++;
            j--;
        }
        return pali;
    }
};