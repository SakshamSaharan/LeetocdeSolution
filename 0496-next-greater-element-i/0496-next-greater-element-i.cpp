class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        int n2 = nums2.size();
        s.push(n2-1);
        int ans[n2];
        ans[n2-1] = -1;
        for(int i = n2-2;i>=0;i--){
            int curr = nums2[i];
            while(! s.empty() && curr > nums2[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            } else{
                ans[i] = nums2[s.top()];
            }
            s.push(i);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n2;i++){
            mp[nums2[i]] = ans[i];
        }
        for(int i=0;i<nums1.size();i++){
            auto it = mp.find(nums1[i]);
            nums1[i] = it->second;
        }
        return nums1;
    }
};