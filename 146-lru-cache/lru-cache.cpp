class LRUCache {
public:
    list<int> dll; // Doubly linked list of keys (front = MRU, back = LRU)
    // Map: key -> {iterator to dll node, value}
    unordered_map<int, pair<list<int>::iterator, int>> cache; 
    int capacity;

    // Constructor
    LRUCache(int capacity) { 
        this->capacity = capacity; 
    }

    // Move key to front (mark as MRU)
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);   // remove old position
        dll.push_front(key);           // move to front
        cache[key].first = dll.begin();// update iterator
    }

    // Get value for a given key
    int get(int key) {
        unordered_map<int, pair<list<int>::iterator, int>>::iterator it = cache.find(key);
        if (it == cache.end()) {
            return -1; // not found
        }

        // Mark as MRU
        makeMostRecentlyUsed(key);
        return it->second.second; // return value
    }

    // Insert or update a key-value pair
    void put(int key, int value) {
        unordered_map<int, pair<list<int>::iterator, int>>::iterator it = cache.find(key);

        if (it != cache.end()) {
            // Key exists -> update value & move to MRU
            it->second.second = value;
            makeMostRecentlyUsed(key);
        } else {
            // Insert new key at front (MRU)
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;
        }

        // If over capacity -> remove LRU
        if (capacity < 0) {
            int lruKey = dll.back();   // last element = LRU
            dll.pop_back();            // remove from list
            cache.erase(lruKey);       // erase from map
            capacity++;
        }
    }
};