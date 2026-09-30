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
        //321
        // 54
        //---
        //975
        //1->2->3
        //4->5->6
        int carry=0;
        ListNode* dummy = new ListNode(-1, l1);
        ListNode* temp=l1;
        int sum =0;
        while(l1 && l2){
            sum = l1->val + l2->val+carry;
            if(sum>9){
                sum=sum-10;
                carry=1;
            }else{
                carry=0;
            }
            l1->val=sum;
            temp=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum = l1->val+carry;
            if(sum>9){
                sum = sum-10;
                carry=1;
                l1->val=sum;
            }else{
                l1->val=sum;
                carry=0;
            }
            temp=l1;
            l1=l1->next;
        }
        while(l2){
            sum = l2->val+carry;
            if(sum>9){
                sum = sum-10;
                carry=1;
                temp->next = new ListNode(sum);
            }else{
                temp->next= new ListNode(sum);
                carry=0;
            }
            l2=l2->next;
            temp=temp->next;
        }
        if(carry){
            if(l1){
                l1->next = new ListNode(carry);
            }else{
                temp->next = new ListNode(carry);
            }
        }

        return dummy->next;
    }
};
