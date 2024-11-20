class Solution {
    public:
        int buildAns(string s) {
            int ans = 0;
            for(char ch:s) {
                ans += (ch-'0');
            }
            return ans;
        }
        int getLucky(string s, int k) {
            string ans = "";
            for(char ch:s) {
                int i = ch-'a'+1;
                ans += to_string(i);
            }
            int res;
            for(int i=0;i<k;i++) {
                res = buildAns(ans);
                ans = to_string(res);
            }
            return res;
        }
};
