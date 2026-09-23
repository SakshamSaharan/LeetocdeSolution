class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int low = 0,high = 0;
        int count1 = 0,sum = 0,count2 = 0;
        int n = nums.size();
        while(high < n){
            if(goal < 0) break;
            sum += nums[high];
            while(sum > goal){
                sum -= nums[low];
                low++;
            }
            count1 += high-low+1;
            high++;
        }
        low = 0;
        sum = 0;
        high = 0;
        goal--;
        while(high < n){
            if(goal < 0) break;
            sum += nums[high];
            while(sum > goal){
                sum -= nums[low];
                low++;
            }
            count2 += high-low+1;
            high++;
        }
        return count1-count2;
    }
};