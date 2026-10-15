class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int finalans = 0;
        set<int>st;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                int x = st.size();
                finalans += x*x;
            }
            st.clear();
        }
        return finalans;
    }
};