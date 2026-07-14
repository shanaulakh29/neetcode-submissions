class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class LRUCache {
    int cap;
    Node* left;//LRU
    Node* right;//MRU
    unordered_map<int,Node*>mp;
public:
    LRUCache(int capacity) {
        this->cap=capacity;  
        left = new Node(0,0);
        right =  new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    void insert(Node* node){
        Node* prevNode = right->prev;
        Node* nextNode = right;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = nextNode;
        nextNode->prev = node;
    }
    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        remove(mp[key]);
        insert(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            Node* node = new Node(key,value);
            mp[key]=node;
            insert(node);
        }else{
            Node* node = mp[key];
            node->value = value;
            remove(mp[key]);
            insert(node);
        }
        if(mp.size()>cap){
            Node* LRU = left->next;
            remove(LRU);
            mp.erase(LRU->key);
            delete LRU;
        }
    }
};
