/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* h) {
    struct ListNode d;
    d.next = h;
    struct ListNode* p = &d;
    while (p->next && p->next->next) {
        struct ListNode* f = p->next;
        struct ListNode* s = p->next->next;
        f->next = s->next;
        s->next = f;
        p->next = s;
        p = f;
    }
    return d.next;
}

struct ListNode* c(int v) {
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = v;
    n->next = NULL;
    return n;
}

struct ListNode* a(int* arr, int sz) {
    if (sz == 0) return NULL;
    struct ListNode* h = c(arr[0]);
    struct ListNode* cur = h;
    for (int i = 1; i < sz; i++) {
        cur->next = c(arr[i]);
        cur = cur->next;
    }
    return h;
}

void p(struct ListNode* h) {
    while (h != NULL) {
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}