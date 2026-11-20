class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int i = 1;
        for(int j=0;j<temp.size();j++){
            if(mp.find(temp[j]) == mp.end()){
                mp[temp[j]] = i++;
            }
        }
        for(int j = 0;j<arr.size();j++){
            arr[j] = mp[arr[j]];
        }
        return arr;
    }
};