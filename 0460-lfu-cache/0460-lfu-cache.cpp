

class LFUCache {
public:
    struct node {
        int key, value, freq;
        node *left, *right;
        node(int k, int v) : key(k), value(v), freq(1), left(nullptr), right(nullptr) {}
    };

    struct DLL {
        node *head;
        node *tail;
        int size;

        DLL() {
            head = new node(-1, -1);
            tail = new node(-1, -1);
            head->right = tail;
            tail->left = head;
            size = 0;
        }

        void addnode(node *temp) {
            temp->right = head->right;
            temp->left = head;
            head->right->left = temp;
            head->right = temp;
            size++;
        }

        void removenode(node *temp) {
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            size--;
        }

        node* removelast() {
            if (size == 0) return nullptr;
            node *last = tail->left;
            removenode(last);
            return last;
        }
    };

    unordered_map<int, node*> keynode;
    unordered_map<int, DLL*> freqlist;
    int capacity;
    int minfreq;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minfreq = 0;
    }

    void updatenode(node *cur) {
        int freq = cur->freq;
        freqlist[freq]->removenode(cur);

        if (freq == minfreq && freqlist[freq]->size == 0) {
            minfreq++;
        }

        cur->freq++;

        if (freqlist.find(cur->freq) == freqlist.end()) {
            freqlist[cur->freq] = new DLL();
        }

        freqlist[cur->freq]->addnode(cur);
    }

    int get(int key) {
        if (keynode.find(key) == keynode.end())
            return -1;

        node* cur = keynode[key];
        updatenode(cur);
        return cur->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keynode.find(key) != keynode.end()) {
            node *cur = keynode[key];
            cur->value = value;
            updatenode(cur);
            return;
        }

        if (keynode.size() == capacity) {
            DLL *list = freqlist[minfreq];
            node *lastnode = list->removelast();
            keynode.erase(lastnode->key);
            delete lastnode;
        }

        node* newnode = new node(key, value);
        minfreq = 1;

        if (freqlist.find(1) == freqlist.end()) {
            freqlist[1] = new DLL();
        }

        freqlist[1]->addnode(newnode);
        keynode[key] = newnode;
    }
};
