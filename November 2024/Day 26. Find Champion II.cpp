class Solution {
public:
    void dfs(int src, vector<int> graph[], set<int> &visited){
        visited.insert(src);

        for(int v:graph[src]){
            if(visited.find(v) == visited.end()) 
                dfs(v, graph, visited);
        }
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];

        for(vector<int> edge: edges){
            int u=edge[0], v=edge[1];

            graph[u].push_back(v);
        }

        bool found=false;
        int ans=-1;
        for(int i=0;i<n;i++){
            set<int> visited;
            dfs(i, graph, visited);

            if(visited.size() == n){
                if(found) return -1;
                found=true;
                ans=i;
            }
        }

        return ans;
    }
};