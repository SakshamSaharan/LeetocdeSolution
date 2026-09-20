class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high=0,low=0,maxlength=0;
        int n = s.size();
        unordered_map<char,int>mp;
        while(high < n){
            if(mp.find(s[high]) != mp.end()){
                low = max(low,mp[s[high]] + 1);
            }
            mp[s[high]] = high;
            int length = high-low+1;
            maxlength = max(maxlength,length);
            high++;
        }
        return maxlength;
    }
};