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
 ListNode* reverseKNodes(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (k--) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; 
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;


    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev_group_end = &dummy;

    while (true) {
        ListNode* group_start = prev_group_end->next;
        ListNode* node = group_start;

  
        for (int i = 0; i < k; ++i) {
            if (!node) return dummy.next; 
            node = node->next;
        }

        ListNode* next_group_start = node;
        ListNode* prev = next_group_start;
        ListNode* curr = group_start;
        for (int i = 0; i < k; ++i) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

      
        prev_group_end->next = prev;
        prev_group_end = group_start;
    }

    return dummy.next;
}
};
