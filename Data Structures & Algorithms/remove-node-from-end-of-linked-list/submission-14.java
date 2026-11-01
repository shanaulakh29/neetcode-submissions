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
// 1->2->3->4
//-1->4->3->2->1
//    t

class Solution {
    private ListNode reverseList(ListNode head){
        ListNode curr = head;
        ListNode prev = null;
        while(curr!=null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr=next;
        }
        return prev;
    } 
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next==null){
            return null;
        }
        ListNode revHead = reverseList(head);
        ListNode dummy = new ListNode();
        dummy.next = revHead;
        ListNode temp = dummy;
        int count=0;
        while(count<n-1){
            temp = temp.next;
            count+=1;
        }
        temp.next = temp.next.next;

        return reverseList(dummy.next);
    }
}
