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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode*temp2 = list2;
        ListNode* HEAD=nullptr;
        ListNode*list=nullptr;

        if(temp1==nullptr){
            return temp2;
        }else if(temp2==nullptr){
            return temp1;
        }

        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val<temp2->val){
                if(HEAD==nullptr){
                    HEAD=temp1;
                    list=temp1;
                }else{
                    list->next=temp1;
                    list=list->next;
                }
                temp1=temp1->next;
            }else{
                if(HEAD==nullptr){
                    HEAD=temp2;
                    list=temp2;
                }else{
                    list->next=temp2;
                    list=list->next;
                }
                temp2=temp2->next;
            }
        }
        if(temp1==nullptr){
            list->next=temp2;
        }else{
            list->next=temp1;
        }
        return HEAD;
    }
};
