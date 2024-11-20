class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0, mask = 0;
        map<int, int> mp;
        mp[0] = -1;
        string vowels = "aeiou";
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    mask = mask ^ (1 << j);
                    break;
                }
            }
            if (mp.find(mask) == mp.end())
                mp[mask] = i;
            res = max(res, i - mp[mask]);
        }
        return res;
    }
};