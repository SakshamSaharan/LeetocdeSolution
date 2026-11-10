class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        vector<int>res;
        for(int i=k;i<nums.size();i++){
            res.push_back(pq.top().first);
            while(! pq.empty() && pq.top().second <= i-k){
                pq.pop();
            }
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);
        return res;
    }
};