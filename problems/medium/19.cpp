// Number: 19
// Name: Remove Nth Node From End of List
// Tags: Linked List

// O(N) O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curNode = head;
        ListNode* curStartNode = head;
        ListNode* prevNode = nullptr;
        int curPos = 0;
        while (curNode && (1 + curPos != n)) {
            curNode = curNode->next;
            curPos++;
        }
        if (!curNode)
            return head;
        while (curNode->next) {
            curNode = curNode->next;
            prevNode = curStartNode;
            curStartNode = curStartNode->next;
        }
        if (!prevNode) {
            return curStartNode->next;
        }
        prevNode->next = curStartNode->next;
        return head;
    }
};
