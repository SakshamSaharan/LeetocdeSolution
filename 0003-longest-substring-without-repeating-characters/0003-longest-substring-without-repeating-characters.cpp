class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high=0,low=0,maxlength=0;
        int n = s.size();
        unordered_map<char,int>mp;
        while(high < n){
            while(mp.find(s[high]) != mp.end()){
                mp[s[low]]--;
                if(mp[s[low]] == 0) mp.erase(s[low]);
                low++;
            }
            mp[s[high]]++;
            int length = high-low+1;
            maxlength = max(maxlength,length);
            high++;
        }
        return maxlength;
    }
};