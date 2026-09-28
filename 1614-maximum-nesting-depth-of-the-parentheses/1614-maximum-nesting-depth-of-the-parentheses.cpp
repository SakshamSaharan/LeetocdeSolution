class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxcount = 0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
               st.push(s[i]);
               count++;
               maxcount = max(maxcount,count);
            } 
            else if(s[i] == ')'){
                st.pop();
                count--;
            }
        }
        return maxcount;
    }
};