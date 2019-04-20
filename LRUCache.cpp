struct LRUItem {
    int key;
    int val;
    LRUItem *before;
    LRUItem *next;
    LRUItem(int _key, int _val) : key(_key), val(_val), before(NULL), next(NULL) {}
};

class LRUCache {
    int size;
    int capacity;
    // 维护一个链表，头部是最新的表项，每次需要删除时，删除链表尾部的那个
    LRUItem *head;
    LRUItem *tail;
    unordered_map<int, LRUItem*> LRU_hash;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        // 值存在，取出值，并将该项放到链表头
        if (LRU_hash.count(key) > 0) {
            LRUItem *item = LRU_hash[key];
            // already the first one
            if (item == head) {
                // do nothing
            } 
            // the last one
            else if (item == tail) {
                item->next = head;
                tail = item->before;
                item->before->next = NULL;
                item->before = NULL;
                head->before = item;
                head = item;
            } 
            else {
                item->before->next = item->next;
                item->next->before = item->before;
                head->before = item;
                item->next = head;
                item->before = NULL;
                head = item;
            }
            return item->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // already exists, update the key
        if (LRU_hash.count(key) > 0) {
            // put the item to the head
            get(key);
            LRU_hash[key]->val = value;
        }
        // size equals to capacity, need to delete the LRU item and insert the new item to the head
        else if (size == capacity) {
            LRUItem *new_item = new LRUItem(key, value);
            LRU_hash.insert(make_pair(key, new_item));
            LRU_hash.erase(LRU_hash.find(tail->key));
            if (capacity == 1) {
                delete tail;
                head = tail = new_item;
            } else {
                LRUItem *tmp = tail;
                tail = tail->before;
                tail->next = NULL;
                delete tmp;
                new_item->next = head;
                head->before = new_item;
                head = new_item;
            }
        }
        // directly insert the item to the head
        else {
            size++;
            LRUItem *new_item = new LRUItem(key, value);
            LRU_hash.insert(make_pair(key, new_item));
            // there is nothing in the list
            if (head == NULL) 
                head = tail = new_item;
            else {
                new_item->next = head;
                head->before = new_item;
                head = new_item;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */