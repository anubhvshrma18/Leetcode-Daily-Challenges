// Leetcode Link - https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans=0;
        for(int i=0;i<m;i++) {
            int cnt = 0;
            vector<int> v(n);
            for(int j=0;j<n;j++) 
                v[j] = matrix[i][j] == 0 ? 1: 0;
            for(int k=i;k<m;k++) {
                if(matrix[k] == matrix[i] || matrix[k] == v) 
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};