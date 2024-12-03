class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;  
        int min_v = INT_MAX;
        int neg_count = 0;
    
        for (auto row : matrix) {
            for (int v : row) {
                total += abs(v);
                min_v = min(min_v, abs(v));
                if (v < 0) {
                    neg_count++;
                }
            }
        }
    
        if (neg_count % 2) {
            total -= abs(2 * min_v);
        }
    
        return total;
    }
};