class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=0,zeroes=0,maxlength=0;
        int n = nums.size();
        while(high < n){
            if(nums[high] == 0){
                zeroes++;
            }
            if(zeroes > k){
                if(nums[low] == 0){
                    zeroes--;
                }
                low++;
            }
            int length = high-low+1;
            maxlength = max(maxlength,length);
            high++;
        }
        return maxlength;
    }
};