class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n = nums.size();
        vector<int>ans(2*n);
        vector<int>temp = nums;
        nums.insert(nums.end(),temp.begin(),temp.end());
        s.push(nums[2*n-1]);
        ans[2*n-1] = -1;
        for(int i=2*n-2;i>=0;i--){
            int curr = nums[i];
            while(! s.empty() && curr >= s.top()){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            } else{
                ans[i] = s.top();
            }
            s.push(nums[i]);
        }
        ans.resize(n);
        return ans;
    }
};