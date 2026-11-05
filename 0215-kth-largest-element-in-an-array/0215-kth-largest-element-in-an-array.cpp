class Solution {
public:
    void heapify(vector<int>& nums,int i){
        if(i > nums.size()) return;

        int l = 2*i+1;
        int r = 2*i+2;
        int maxI = i;

        if(l < nums.size() && nums[l] > nums[maxI]){
            maxI = l;
        }
        if(r < nums.size() && nums[r] > nums[maxI]){
            maxI = r;
        }

        if(maxI != i){
            swap(nums[i],nums[maxI]);
            heapify(nums,maxI);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = (n/2)-1;i>=0;i--){
            heapify(nums,i);
        }
        int cnt = 1;
        while(cnt < k){
            swap(nums[0],nums[nums.size()-1]);
            nums.pop_back();
            heapify(nums,0);
            cnt++;
        }
        return nums[0];
    }
};