#pragma once
#include "primitives.hpp"
template<class T>
class List {
private:
	ListNode<T>* node_;
public:
	List() {
		node_ = new ListNode<T>(0, node_, node_);
		node_->next_ = node_;
		node_->prev_ = node_;
	}
	List(const List<T>& other) {
		node_ = new ListNode<T>(0, node_, node_);
		node_->next_ = node_;
		node_->prev_ = node_;
		ListNode<T>* tmp = other.begin();
		while (tmp != other.end())
		{
			push_back(tmp->data_);
			tmp = tmp->next_;
		}
	}
	void operator=(const List<T>& other) {
		clear();
		node_ = new ListNode<T>(0, node_, node_);
		node_->next_ = node_;
		node_->prev_ = node_;
		ListNode<T>* tmp = other.begin();
		while (tmp != other.end())
		{
			push_back(tmp->data_);
			tmp = tmp->next_;
		}
	}
	void swap(List<T>& other) {
		List<T> tmp(*this);
		*this = other;
		other = tmp;
	}
	bool empty()const {
		return node_->next_ == node_;
	}
	ListNode<T>* begin()const {
		return node_->next_;
	}
	ListNode<T>* end()const {
		return node_;
	}
	T front()const {
		return begin()->data_;
	}
	T back()const {
		return end()->prev_->data_;
	}
	void push_back(const T& item) {
		insert(end(), item);
	}
	void push_front(const T& item) {
		insert(begin(), item);
	}
	void pop_front() {
		erase(begin());
	}
	void pop_back() {
		erase(end()->prev_);
	}
	void insert(ListNode<T>* node, const T& item) {
		ListNode<T>* temp = new ListNode<T>(item, node->prev_, node);
		node->prev_->next_ = temp;
		node->prev_ = temp;
	}
	void erase(ListNode<T>* node) {
		if (node_->next_ == node_)
		{
			cout << "has been empty." << endl;
			return;
		}
		ListNode<T>* temp_prev = node->prev_;
		ListNode<T>* temp_next = node->next_;
		temp_prev->next_ = temp_next;
		temp_next->prev_ = temp_prev;
		delete node;
	}
	void clear() {
		while (node_->next_ != node_) {
			pop_front();
		}
	}
	//transfer [first,last) to the node just before pos
	void transfer(ListNode<T>* pos, ListNode<T>* first, ListNode<T>* last) {
		if (pos != last) {
			last->prev_->next_ = pos;
			first->prev_->next_ = last;
			pos->prev_->next_ = first;
			ListNode<T>* temp = first->prev_;
			first->prev_ = pos->prev_;
			pos->prev_ = last->prev_;
			last->prev_ = temp;
		}
	}
	//to merge *this and other to *this, where both lists should be sorted.
	void merge(List<T>& other) {
		ListNode<T>* first1 = begin();
		ListNode<T>* last1 = end();
		ListNode<T>* first2 = other.begin();
		ListNode<T>* last2 = other.end();
		while (first1 != last1 && first2 != last2)
		{
			if (first1->data_ > first2->data_)
			{
				ListNode<T>* tmp = first2->next_;
				transfer(first1, first2, first2->next_);
				first2 = tmp;
			}
			else
				first1 = first1->next_;
		}
		if (first2 != last2)
		{
			transfer(last1, first2, last2);
		}
	}
	void reverse() {
		if (node_->next_ == node_ || node_->next_->next_ == node_)
			return;
		ListNode<T>* first = begin()->next_;
		while (first != end())
		{
			ListNode<T>* tmp = first->next_;
			transfer(begin(), first, first->next_);
			first = tmp;
		}
	}
	void sort() {
		if (node_->next_ == node_ || node_->next_->next_ == node_)
			return;
		List<T> carry;
		List<T> counter[64];
		int fill = 0;
		while (!empty()) {
			carry.transfer(carry.begin(), begin(), begin()->next_);
			int i = 0;
			while (i < fill && !counter[i].empty())
			{
				counter[i].merge(carry);
				carry.swap(counter[i++]);
			}
			carry.swap(counter[i]);
			if (i == fill)
				++fill;
		}
		for (int i = 1; i < fill; i++)
		{
			counter[i].merge(counter[i-1]);
		}
		this->swap(counter[fill - 1]);
	}
};