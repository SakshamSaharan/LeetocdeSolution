class Solution {
public:
    int ans(string s,int k){
        int high=0,low=0,count=0;
        int n = s.size();
        unordered_map<char,int>mp;
        while(high < n){
            mp[s[high]]++;
            while(mp.size() > k){
                mp[s[low]]--;
                if(mp[s[low]] == 0) mp.erase(s[low]);
                low++;
            }
            count += high-low+1;
            high++;
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        return ans(s,3)-ans(s,2);
    }

};