class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(mp.size() > 0){
            int n = ans.size();
        for(auto it=mp.begin();it!=mp.end();){
            ans.push_back(it->first);
            it->second--;
            if(it->second == 0){
               it =  mp.erase(it);
            } 
            else{
                it++;
            }
        }
        sort(ans.begin()+n,ans.end());
        }
        return ans;
    }
};