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
    bool hasCycle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
        //this takes O(n) time but O(n)memory
        // ListNode* curr = head;
        // unordered_set<ListNode*>mp;
        // while(curr){
        //     if(mp.find(curr)!=mp.end()){
        //         return true;
        //     }
        //     mp.insert(curr);
        //     curr=curr->next;
            
        // }
        // return false;
    }
};
