class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax[n];
        leftmax[0] = -1;
        for(int i=1;i<n;i++){
            leftmax[i] = max(leftmax[i-1],height[i-1]);
        }
        int rightmax[n];
        rightmax[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            rightmax[i] = max(rightmax[i+1],height[i+1]);
        }
        int maxarea = 0;
        for(int i=0;i<n;i++){
            int currarea = min(leftmax[i],rightmax[i]) - height[i];
            if(currarea > 0){
                maxarea += currarea;
            }
        }
        return maxarea;
    }
};