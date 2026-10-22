class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int cand;
        for(int x : nums){
            if(count == 0){
                cand = x;
                count = 1;
            }
            else if(x == cand){
                count++;
            }
            else{
                count--;
            }
        }
        return cand;
    }
};