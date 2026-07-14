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
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr!=NULL){
            ListNode* currNextBlock = curr->next;
            curr->next = prev;
            if(prev==head){
                prev->next = NULL;
            }
            prev = curr;
            curr=currNextBlock;
        }
        head = prev;
        return head;
    }
};
