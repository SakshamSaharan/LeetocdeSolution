class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,cand=0;
        for(int val : nums){
            if(count == 0){
                cand = val;
                count = 1;
            }
            else if(val == cand){
                count++;
            }
            else{
                count--;
            }
        }
        return cand;
    }
};