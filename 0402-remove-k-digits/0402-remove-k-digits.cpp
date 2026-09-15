class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        stack<char>s;
        for(char ch : num){
            while(k>0 && ! s.empty() && s.top() > ch){
                s.pop();
                k--;
            }
            s.push(ch);
        }
        while(! s.empty() && k >0){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string res = "";
        while(! s.empty()){
            res += s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());
        int i = 0;
        while(res[i] == '0'){
            i++;
        }
        res = res.substr(i);
        return res.empty() ? "0" : res;
    }
};