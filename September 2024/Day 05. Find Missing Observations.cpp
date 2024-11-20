class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long totalNum = n+m;
        long totalSum = mean*totalNum;
        long diff = totalSum - accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> ans;
        if(diff > 6*n || diff < 1*n) return ans;
        long fv = diff/n;
        if(fv < 1 || fv > 6){
            return ans;
        }
        long ps = 0;
        for(int i=0;i<n;i++){
            ps+=diff/(n-i);
            ans.push_back(diff/(n-i));
            diff-= diff/(n-i);
        }
        return ans;
    }
};
