class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(auto a:obstacles) {
            st.insert(to_string(a[0])+"#"+to_string(a[1]));
        }
        int n = commands.size(), dir = 0, ans = 0, currX = 0, currY = 0;
        for(int i=0;i<n;i++) {
            if(commands[i]==-1) {
                dir = (dir+5)%4;
                continue;
            }
            else if(commands[i]==-2) {
                dir = (dir+3)%4;
                continue;
            } else {
                int k =0;
                while(k<commands[i]) {
                    if(dir == 0 && st.find(to_string(currX)+"#"+to_string(currY+1)) == st.end()) {
                        currY += 1;
                    } else if(dir == 1 && st.find(to_string(currX+1)+"#"+to_string(currY)) == st.end()) {
                        currX += 1;
                    } else if(dir == 2 && st.find(to_string(currX)+"#"+to_string(currY-1)) == st.end()) {
                        currY -= 1;
                    } else if(dir == 3 && st.find(to_string(currX-1)+"#"+to_string(currY)) == st.end()) {
                        currX -= 1;
                    }
                    k++;
                    cout << currX << " " << currY << " " << dir << endl;
                }
            }
            ans = max(ans, currX*currX + currY*currY);
        }
        return ans;
    }
};
