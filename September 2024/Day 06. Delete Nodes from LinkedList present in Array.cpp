/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto a:nums) {
            st.insert(a);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        dummy->next = head;
        while(temp->next!=NULL) {
                if(st.find(temp->next->val)!=st.end()) {
                    temp->next=temp->next->next;
                } else {
                    temp=temp->next;
                }
        }
        return dummy->next;
    }
};
