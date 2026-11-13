class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>matrix;
        matrix.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>store;
            store.push_back(1);
            for(int j=1;j<matrix[i-1].size();j++){
                store.push_back(matrix[i-1][j-1] + matrix[i-1][j]);  
            }
            store.push_back(1);
            matrix.push_back(store);
        }
        return matrix;
    }
};