class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0,high = 0;
        int maxlength = -1;
        int frequency[26] = {0};
        int n = s.size();
        int maxfreq = 0;
        while(high < n){
            frequency[s[high] - 'A']++;
            maxfreq = max(maxfreq,frequency[s[high] - 'A']);
            while((high-low+1) - maxfreq > k){
            frequency[s[low] - 'A']--;
            low++;
            }
        maxlength = max(maxlength,high-low+1);
        high++;
        }
    return maxlength;
    }
};