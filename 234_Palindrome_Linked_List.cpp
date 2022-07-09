#include <iostream>
#include <string>
#include <vector>

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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> nodes_val;

        while ( temp != NULL ) {
            nodes_val.push_back( temp->val );
            temp = temp->next;
        }
        for (size_t i = 0; i < nodes_val.size() / 2; i ++)
        {
            if ( nodes_val[i] != nodes_val[nodes_val.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};