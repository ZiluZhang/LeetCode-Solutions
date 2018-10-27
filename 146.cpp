// LRU Cache
// 用list和unordered_map结合
// unordered_map是key --> iterator的哈希表
// mylist.splice(it_position, mylist, element) 插到第一个
// mylist.pop_back() 去掉最后一个
// mymap.erase(key) 去掉某个key


class LRUCache {
public:
    LRUCache(int capacity) {
        capa = capacity;
    }
    
    int get(int key) {
        auto it = hash.find(key);
        if(it == hash.end()) return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end())
        {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        cache.insert(cache.begin(), pair<int,int>(key, value));
        hash[key] = cache.begin();
        if(cache.size() > capa)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
        return;
    }
    
    int capa;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> hash; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */