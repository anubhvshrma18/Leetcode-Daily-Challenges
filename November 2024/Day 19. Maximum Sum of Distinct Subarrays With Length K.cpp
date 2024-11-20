class Solution {
public:
    long long maximumSubarraySum(vector<int>& N, int k) {
        int n = N.size();
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp;
        int i = 0;
        while(i < k  && i < n){
            mp[N[i]]++;
            sum += N[i];
            i++;
        }
        if(mp.size() == k) ans = sum;
        while(i < n){
            mp[N[i]]++;
            mp[N[i-k]]--;
            if(mp[N[i-k]] == 0) mp.erase(N[i-k]);
            
            sum += N[i];
            sum -= N[i-k];
            if(mp.size() == k) ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};