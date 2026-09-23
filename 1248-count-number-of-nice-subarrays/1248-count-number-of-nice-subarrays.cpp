class Solution {
public:
    int oddcount(vector<int>nums,int k){
        int high = 0,low = 0,count = 0,oddcount = 0;
        int n = nums.size();
        if(k < 0) return 0;
        while(high < n){
            if(nums[high]%2 != 0) oddcount++;
            while(oddcount > k){
                if(nums[low]%2 != 0) oddcount--;
                low++;
            }
            count += high-low+1;
            high++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return oddcount(nums,k) - oddcount(nums,k-1);
    }
};