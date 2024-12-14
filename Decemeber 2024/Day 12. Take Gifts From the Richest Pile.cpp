class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> maxHeap;
        for(auto n: gifts) maxHeap.push(n);
        while(k--){ maxHeap.push(sqrt(maxHeap.top())); maxHeap.pop(); }
        while(maxHeap.size() > 0){ ans+= maxHeap.top(); maxHeap.pop(); }
        return ans;
    }
};