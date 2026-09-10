class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        }
        for(int i=0;i<nums1.size();i++){
            auto it = mp.find(nums1[i]);
            int j = it->second;
            nums1[i] = -1;
            for(int k = j+1;k<nums2.size();k++){
                if(nums2[k] > it->first){
                    nums1[i] = nums2[k];
                    break;
                }
            }
        }
        return nums1;
    }
};