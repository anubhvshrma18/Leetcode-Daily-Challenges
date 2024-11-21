class Solution {
public:
    void marker(vector<vector<int>>& grid, int i, int j, string dir) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==-1 || grid[i][j]==1) return;
        
        grid[i][j]=2;
        if(dir == "T") {
            marker(grid, i-1, j, "T");
        } else if(dir == "L") {
            marker(grid, i, j-1, "L");
        } else if(dir == "D") {
            marker(grid, i+1, j, "D");
        } else {
            marker(grid, i, j+1, "R");
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,0));
        
        for(auto a:walls) {
            grid[a[0]][a[1]]=-1;
        }
        for(auto a:guards) {
            grid[a[0]][a[1]]=1;
        }
        
        for(auto a:guards) {
            marker(grid, a[0]-1, a[1], "T");
            marker(grid, a[0], a[1]-1, "L");
            marker(grid, a[0]+1, a[1], "D");
            marker(grid, a[0], a[1]+1, "R");
        }
        
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) ans++;
            }
        }
        return ans;
    }
};