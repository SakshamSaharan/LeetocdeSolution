class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[j]){
                continue;
            }
            else{
                swap(nums[i],nums[j+1]);
                j++;
                count++;
            }
        }
        return count;
    }
};