class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int digit = nums[i];
            int sum = 0;
            while(digit > 0){
                int x = digit%10;
                sum+=x;
                digit/=10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};