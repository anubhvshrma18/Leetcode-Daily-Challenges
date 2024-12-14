class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
           int op=0;
           int mid=low+(high-low)/2;
           for(auto a:nums)op+=(a-1)/mid;
           if(op>maxOperations)low=mid+1;
           else high=mid-1;
        }
        return low;
    }
};