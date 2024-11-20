class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) { 
            string aS = to_string(a), bS = to_string(b);
            return aS+bS > bS+aS;
        });
        string ans="";
        for(auto a:nums) {
            ans += to_string(a);
        }
        return ans[0]=='0' ? "0" : ans;
    }
};