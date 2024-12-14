class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> v(2*1e5+10);
        int x,y;
        for(auto &i: nums){
            x = 0,y=i-k;
            v[max(x,y)]++;
            x = 2*1e5+1,y=i+k+1;
            v[min(x,y)]--;
        }
        int ans = v[0];
        for(int i = 1; i <= 2*1e5; i++){
            v[i] += v[i-1];
            ans = max(ans,v[i]);
        }
        return ans;
    }
};