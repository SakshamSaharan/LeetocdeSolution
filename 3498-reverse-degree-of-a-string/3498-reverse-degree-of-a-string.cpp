class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int i=0,j=1;
        while(i < s.size()){
            int prod = ('a'-s[i]+26)*j;
            sum+=prod;
            i++;
            j++;
        }

        return sum;
    }
};