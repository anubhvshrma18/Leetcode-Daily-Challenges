class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=0,count=0,maxcount=0;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(mx==nums[i]){
                count++;
            }
            else{
                maxcount=max(maxcount,count);
                count=0;
            }
        }
        maxcount=max(maxcount,count);
        if(maxcount==0){return 1;}
        return maxcount;
    }
};