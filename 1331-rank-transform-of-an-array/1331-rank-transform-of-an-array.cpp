class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int i = 1;
        while(! pq.empty()){
            if(mp.find(pq.top()) == mp.end()){
                mp[pq.top()] = i++;
            }
            pq.pop();
        }
        for(int j = 0;j<arr.size();j++){
            arr[j] = mp[arr[j]];
        }
        return arr;
    }
};