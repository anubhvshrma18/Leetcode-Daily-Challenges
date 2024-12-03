class Solution {
public:
    int dijikstra(int &n, vector<vector<int>> roads){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        pq.push({ 0, 0 });
        dist[0] = 0;
        while(!pq.empty()){
            auto [distance, node] = pq.top();
            pq.pop(); 
            for(auto adjRoad : roads[node]){
                if(1 + distance < dist[adjRoad]){
                    dist[adjRoad] = 1 + distance;
                    pq.push({ 1 + distance,  adjRoad });
                }
            }
        }
        return dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> roads(n);
        for(int i=0;i<n-1;i++){
            roads[i].push_back(i+1);
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            roads[u].push_back(v);
            ans[i] = dijikstra(n, roads);
        }
        return ans;
    }
};