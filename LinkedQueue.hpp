#pragma once
#include "primitives.hpp"

template<class T>
class LinkedQueue {
private:
	node<T>* front_;
	node<T>* rear_;
	int size_;
public:
	LinkedQueue() {
		size_ = 0;
		front_ = nullptr;
		rear_ = nullptr;
	}
	~LinkedQueue() {
		while (!this->empty())
			pop();
	}
	Error_type pop() {
		if (front_ == nullptr)
			return underflow;
		node<T>* temp = front_;
		front_ = front_->next_;
		delete temp;
		size_--;
		return success;
	}
	Error_type push(const T& item) {
		node<T>* new_node = new node<T>(item);
		if (front_ == nullptr)
		{
			front_ = rear_ = new_node;
		}
		else if (front_ == rear_)
		{
			rear_ = new_node;
			front_->next_ = rear_;
		}
		else
		{
			rear_->next_ = new_node;
			rear_ = new_node;
		}
		size_++;
		return success;
	}
	Error_type head(T& item) {
		if (front_ == nullptr)
			return underflow;
		item = front_->data_;
		return success;
	}
	bool empty() {
		return size_ == 0;
	}
	void clear() {
		while (!empty())
			pop();
		size_ = 0;
	}
	int size() {
		return size_;
	}
};
