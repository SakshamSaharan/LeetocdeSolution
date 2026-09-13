class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0,maxlength = 1;
        for(int i=0;i<n;i++){
            int l =i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxlength){
                    start = l;
                    maxlength = r-l+1;
                }
                l--;
                r++;
            }
            l = i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxlength){
                    start = l;
                    maxlength = r-l+1;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxlength);
    }
};