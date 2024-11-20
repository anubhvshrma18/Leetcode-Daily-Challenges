class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int vl : arr1) {
            while(!st.count(vl) && vl > 0) {
                st.insert(vl);
                vl = vl/10;
            }
        }
        int ans = 0;
        for(int num : arr2) {
            while(!st.count(num) && num > 0) {
                num /= 10;
            }
            if(num > 0) {
                ans = max(ans, (int)(log10(num)) + 1);
            }
        }
        return ans;
    }
};