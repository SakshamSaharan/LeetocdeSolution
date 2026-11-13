class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxF = 0;
        int maxE = 0;
        for(auto it = mp.begin();it != mp.end();it++){
            if(it->second > maxF){
                maxF = it->second;
                maxE = it->first;
            }
        }
        return maxE;
    }
};