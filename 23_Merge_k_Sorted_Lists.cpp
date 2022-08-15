#include <vector>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode(0), *cur = root;
        priority_queue<int, vector<int>, greater<int>> pq;
        

        for (int i = 0 ; i < lists.size(); i ++ ) {
            ListNode * current_head = lists[i];
            while (current_head) {
                pq.push(current_head->val);
                current_head = current_head->next;
            }
        }


        while (pq.size() > 0) {
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }
        return root->next;
    }
};