struct ListNode{
    ListNode* next;
    ListNode* prev;
    int value;
    ListNode(int value, ListNode* next, ListNode* prev){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};
class MyCircularQueue {
    int space;
    ListNode* left;
    ListNode* right;
public:
    MyCircularQueue(int k) {
        space=k;
        left = new ListNode(0, nullptr, nullptr);
        right = new ListNode(0, nullptr, nullptr);
        left->next = right;
        right->prev = left;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        ListNode* newNode = new ListNode(value, right, right->prev);
        right->prev->next = newNode;
        right->prev = newNode;
        space-=1;
        return true;
    }
    //L->1->2->R
    //L->2->R
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        ListNode* nodeToDelete = left->next;
        left->next=left->next->next;
        left->next->prev=left;
        delete nodeToDelete;
        space+=1;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return left->next->value;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return right->prev->value;
    }   
    
    bool isEmpty() {
        if(left->next == right){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        return space == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */