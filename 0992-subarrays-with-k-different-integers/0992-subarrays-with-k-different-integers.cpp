class Solution {
public:
    int atmost(vector<int>nums,int k){
        int high = 0,low = 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>mp;
        while(high < n){
            mp[nums[high]]++;
            while(mp.size() > k){
                mp[nums[low]]--;
                if(mp[nums[low]] == 0) mp.erase(nums[low]);
                low++;
            }
            count += high-low+1;
            high++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};