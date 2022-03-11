#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) : data_(k) {
        front_ = 0;
				rear_ = 0;
				size_ = 0;
    }
    
    bool enQueue(int value) {
			if (size_ == data_.size()) return false;
			data_[rear_] = value;
			size_++;
			rear_++;
			rear_ = rear_ % data_.size();
			return true;
    }
    
    bool deQueue() {
			if (size_ == 0) return false;
			size_--;
			front_++;
			front_ = front_ % data_.size();
			return true;
    }
    
    int Front() {
			if (size_ == 0) return -1;
			return data_[front_];
    }
    
    int Rear() {
			if (size_ == 0) return -1;
			if (rear_ == 0) return data_.back();
			return data_[rear_ - 1];
    }
    
    bool isEmpty() {
			return size_ == 0;
    }
    
    bool isFull() {
			return size_ == data_.size();
    }

    vector<int> data_;
    int front_;
    int rear_;
    int size_;
};