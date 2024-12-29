class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int score=INT_MIN,n=values.size();
        int maxLeft = values[0];
        
        for(int i=1;i<n;i++){ 
            score=max(score,maxLeft+values[i]-i);
            maxLeft = max(maxLeft,values[i]+i);
        }
        
        return score;
    }
};