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
        ListNode* list3=nullptr;
        ListNode* head = nullptr;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                if(list3==nullptr){
                    list3 = list1;
                    head = list3;
                }else{
                    list3->next = list1;
                    list3=list1;
                }
                list1=list1->next;
            }else if(list1->val>=list2->val){
                if(list3==nullptr){
                    list3=list2;
                    head = list3;
                }else{
                    list3->next = list2;
                    list3 = list2;
                }
                list2=list2->next;
            }
        }
        while(list1!=nullptr){
            if(list3 ==nullptr){
                list3 = list1;
                head = list3;
            }else{
            list3->next = list1;
            list3 = list1;
            }
            list1 = list1->next;
        }
         while(list2!=nullptr){
            if(list3==nullptr){
                list3 = list2;
                head = list3;

            }else{
            list3->next = list2;
            list3 = list2;
            }
            list2 = list2->next;
        }
        return head;
    }
};
