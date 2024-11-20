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
    int gcd(int a, int b) {
        if(a>b) swap(a,b);
        if(b%a == 0) return a;
        return gcd(b%a, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp) {
            if(temp->next) {
                int vl = gcd(temp->val, temp->next->val);
                ListNode* newNode = new ListNode(vl);
                ListNode* nex = temp->next;
                temp->next=newNode;
                newNode->next=nex;
                temp=temp->next;
            }
            temp = temp->next;
        }
        return head;
    }
};
