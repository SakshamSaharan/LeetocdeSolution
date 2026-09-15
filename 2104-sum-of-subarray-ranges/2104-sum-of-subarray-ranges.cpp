class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int maxi = nums[i];
            int mini = nums[i];
            for(int j=i;j<n;j++){
                maxi = max(maxi,nums[j]);
                mini = min(mini,nums[j]);
                int range = maxi - mini;
                sum += range;
            }
        }
        return sum;
    }
};