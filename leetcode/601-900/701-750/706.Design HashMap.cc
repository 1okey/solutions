// lazy way, without space effiency

class MyHashMap {
private:
    int * _data;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        _data = new int[1000001];
        memset(_data, -1, 1000001);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        _data[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return _data[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        _data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */