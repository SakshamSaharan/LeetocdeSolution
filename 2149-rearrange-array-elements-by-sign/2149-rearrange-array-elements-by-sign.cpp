class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0,neg = 0;
        int n = nums.size();
        vector<int>ans;
        while(pos < n && neg < n){
            while(nums[pos] < 0){
                pos++;
            }
            ans.push_back(nums[pos]);
            pos++;
            while(nums[neg] > 0){
                neg++;
            }
            ans.push_back(nums[neg]);
            neg++;
        }
        return ans;
    }
};