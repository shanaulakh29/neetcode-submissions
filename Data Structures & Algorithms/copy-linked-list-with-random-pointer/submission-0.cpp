/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>map;
        map[nullptr] = nullptr;
        Node* curr = head;
        while(curr){//first pass just making up the nodes
            Node* tmp = new Node(curr->val);
            map[curr] = tmp;
            curr = curr->next;
        }
        curr = head;
        while(curr){//2nd pass. now setting the next and random pointers
            Node* copy = map[curr];
            copy->next = map[curr->next];
            copy->random = map[curr->random];
            curr=curr->next;
        }
        return map[head];
    }
};
