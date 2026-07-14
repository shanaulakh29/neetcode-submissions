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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode*fast = head;
        //first find the middle of the linked list. this can be achieved by incrementing fast by 2 and slow by 1. when fast reaches null, then slow is in the middle
        //now we can get the second half of the list from slow->next
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
        }
        //now we reverese the second half of the linked list. If we origally have the list as 1->2->3->4->5, after this code we will have 1->2->3 5->4
        ListNode* l1 = slow->next;
        slow->next = nullptr;
        ListNode* prev=nullptr;
        ListNode* curr = l1;
        while(curr!=nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        //now we merge the two halves to get the final result. we put the element of second half inbetween the curr and elemet of first half
        ListNode* first = head;
        ListNode* second = prev;
        while(first && second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
/*
            ListNode* l1Next = l1->next;
            ListNode* reversedListNext = reversedList->next;
            l1->next = reversedList;
            l1->next->next = l1Next;
            l1 = l1Next;
            reversedList = reversedListNext;
*/
