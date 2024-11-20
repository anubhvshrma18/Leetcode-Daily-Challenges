### ***Recursion*** - 

**Test Cases Passed** - 119/142 ❌
**Status**: *Time Limit Exceeded*
```
class Solution {
public:
    vector<int> cnt = {0,0,0};
    
    int solve(string& s, int l, int r, int k, int ste) {
        if(cnt[0]>=k && cnt[1]>=k && cnt[2]>=k) {
            return ste;
        }
        if(l>r) return INT_MAX;
  
        cnt[s[l]-'a']++;
        int left = solve(s, l+1, r, k, ste+1);
        cnt[s[l]-'a']--;
        cnt[s[r]-'a']++;
        int right  = solve(s, l, r-1, k, ste+1);
        cnt[s[r]-'a']--;
        return min(left, right);
    }
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        if(s.length()<3) return -1;
        int ans = solve(s, 0, s.length()-1, k, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
```



### Memoization -

**Test Cases Passed** - 119/142
**Status**: *Memory Limit Exceeded*

```
class Solution {
public:
    vector<int> cnt = {0,0,0};
    vector<vector<int>> dp;
    int solve(string& s, int l, int r, int k, int ste) {
        if(cnt[0]>=k && cnt[1]>=k && cnt[2]>=k) {
            return ste;
        }
        if(l>r) return INT_MAX;
        
        if(dp[l][r]!=INT_MAX) 
            return dp[l][r];
        else {
            cnt[s[l]-'a']++;
            int left = solve(s, l+1, r, k, ste+1);
            cnt[s[l]-'a']--;
            cnt[s[r]-'a']++;
            int right = solve(s, l, r-1, k, ste+1);
            cnt[s[r]-'a']--;
            return dp[l][r] = min(left, right);
        }
    }
    int takeCharacters(string s, int k) {
        dp.resize(s.length(), vector<int> (s.length(), INT_MAX));
        if(k==0) return 0;
        if(s.length()<3) return -1;
        int ans = solve(s, 0, s.length()-1, k, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
```


### Sliding Window

*Runtime: 1 ms, faster than 98.54% of C++ online submissions for Take K of Each Character From Left and Right.
Memory Usage: 12.1 MB, less than 56.21% of C++ online submissions for Take K of Each Character From Left and Right.*

```
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        if(s.length()<3) return -1;
        int i=0,j=0,ans=0,ac=0,bc=0,cc=0,n=s.length();
        for(auto ch:s) {
            if(ch=='a') ac++;
            if(ch=='b') bc++;
            if(ch=='c') cc++;
        }
        if (ac < k || bc < k || cc < k) {
            return -1;
        }
        
        while(j<n) {
            
			// Increase the window for max deletion until it becomes invalid
            while(j<n && ac>=k && bc>=k && cc>=k) {
                if(s[j]=='a') ac--;
                else if(s[j]=='b') bc--;
                else cc--;
                ans=max(ans, j-i);
                j++;
            }
            
			// Release the character to make it valid
            while(i<=j && (ac<k || bc<k || cc<k)) {
                if(s[i]=='a') ac++;
                else if(s[i]=='b') bc++;
                else cc++;
                i++;
            }
            ans=max(ans, j-i);
        }
        return n - ans;
    }
};
```