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
// 1->2->3->4->5
// 5->4->3->2->1
// p. rh
//  5
//p rh
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }   
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revHead = reverseList(head);
        ListNode* defaultNode=new ListNode(-1, revHead);
        ListNode* prev = defaultNode;
        int i=1;
        while(i<n){
            prev=revHead;
            revHead=revHead->next;
            i+=1;
        }
        prev->next = revHead->next;
        return reverseList(defaultNode->next);
    }
};
