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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* res = nullptr;
        ListNode* tail = head;
        res = tail;
        int prev_val = head->val;
        ListNode* current = head->next;
        while (current != nullptr) {
            if (current->val != prev_val) {
                tail->next = current;
                tail = tail->next;
                prev_val = current->val;
            }
            current = current->next;
        }
        tail->next = nullptr;
        return res;
    }
};