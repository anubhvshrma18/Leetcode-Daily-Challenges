class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> arr(26, 0);
        for(char ch:allowed) {
            arr[ch-'a']++;
        }
        int ans = 0;
        for(string s:words) {
            int cnt = 0;
            for(char ch:s) {
                if(arr[ch-'a'] == 0) {
                    cnt=1;
                    break;
                }
            }
            ans += cnt==0;
        }
        return ans;
    }
};
