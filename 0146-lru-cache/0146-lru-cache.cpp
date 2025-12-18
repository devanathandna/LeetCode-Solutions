class LRUCache {
public:
    class node{
        public:
        int key;
        int value;
        node* left;
        node* right;
        node(int key_,int value_){
            key = key_;
            value = value_;
        }
    };


    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
    LRUCache(int capacity) {
        cap = capacity;
        head->right = tail;
        tail->left = head;
    }

    void insertNode(node* newNode){
        node* temp = head->right;
        newNode ->right = temp;
        newNode->left = head;
        head->right = newNode;
        temp->left = newNode;
    }

    void deleteNode(node* delnode){
        node* delprev = delnode ->left;
        node* delnext = delnode->right;

        delprev->right = delnext;
        delnext->left = delprev;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* exist = m[key];
            int res = exist->value;
            m.erase(key);
            deleteNode(exist);
            insertNode(exist);
            m[key] = head->right;
            return res;
        }

        return -1;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* exist = m[key];
            m.erase(key);
            deleteNode(exist);
        }

        if(m.size() == cap){
            m.erase(tail->left->key);
            deleteNode(tail->left);
        }

        insertNode(new node(key,value));
        m[key] = head->right;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */