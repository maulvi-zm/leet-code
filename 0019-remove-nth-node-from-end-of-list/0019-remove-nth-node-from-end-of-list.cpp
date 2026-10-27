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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> st;

        auto curr = head;
        while (curr){
            st.push(curr);
            curr = curr->next;
        }

        ListNode* next;
        while (n--){
            auto top = st.top();
            next = top->next;

            st.pop();
        }

        if (st.empty()) return next;

        auto top = st.top();
        top->next = next;

        return head;
    }
};