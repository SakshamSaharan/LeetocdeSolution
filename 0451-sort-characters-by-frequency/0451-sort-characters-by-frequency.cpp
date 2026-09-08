class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // Frequency count
        for (char ch : s) {
            mp[ch]++;
        }

        // Bucket: index = frequency
        vector<vector<char>> bucket(s.size() + 1);

        for (auto &it : mp) {
            bucket[it.second].push_back(it.first);
        }

        // Highest frequency se traverse
        string ans;

        for (int freq = s.size(); freq >= 1; freq--) {
            for (char ch : bucket[freq]) {
                ans.append(freq, ch);
            }
        }

        return ans;
    }
};