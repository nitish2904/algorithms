class LRUCache {
public:
    int size;
    
    struct Node{
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int x, int y){
            key = x;
            value = y;
            next = NULL;
            prev = NULL;
        }
    };

    Node *head = new Node(0,0);
    Node *tail = new Node(0,0);
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;

    }


    Node* delete1(Node* current){
        (current->prev)->next = current->next;
        (current->next)->prev = current->prev;
        return head;
    }

    Node *insert(Node *head, Node *temp){
        temp->next = head->next;
        (head->next)->prev = temp;
        head->next = temp;
        temp->prev = head;
        return head;
    }

    unordered_map<int,Node*>mp;

    int get(int key) {
        if(mp[key]){
            Node *temp = mp[key];
            head = delete1(temp);
            head = insert(head,temp);
            return temp->value;    
        }
        return -1;        
    }
    
    void put(int key, int value) {
        if(mp[key]){
            Node *current = mp[key];
            head = delete1(current);
            current->value = value;
            head = insert(head,current);
        }
        else{
            if(size==0){
                mp.erase(tail->prev->key);
                delete1(tail->prev);
                size++;
            }
            Node *temp = new Node(key,value);
            mp[key] = temp;
            head = insert(head, temp);
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */