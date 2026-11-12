class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();i++){
            if(! mp.count(nums1[i])) mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if( mp.count(nums2[i])) mp[nums2[i]]++;
        }
        vector<int>ans;
        for(auto it = mp.begin();it != mp.end();it++){
            if(it->second > 1){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};