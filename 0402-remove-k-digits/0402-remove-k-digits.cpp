class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        stack<char>s;
        int i = 0;
        while(i < n){
            char ch = num[i];
            while(k>0 && ! s.empty() && s.top() > ch){
                s.pop();
                k--;
            }
            s.push(ch);
            i++;
        }
        while(k > 0){
            s.pop();
            k--;
        }
        string res = "";
        while(! s.empty()){
            res += s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());
        i = 0;
        while(i < res.size() && res[i] == '0') i++;
        res = res.substr(i);
        return res.empty() ? "0" : res;
    }
};