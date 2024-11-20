class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int ps = 0,n=arr.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ps^=arr[i];
            ans[i]=ps;
        }
        vector<int> t(queries.size());
        for(int i=0;i<queries.size();i++) {
            int l=queries[i][0],r=queries[i][1];
            t[i] = (ans[r]^arr[l])^(ans[l]);
        }
        return t;
    }
};
