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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* nextNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* mergeLists(ListNode*list1, ListNode*list2){
        if(list1==nullptr){
            return list2;
        }else if(list2==nullptr){
            return list1;
        }
        ListNode* HEAD=list1;
        ListNode*list=list1;
        list1=list1->next;
        while(list1!=nullptr && list2!=nullptr){
                list->next=list2;
                list2=list2->next;
                list=list->next;
                

                list->next=list1;
                list1=list1->next;
                list=list->next;
        }
        if(list1==nullptr){
            list->next= list2;
        }else if(list2==nullptr){
            list->next=list1;
        }
        return HEAD;
    }

    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast= fast->next->next;
        }
        ListNode* rhead=reverseList(slow->next);
        slow->next = nullptr;
        mergeLists(head, rhead);
        
    }
};
