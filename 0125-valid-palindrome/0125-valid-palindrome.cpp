#include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;s[i] != '\0';i++){
            if(isalnum(s[i])){
                ans+=tolower(s[i]);
            }
        }
        int n= ans.length();
        int st=0,end=n-1;
        while(end>st){
            if(ans[st] != ans[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};