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
    ListNode*reverseList(ListNode*head){
        ListNode* curr = head;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode*nextNode= curr->next;
            curr->next = prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    //[4,3,2,1]
    //[5]
    //[2,1]
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rHead = reverseList(head);
        ListNode* curr=rHead;
        ListNode* temp=nullptr;
        int i=1;
        while(i<n && curr!=nullptr){
            temp=curr;
            curr = curr->next;
            i++;
        }
        if(curr!=nullptr && temp==nullptr){
            rHead=curr->next;
        }else if(curr!=nullptr && temp!=nullptr){
            temp->next = curr->next;
        }

        return reverseList(rHead);
        
    }
};
