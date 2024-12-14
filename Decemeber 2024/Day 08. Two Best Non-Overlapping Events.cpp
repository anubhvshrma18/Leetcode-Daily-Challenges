class Solution {
public:
    int nextNonConflictingEvent(vector<vector<int>>& events, int l, int r, int end){
        while(l<r){
            int m = l+(r-l)/2;
            
            if(events[m][0] > end){
                r=m;
            }else{
                l=m+1;
            }
        }
        
        return (events[l][0] > end ? l:-1);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int n=events.size();
        vector<int> single(n,0), pair(n,0);
        single[n-1] = pair[n-1] = events[n-1][2];
        
        int ans = events[n-1][2];
        
        for(int i=n-2;i>=0;i--){
            single[i] = max(events[i][2], single[i+1]);
            int idx = nextNonConflictingEvent(events, i+1, n-1, events[i][1]);
            pair[i] = events[i][2] + (idx != -1 ? single[idx]:0);
            
            ans = max(ans, max(single[i], pair[i]));
        }
        
        return ans;
    }
};