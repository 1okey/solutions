#include <algorithm>
#include <iterator>

class MyHashMap {
private:
    vector<int> _data;
    static const int SIZE = 100;
    size_t _size;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        _size = MyHashMap::SIZE;
        _data = vector<int>(_size, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if (key >= _size) {
            resize();
            return put(key, value);
        }
        _data[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return key >= _size ? -1 : _data[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (key < _size) {
            _data[key] = -1;
        }
    }
private:
    void resize()
    {
        _size *= 2;
        vector<int> _tmp(_size, -1);
        copy(_data.begin(), _data.end(), _tmp.begin());
        _data = move(_tmp);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */