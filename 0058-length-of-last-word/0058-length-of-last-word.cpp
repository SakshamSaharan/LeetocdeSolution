class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count1=0;
        int count2=0;
       // string ans= "";
        if(s[n-1] != ' '){
            for(int i=0;i<n;i++){
                count1++;
                if(s[i]==' '){
                    count1=0;
                }
            }
            return count1;
        }
        else{
            for(int i=n-2;i>=0;i--){
                if(s[i]==' ' && s[i+1] != ' ' && count2>0){
                    break;
                }
              else if(s[i]!=' '){
                count2++;
               }
            else{
                continue;
            }
            }
            return count2;
        }
        return -1;
    }
};