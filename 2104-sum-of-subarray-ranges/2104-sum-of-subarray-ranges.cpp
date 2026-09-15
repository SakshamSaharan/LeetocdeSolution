class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>s;
        int n = nums.size(); 
        vector<int>nse(n,n);
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            int curr = nums[i];
            while(! s.empty() && curr < nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = s.top();
            }
            s.push(i);
        }
        while(! s.empty()){
            s.pop();
        }
        vector<int>pse(n,-1);
        s.push(0);
        for(int i=1;i<n;i++){
            int curr = nums[i];
            while(! s.empty() && curr <= nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = s.top();
            }
            s.push(i);
        }
        long long minsum = 0;
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left*right;
            long long val = freq*nums[i];
            minsum += val;
        }
        while(! s.empty()){
            s.pop();
        }
        vector<int>nge(n,n);
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            int curr = nums[i];
            while(! s.empty() && curr > nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nge[i] = n;
            }
            else{
                nge[i] = s.top();
            }
            s.push(i);
        }
        while(! s.empty()){
            s.pop();
        }
        vector<int>pge(n,-1);
        s.push(0);
        for(int i=1;i<n;i++){
            int curr = nums[i];
            while(! s.empty() && curr >= nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                pge[i] = -1;
            }
            else{
                pge[i] = s.top();
            }
            s.push(i);
        }
        long long maxsum = 0;
        for(int i=0;i<n;i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            long long freq = left*right;
            long long val = freq*nums[i];
            maxsum += val;
        }
        return maxsum-minsum;
    }
};