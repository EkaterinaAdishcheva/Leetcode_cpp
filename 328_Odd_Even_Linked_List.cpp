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
    pair<ListNode*, ListNode*> partition(ListNode* head, ListNode* bigNodes) {
        if ( head == nullptr ) {
            return make_pair(nullptr, nullptr);
        }
        
        auto pivot = head->val;
        auto current = head;
        auto previous = head;

        ListNode* smallNodes = nullptr;
        ListNode* smallNodes_head = nullptr;

        while ( current != nullptr && current != bigNodes ) {
            if ( current->val < pivot )
            {
                if (smallNodes_head == nullptr) {
                    smallNodes_head = current;
                    smallNodes = smallNodes_head;
                } else {
                    smallNodes->next = current;
                    smallNodes = smallNodes->next;
                }
                previous->next = current->next;    
            } else {
                previous = current;            
            }
            current = current->next;
        }
        previous->next = bigNodes; 
        ListNode* current_print = smallNodes;
        cout << "partition" << "\n";
        while(current_print) {
            cout << current_print->val << "\t";
            current_print = current_print->next;
        }
        smallNodes->next = head;
        cout << "partition" << "\n";
        while(current_print) {
            cout << current_print->val << "\t";
            current_print = current_print->next;
        } 
        
        return make_pair(nullptr, nullptr);
    }

    void quickSort(ListNode* smallNodes, ListNode* bigNodes) {
        if ( smallNodes != nullptr || bigNodes != nullptr ) {
        ListNoder* pivot = partition(smallNodes, bigNodes);
            quickSort(smallNodes, pivot[0]]);
            quickSort(pivot[1]->next, bigNodes);
        }        
    }

    ListNode* sortList(ListNode* head) {
        quickSort(head, nullptr);
        return head;
    }
};


int main()
{
    auto head = new ListNode(2, new ListNode(1, new ListNode(4, new ListNode(3))));
    Solution solution;
    ListNode* res = solution.sortList(head);

    ListNode* current = head;
    while(current) {
        cout << current->val << "\t";
        current = current->next;
    } 
}