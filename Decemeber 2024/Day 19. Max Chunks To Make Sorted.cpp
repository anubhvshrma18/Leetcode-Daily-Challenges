class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i=0,sum=0,cnt=0,n=arr.size(),s=0;
        while(i<n){
            sum+=i;
            s+=arr[i];
            if(sum==s) {
                cnt++;
            };
            i++;
        }
        return cnt;
    }
};