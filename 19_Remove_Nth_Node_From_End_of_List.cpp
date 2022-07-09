#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( n == 0) {
            return head;
        }
        ListNode* temp=head;

        int length = 0;
        while (temp != NULL ) {
            temp = temp->next;
            length ++;
        }
        if (length == n) {
            return head->next;
        }
        temp=head;
        int counter = 0;
        while ( counter < length - n - 1) {
            temp = temp->next;
            counter ++;
        }
        ListNode* next1=temp->next;
        temp->next=temp->next->next;
                
        return head;
    }
};