#pragma once
#include "primitives.hpp"

template <class T>
class LinkedStack
{
  private:
    node<T> *head_;
    int size_;

  public:
	  LinkedStack() {
		  head_ = nullptr;
		  size_ = 0;
	}
	  Error_type pop() {
		  if (head_ == nullptr)
			  return underflow;
		  node<T> *temp = head_;
		  head_ = head_->next_;
		  delete temp;
		  size_--;
		  return success;
	}
	  Error_type push(const T &item) {
		  node<T> *temp = new node<T>(item);
		  temp->next_ = head_;
		  head_ = temp;
		  size_++;
		  return success;
	}
	  Error_type top(T &item) {
		  if (head_ == nullptr)
			  return underflow;
		  item = head_->data_;
		  return success;
	}
	  bool empty() {
		  return size_ == 0;
	}
	  void clear() {
		  while (!empty())
			  pop();
	}
	  ~LinkedStack() {
		  clear();
	}
	  int size() {
		  return size_;
	  }
};
