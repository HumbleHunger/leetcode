#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), size_(0) {

    }
    
    int get(int key) {
			auto iter = map_[key];
			int ret = iter->second;
			data_.erase(iter);
			data_.push_front({key, ret});
			map_[key] = data_.begin();
			return ret;
    }
    
    void put(int key, int value) {
			if (map_.count(key) == 0) {
				if (size_ == capacity_) {
					data_.pop_back();
					size_--;
					map_.erase(key);
				}
				data_.push_front({key, value});
				map_[key] = data_.begin();
				size_++;
			} else {
				auto iter = map_[key];
				data_.erase(iter);
				data_.push_front({key, value});
				map_[key] = data_.begin();
			}
    }

		int size_;
		int capacity_;
    list<pair<int, int>> data_;
    map<int, list<pair<int, int>>::const_iterator> map_;
};
