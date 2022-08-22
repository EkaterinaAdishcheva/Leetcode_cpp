/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = nullptr;
        ListNode* current = head;
        ListNode* tail = nullptr;
        while(current != nullptr) {
            if (current->val != val) {
                if (res == nullptr) {
                    res = current;
                    tail = current;
                } else {
                    tail->next = current;
                    tail = current;
                }
            } 
            current = current->next; 
        }
        if (tail != nullptr) {
            tail->next = nullptr;        
        }
        return res;
    }
};