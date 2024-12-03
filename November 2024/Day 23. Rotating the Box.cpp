class Solution {
public:
    vector<vector<char>> rotate(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<char>> rotated(m, vector<char>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                rotated[j][i] = matrix[i][j];
            }
        }

        for(int i=0;i<m;i++) {
            int j=0,k=n-1;
            while(j<k) {
                char tmp = rotated[i][j];
                rotated[i][j] = rotated[i][k];
                rotated[i][k] = tmp;
                j++;
                k--;
            }
        }

        return rotated;

    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> rot = rotate(box);
        int n = rot.size(),m=rot[0].size();
        
        for(int i=0;i<m;i++) {
            int j=0;
            while(j<n){
                if(rot[j][i]=='.' or rot[j][i]=='*'){
                    j++;
                    continue;
                }
                int k = j+1;
                while(k<n and rot[k][i]=='#') {
                    k++;
                }
                
                if(k<n and rot[k][i]=='.'){
                    swap(rot[j][i],rot[k][i]);
                }
                else{
                    j=k+1;
                }
            }
        }

        return rot;
    }
};