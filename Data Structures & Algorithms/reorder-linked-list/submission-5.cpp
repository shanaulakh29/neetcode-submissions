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
    ListNode* reverseList(ListNode*head){
        ListNode*prev=nullptr;
        ListNode*curr=head;
        while(curr!=nullptr){
            ListNode*next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void mergeList(ListNode*list1, ListNode*list2){
        while(list1!=nullptr && list2!=nullptr){
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            list1->next=list2;
            list2->next=temp1;
            list1=temp1;
            list2=temp2;
        }
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode*mid = slow->next;
        slow->next=nullptr;
        ListNode* rlist=reverseList(mid);
        mergeList(head, rlist);
    }
};
