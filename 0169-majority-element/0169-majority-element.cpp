class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it != mp.end();it++){
            if(it->second > n/2) return it->first;
        }
        return nums[0];
    }
};