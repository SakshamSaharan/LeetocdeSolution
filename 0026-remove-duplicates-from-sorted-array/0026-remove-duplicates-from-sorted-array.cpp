class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[j-1]){
                swap(nums[i],nums[j++]);
                cnt++;
            }
        }
        return cnt;
    }
};