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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast=head;
        ListNode* slow = dummy;
        int count=0;
        while(count!=n){
            fast=fast->next;
            count++;
        }
        while(fast!=nullptr){
            slow=slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
/* Another way to do it is first reverse the list then delete the nth element and then again reverse the list
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


        ListNode* list = reverseList(head);
        ListNode* curr = list;
        ListNode* prev = nullptr;
        int count=1;
        while(count!=n && curr!=nullptr){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(count==n){
            if(prev==nullptr){
            list = curr->next;
            }else if(prev!=nullptr && curr!=nullptr){
            prev->next = curr->next;
        }
        }
        return reverseList(list);

    }
*/
