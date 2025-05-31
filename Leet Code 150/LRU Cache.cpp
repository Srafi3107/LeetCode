class LRUCache {
    private:
    int capacity;
    std::list<std::pair<int, int>> dll; 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
public:
LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        
        auto it = cache[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});
        cache[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
         
            dll.erase(cache[key]);
        } else if (dll.size() == capacity) {
           
            int lruKey = dll.back().first;
            dll.pop_back();
            cache.erase(lruKey);
        }

       
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
