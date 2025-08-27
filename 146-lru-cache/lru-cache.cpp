
class LRUCache {
public:
    list<int> dll; // Doubly linked list to store keys (front = most recent, back = least recent)
    map<int, pair<list<int>::iterator, int>> cache; // key -> (iterator pointing to dll node, value)
    int capacity; // Maximum capacity of cache

    // Constructor to initialize LRU Cache with given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Function to move a key to the front of the DLL (mark it as most recently used)
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);   // Remove the key from its current position
        dll.push_front(key);           // Insert it at the front (most recent)
        cache[key].first = dll.begin(); // Update iterator in cache map
    }

    // Function to get the value of a key
    int get(int key) {
        // Look for the key in cache using find()
        map<int, pair<list<int>::iterator, int>>::iterator it = cache.find(key);

        if (it == cache.end()) {
            return -1; // Key not found
        }

        makeMostRecentlyUsed(key);     // Since it's accessed, mark it as most recently used
        return cache[key].second;      // Return the value
    }

    // Function to insert or update a key-value pair
    void put(int key, int value) {
        // Case 1: Key already exists → update value and move to front
        map<int, pair<list<int>::iterator, int>>::iterator it = cache.find(key);
        if (it != cache.end()) {
            cache[key].second = value;  // Update value
            makeMostRecentlyUsed(key);  // Move to most recently used
        }
        // Case 2: Key does not exist → insert new key
        else {
            dll.push_front(key);             // Insert key at front
            cache[key] = make_pair(dll.begin(), value); // Store iterator + value in map
            capacity--;                      // Reduce capacity
        }

        // If cache exceeds capacity, remove least recently used (from back)
        if (capacity < 0) {
            int leastRecentKey = dll.back(); // Get least recent key
            dll.pop_back();                  // Remove from list
            cache.erase(leastRecentKey);     // Erase from map
            capacity++;                      // Restore capacity
        }
    }
};
