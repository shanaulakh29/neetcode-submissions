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
       ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        } 
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr){
            return nullptr;
        }

        ListNode* list = reverseList(head);
        ListNode* curr = list;
        ListNode* prev = nullptr;
        int count=1;
        while(count!=n){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(prev!=nullptr && curr!=nullptr){
            prev->next = curr->next;
        }
        if(prev==nullptr && curr!=nullptr){
            list = curr->next;
        }
        return reverseList(list);

    }
};
