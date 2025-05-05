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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }

    ListNode* const reverse_start = prev;
    ListNode* curr = prev->next;
    ListNode* prev_rev = nullptr;

   
    for (int i = 0; i <= right - left; ++i) {
        ListNode* next_node = curr->next;
        curr->next = prev_rev;
        prev_rev = curr;
        curr = next_node;
    }

  
    reverse_start->next->next = curr;
    reverse_start->next = prev_rev;

    return dummy.next;
}
};
