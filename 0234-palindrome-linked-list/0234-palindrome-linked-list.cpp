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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // At this state slow is in the middle of the linked list, we need to reverse that
        ListNode *prev = nullptr, *curr = slow;
        while (curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        while (head && prev){
            if (head->val != prev->val){
                return false;
            }

            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};