/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode x = temp;
        ListNode y = temp;
        for (int i = 1; i <= n + 1; i++) {
            x = x.next;
        }
        while (x != null) {
            x = x.next;
            y = y.next;
        }
        y.next = y.next.next;
        return temp.next;
    }
}