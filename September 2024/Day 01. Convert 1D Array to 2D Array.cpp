class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int idx=0;
        if(m*n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n,-1));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans[i][j]=original[idx++];
            }
        }
        return ans;
    }
};
