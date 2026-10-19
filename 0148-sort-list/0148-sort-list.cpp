class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 node
        if (!head || !head->next) return head;

        // 1. Split the list into two halves using fast & slow pointers
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Cut the list
        prev->next = nullptr;

        // 2. Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // 3. Merge the two sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};