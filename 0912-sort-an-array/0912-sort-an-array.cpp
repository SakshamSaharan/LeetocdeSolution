class Solution {
public:
    void heapify(vector<int>& nums,int i,int n){
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
            swap(nums[i],nums[maxI]);
            heapify(nums,maxI,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = (n/2)-1;i>=0;i--){
            heapify(nums,i,n);
        }

        for(int i =n-1;i>=0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }

        return nums;
    }
};