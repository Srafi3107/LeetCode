class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Dummy node before the sorted list
        ListNode* dummy = new ListNode(0);

        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;

            // Find where curr should be inserted
            ListNode* prev = dummy;

            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy->next;
    }
};