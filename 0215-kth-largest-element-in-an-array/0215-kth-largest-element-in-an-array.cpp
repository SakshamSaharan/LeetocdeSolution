class Solution {
public:
    void heapify(vector<int>& nums,int i,int n){
        if(i > n) return;

        int l = 2*i+1;
        int r = 2*i+2;
        int maxI = i;

        if(l < n && nums[l] > nums[maxI]){
            maxI = l;
        }
        if(r < n && nums[r] > nums[maxI]){
            maxI = r;
        }
        if(maxI != i){
            swap(nums[maxI],nums[i]);
            heapify(nums,maxI,n);
        }
    }
    void heapsort(vector<int>& nums){
        int n = nums.size();
        for(int i = (n/2)-1;i>=0;i--){
            heapify(nums,i,n);
        }
        for(int i=n-1;i>=0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        heapsort(nums);
        return nums[nums.size()-k];
    }
};