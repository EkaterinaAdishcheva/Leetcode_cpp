#include <utility>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// based on quick sort

class Solution {
private:
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* temp = nullptr;
        while( list1!= nullptr && list2!= nullptr ) {
            if (list1->val > list2->val) {
                if (head == nullptr) {
                    head = list2;
                    temp = list2;
                } else {
                    temp = list2;
                }
                list2 = list2->next;
            } else {
                if (head == nullptr) {
                    head = list1;
                    temp = list1;
                } else {
                    temp = list1;
                }
                list1 = list1->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr) {
            temp = list1;
        }
        if (list2 != nullptr) {
            temp = list2;
        }
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {return head;}
        if (head->next == nullptr) {return head;}

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        
        while(fast != nullptr && fast -> next != nullptr) {

            fast = fast->next->next;
            temp = slow;
            slow = slow->next;
        }

        temp->next = nullptr;
        
        ListNode* l1= sortList(head);
        ListNode* l2= sortList(slow);

        ListNode* res = mergeLists(l1, l2);

        return res;
    }
};