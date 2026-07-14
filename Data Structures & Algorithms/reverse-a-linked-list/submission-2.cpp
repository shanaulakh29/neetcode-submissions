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
    ListNode* reverseList(ListNode* head) {
        //O(n) time and O(1)space
        if(head==nullptr){
            return nullptr;
        }
        // ListNode* curr=head;
        // ListNode* prev=nullptr;
        // while(curr!=nullptr){
        //     ListNode* nextNode = curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nextNode;
        // }
        // head=prev;
        // return head;

        //recursive O(n) time and O(n)space

        // if(head==nullptr){
        //     return head;
        // }
        ListNode*newHead = head;
        if(head->next){
            newHead = reverseList(head->next);
            head->next->next=head;
            head->next=nullptr;
        }
        return newHead;

    }
};
