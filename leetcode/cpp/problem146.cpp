class LRUCache {

    typedef int key_t;
    typedef int val_t;
    typedef pair<key_t, val_t> kv;
    typedef list<kv>::iterator lit;
    unordered_map<key_t, lit> map;

    list<kv> ls;
    int _cap;
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }

    int get(int key) {
        auto kit = map.find(key);
        if (kit == map.end())
            return -1;
        auto ret = map[key]->second;
        ls.erase(kit->second);
        ls.push_front({key, ret});
        map[key] = ls.begin();
        return ret;
    }

    void put(int key, int value) {
        auto kit = map.find(key);
        lit _lit;
        if (kit != map.end()) {
            ls.erase(kit->second);
            ls.push_front({key, value});
            map[key] = ls.begin();
            return;

        }
        if (_cap == ls.size()) {
            map.erase(ls.back().first);
            ls.pop_back();
        }

        ls.push_front({key, value});
        map[key] = ls.begin();
    }

};

