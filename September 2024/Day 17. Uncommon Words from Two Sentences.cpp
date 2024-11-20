class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        stringstream ss(s1+" "+s2);
        string word;
        while(ss>>word) {
            mp[word]++;
        }
        for(auto a:mp) {
            if(a.second==1) {
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};