class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int rank;
public:
    KthLargest(int k, vector<int>& nums) {
        rank = k;
        for(int value : nums){
            pq.push(value);
            if(pq.size() > rank){
                pq.pop();
            }
        }
    }
    int add(int val) {
        pq.push(val);
        if(pq.size() > rank){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */