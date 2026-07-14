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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = l1;
        ListNode* prev = nullptr;

        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;
            int digit = sum % 10;

            if (l1) {
                l1->val = digit;
            } else {
                l1 = new ListNode(digit);
                if (prev) {
                    prev->next = l1;
                } else {
                    head = l1; // case when original l1 was nullptr
                }
            }

            prev = l1;
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head;
    }
};


/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carryBit = 0;
        ListNode* head = l1;
        ListNode* prev = nullptr;
        while(l1 || l2 || carryBit){
            int l1Val= l1 ? l1->val : 0;
            int l2Val = l2?l2->val:0;
            int res = l1Val+l2Val+carryBit;
            carryBit = 0;
            carryBit = res/10;
            res = res%10;
            if(l1==nullptr){
                l1 = new ListNode(res);
                prev->next = l1;
            }else{
            l1->val=res;
            }
            prev = l1;
            l1=l1->next?l1->next:nullptr;
            l2 = l2->next?l2->next:nullptr;   
        }
        return head;
    }
*/
