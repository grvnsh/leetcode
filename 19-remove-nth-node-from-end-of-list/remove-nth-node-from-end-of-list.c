/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode temp;
    temp.next = head;
    struct ListNode *x = &temp;
    struct ListNode *y = &temp;
    for (int i = 1; i <= n + 1; i++) {
        x = x->next;
    }
    while (x != NULL) {
        x = x->next;
        y = y->next;
    }
    struct ListNode *to_remove = y->next;
    y->next = y->next->next;
    free(to_remove);
    return temp.next;
}