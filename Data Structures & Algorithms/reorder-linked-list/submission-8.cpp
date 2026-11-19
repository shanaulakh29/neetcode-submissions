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
//[2,4,6,8,10]
//     s
//         f
//[2,4,6, 8]
//     s
//         f
//[2,4]
//   s
//     f

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
//2->4->6->null
//.     l1
//10->8->null
//.      l2
//  
//-1->2->10->4->8->6->null
//              t
//.   d
   
    ListNode* mergeLists(ListNode* list1, ListNode* list2){
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* temp=dummy;
        while(list1!=nullptr && list2!=nullptr){
            temp->next = list1;
            list1=list1->next;
            temp=temp->next;
            temp->next = list2;
            list2=list2->next;
            temp=temp->next;
        }
        if(list1!=nullptr){
            temp->next = list1;
        }else{
            temp->next=list2;
        }
        return dummy->next;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode* revHead = reverse(slow->next);
        slow->next = nullptr;
        mergeLists(head, revHead);
        
    }
};
