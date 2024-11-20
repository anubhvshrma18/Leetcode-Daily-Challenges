class Solution {
public:
    void solve(int currNum, int n, vector<int>& res) {
        if(currNum > n) return;
        res.push_back(currNum);
        for(int i=0;i<=9;i++) {
            int num = currNum*10 + i;
            if(num <= n) {
                solve(num,n,res);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++) {
            solve(i,n,res);
        }
        return res;
    }
};