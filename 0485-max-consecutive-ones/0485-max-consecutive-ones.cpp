class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount=0,currcount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                currcount++;
                maxcount = max(maxcount,currcount);
            }
            else{
                currcount = 0;
            }
        }
        return maxcount;
    }
};