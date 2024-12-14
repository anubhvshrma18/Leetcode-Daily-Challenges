class Solution {
public:
    int maximumLength(string s) {
        int N = s.length();
        for(int i = N-2; i>=1; i--) {
            for(char c = 'a'; c<='z'; c++) {
                int cnt = 0;
                for(int j = 0; j<=N-i; j++) {
                    if(s[j] != c) continue;
                    string str = s.substr(j, i);
                    if(str == string(i, c)) {
                        cnt++;
                    }
                }
                if(cnt>=3)
                    return i;
            }
        }
        return -1;
    }
};