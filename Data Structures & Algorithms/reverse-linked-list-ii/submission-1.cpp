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
//l=2
//r=4
//1->2->3->4->5
//p  t
//1->4->3->2->5
//
    ListNode* reverse(ListNode* head, ListNode* temp2){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=temp2){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        head->next=temp2;
        return prev;        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev=dummy;
        int i=1;
        while(i<left){
            temp = temp->next;
            prev = prev->next;
            i+=1;
        }
        i=0;
        ListNode* temp2 = head;
        while(i<right){
            temp2=temp2->next;
            i+=1;
        }   
        prev->next = reverse(temp, temp2);
        return dummy->next;
    }
};