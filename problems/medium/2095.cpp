// Number: 2095
// Name: Delete the Middle Node of a Linked List
// Tags: Linked List

// O(N) O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head) return head;
        if (!head->next) return nullptr;
        ListNode* slowPointer = head;
        ListNode* prevNode = nullptr;
        ListNode* fastPointer = head;
        while (fastPointer && fastPointer->next) {
            prevNode = slowPointer;
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        prevNode->next = slowPointer->next;
        return head;
    }
};
