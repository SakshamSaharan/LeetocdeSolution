class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum1 = 0,sum2 = 0;
        int n = cardPoints.size();
        int i=0,j=n-1;
        int x = n-k;
        while(k > 0){
            sum1 += cardPoints[i];
            sum2 += cardPoints[j];
            i++;
            j--;
            k--;
        }
        i = 0;
        int sum3 = sum2;
        int maxsum = sum2;
        while(x < n){
            sum3 = sum3 + cardPoints[i] - cardPoints[x];
            maxsum = max(maxsum,sum3);
            i++;
            x++;
        }
        maxsum = max(maxsum,sum1);
        return maxsum;
    }
};