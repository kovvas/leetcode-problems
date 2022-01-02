// Number: 146
// Name: LRU Cache
// Tags: OOP

class LRUCache {
public:
    LRUCache(int capacity) : d_capacity(capacity) {
        
    }
    
    int get(int key) {
        if (d_kv.find(key) != d_kv.end()) {
            update(key);
            return d_kv[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (d_kv.find(key) != d_kv.end()) {
            d_kv[key] = value;
            update(key);
        } else {
            if (lru.size() == d_capacity) {
                d_kv.erase(lru.back());
                keyToIt.erase(lru.back());
                lru.pop_back();
            }
            d_kv[key] = value;
            lru.push_front(key);
            keyToIt[key] = lru.begin();
        }
    }
    
    void update(int key) {
        lru.erase(keyToIt[key]);
        lru.push_front(key);
        keyToIt[key] = lru.begin();
    }
private:
    int d_capacity;
    unordered_map<int, list<int>::iterator> keyToIt;
    unordered_map<int,int> d_kv;
    list<int> lru;
};
