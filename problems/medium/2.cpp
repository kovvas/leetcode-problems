// Number: 2
// Name: Add Two Numbers
// Tags: linked list

// don't use new memory
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_head = l1;
        int extra = 0;
        ListNode* l1_prev = nullptr;
        while (l1 && l2) {
            l1->val = l1->val + l2->val + extra;
            extra = l1->val / 10;
            l1->val = l1->val % 10;
            l1_prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            l1_prev->next = l2;
            l1 = l2;
        }
        while (l1) {
            l1->val = l1->val + extra;
            extra = l1->val / 10;
            l1->val = l1->val % 10;
            l1_prev = l1;
            l1 = l1->next;
        }
        if (extra != 0) {
            l1_prev->next = new ListNode(1);
        }
        return l1_head;
    }
};

// new memory for answer
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* current = head;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = extra;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            extra = sum / 10;
            sum %= 10;
            if (!head) {
                head = new ListNode(sum);
                current = head;
            } else {
                current->next = new ListNode(sum);
                current = current->next;
            }
        }
        return head;
    }
};
