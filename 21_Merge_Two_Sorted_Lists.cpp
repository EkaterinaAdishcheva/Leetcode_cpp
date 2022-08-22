/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
 var mergeTwoLists = function(list1, list2) {
    let current1 = list1;
    let current2 = list2;
    let list = new ListNode();
    let current = list;
    
    while(current1 || current2) {
        if (current1 === null) {
            current.next = current2;
            break;
        }
        if (current2 === null) {
            current.next = current1;
            break;
        }
        if (current2.val > current1.val) {
            current.next = current1;
            current1 = current1.next;
        } else {
            current.next = current2;
            current2 = current2.next;
        }
        current = current.next;
    }
    return list.next;
};