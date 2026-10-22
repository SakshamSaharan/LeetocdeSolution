class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0,count2 = 0;
        int cand1=0,cand2=0;
        for(int x : nums){
            if(count1 > 0 && x == cand1){
                count1++;
            }
            else if(count2 > 0 && x == cand2){
                count2++;
            }
            else if(count1 == 0){
                cand1 = x;
                count1 = 1;
            }
            else if(count2 == 0){
                cand2 = x;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        int n = nums.size();
        vector<int>ans;
        for(int x : nums){
            if(x == cand1) count1++;
            if(x == cand2) count2++;
        }
        if(count1 > n/3) ans.push_back(cand1);
        if(count2 > n/3 && cand2 != cand1) ans.push_back(cand2);

        return ans;
    }
};