class Solution {
public:
    string reverseWords(string s) {
        stack<string>str;
        int n = s.size();
        int i = 0;
        while(i < n){
            if(s[i] == ' '){
                i++;
                continue;
            }
            else if(isalnum(s[i])){
                string res = "";
                while(i<n && s[i] != ' '){
                    res+=s[i];
                    i++;
                }
                str.push(res);
                i++;
            }
        }
        string ans = "";
        while(! str.empty()){
            ans+=str.top() + " ";
            str.pop();
        }
        ans.pop_back();
        return ans;
    }
};