class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>matrix;
        matrix.push_back({1});
        for(int i=1;i<=rowIndex;i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j=0;j<i-1;j++){
                temp.push_back(matrix[i-1][j] + matrix[i-1][j+1]);
            }
            temp.push_back(1);
            matrix.push_back(temp);
        }
        return matrix[rowIndex];
    }
};