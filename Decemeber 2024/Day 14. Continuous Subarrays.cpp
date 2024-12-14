class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        deque<int> q1,q2;
        int i=0,j=0;
        while(j<nums.size()) {
            if(q1.empty()) {
                q1.push_back(nums[j]);
            }
            else {
                while(q1.size()!=0 && q1.back()<nums[j]) {
                    q1.pop_back();
                }
                q1.push_back(nums[j]);
            }
            if(q2.empty()){
                q2.push_back(nums[j]);
            }
            else{
                while(q2.size()!=0 && q2.back()>nums[j]) {
                    q2.pop_back();
                }
                q2.push_back(nums[j]);
            }
            if(abs(q1.front()-q2.front())<=2){
                ans+=j-i+1;
                j++;
            }
            else if(abs(q1.front()-q2.front())>2) {
                while(abs(q1.front()-q2.front())>2) {
                    if(nums[i]==q1.front()){
                        q1.pop_front();
                    }
                    if(nums[i]==q2.front()) {
                        q2.pop_front();
                    }
                    i++;
                }
                ans+=(j-i+1);
                j++;
            }
        }
        return ans;
    }
};