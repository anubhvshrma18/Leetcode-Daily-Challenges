class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n,-1);
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({max(queries[i][0],queries[i][1]),i});
        }
        
        sort(v.begin(),v.end());
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int j=0;
        
        for(int i=0;i<heights.size();i++){
            
            while( j<n && v[j].first <= i ){
                int ind = v[j].second;
                
                if( heights[ max(queries[ind][0],queries[ind][1]) ] > heights[ min(queries[ind][0],queries[ind][1]) ] ) 
                    ans[ind] = i;
                else if( queries[ind][0]==queries[ind][1] ) 
                    ans[ind] = i;
                else
                pq.push({ max(heights[queries[ind][0]],heights[queries[ind][1]]) , ind});
                
                j++;
            }
            
            while( pq.size() && pq.top().first < heights[i] ){
                ans[pq.top().second] = i;
                pq.pop();
            }
            
        }
        
        return ans;
    }
};