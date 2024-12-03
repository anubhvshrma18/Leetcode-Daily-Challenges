class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(auto a:arr) {
            if(st.count(2*a)!=0 || (a%2==0 && st.count(a/2)!=0)) return true;
            st.insert(a);
        }
        return false;
    }
};