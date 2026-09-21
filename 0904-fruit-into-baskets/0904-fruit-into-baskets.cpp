class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0,high = 0,maxlength = 0;
        unordered_map<int,int>mp;
        int n = fruits.size();
        while(high < n){
            mp[fruits[high]]++;
            while(mp.size() > 2){
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0) mp.erase(fruits[low]);
                low++;
            }
            maxlength = max(maxlength,high-low+1);
            high++;
        }
        return maxlength;
    }
};