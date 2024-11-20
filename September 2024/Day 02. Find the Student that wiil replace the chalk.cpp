class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0, n=chalk.size();
        for(auto a:chalk) {
            sum += a;
        }
        k=k%sum;
        for(int i=0;i<n;i++) {
            if(k-chalk[i]<0) {
                return i;
            }
            k-=chalk[i];
        }
        return 0;
    }
};
