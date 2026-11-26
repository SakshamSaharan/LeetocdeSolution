class Solution {
public:
    bool canAliceWin(int n) {
        int z = 10;
        bool ans = false;
        while(n >= z){
            ans = !ans;
            n-=z;
            z--;
        }
        return ans;
    }
};