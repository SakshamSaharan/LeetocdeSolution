class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum =0;
        int n = arr.size();
        long long mod = 1e9+7;
        stack<int>s;
        s.push(n-1);
        vector<int>nse(n,n);
        for(int i=n-2;i>=0;i--){
            int curr = arr[i];
            while(! s.empty() && arr[s.top()] > curr){
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
        vector<int>psee(n,-1);
        s.push(0);
        for(int i=1;i<n;i++){
            int curr = arr[i];
            while(! s.empty() && arr[s.top()] >= curr){
                s.pop();
            }
            if(s.empty()){
                psee[i] = -1;
            }
            else{
                psee[i] = s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long freq  = (left*right)%mod;
            long long value = (freq*arr[i])%mod;
            sum = (sum + value)%mod;
        }
        return sum;
    }
};