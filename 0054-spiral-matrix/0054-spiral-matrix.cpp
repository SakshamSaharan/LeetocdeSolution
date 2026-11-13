class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0,scol = 0;
        int erow = m-1,ecol = n-1;
        vector<int>ans;
        while(srow <= erow && scol <= ecol){
            // left to right
            for(int i=scol;i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
            }
            // top to bottom 
            for(int i=srow+1;i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
            }
            // right to left
            for(int i=ecol-1;i>=scol;i--){
                if(srow == erow) break;
                ans.push_back(matrix[erow][i]);
            }
            // bottom to top
            for(int i=erow-1;i>srow;i--){
                if(scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }
            srow++;
            scol++;
            erow--;
            ecol--;
        }
        return ans;
    }
};