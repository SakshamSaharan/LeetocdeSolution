class Solution {
public:
    bool check(vector<int>& need,vector<int>& have){
        for(int i=0;i<256;i++){
            if(need[i] > have[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int low = 0,high = 0;
        int len = INT_MAX;
        int start = -1;
        vector<int>need(256,0);
        vector<int>have(256,0);
        string res = "";
        if(t.empty()) return res;
        for(int i=0;i<t.size();i++){
            need[(int)(t[i])]++;
        }
        while(high < s.size()){
            have[(int)(s[high])]++;
            while(check(need,have)){
                int currlen = high-low+1;
                if(currlen < len){
                    len = currlen;
                    start = low;
                }
                have[(int)(s[low])]--;
                low++;
            }
            high++;
        }
        return len==INT_MAX?"":s.substr(start,len);

    }
};