/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        auto curr = head;
        while (curr) {
            if (mp.count(curr) == 0) {
                mp[curr] = new Node(curr->val);
            }

            if (curr->next && mp.count(curr->next) == 0) {
                mp[curr->next] = new Node(curr->next->val);
            }

            if (curr->random && mp.count(curr->random) == 0) {
                mp[curr->random] = new Node(curr->random->val);
            }

            if (curr->next){
                mp[curr]->next = mp[curr->next];
            }

            if (curr->random){
                mp[curr]->random = mp[curr->random];
            }

            curr = curr->next;
        }

        return mp[head];
    }
};
