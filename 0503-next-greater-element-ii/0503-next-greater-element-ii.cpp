class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int j = (i+1)%n;
            ans[i] = -1;
            while(j != i){
                if(nums[j] > nums[i]){
                    ans[i] = nums[j];
                    break;
                } else{
                    j = (j+1)%n;
                }
            }
        }
        return ans;
    }
};