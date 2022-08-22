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
    ListNode* reverseList(ListNode* head) {
        ListNode* res = nullptr;
        ListNode* current = head;
        ListNode* tail = nullptr;
        int steps = -1;
        while (current != nullptr ) {
            tail = current; 
            current = current->next;
            steps ++;
        }
        res = tail;
        tail = res;
        for (int i = steps - 1; i >= 0; i --) {
            current = head;
            for (int j = 0 ; j < i ; j ++ ) {
                current = current->next; 
            }
            tail->next = current;
        }
        return res;
    }
};