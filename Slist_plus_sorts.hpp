#pragma once
#include "primitives.hpp"

template<class T>
class Slist {
private:
	int size_;
	int cur_pos_;
	node<T>* current_;
	node<T>* head_;
	void set_pos(int position) {
		if (position <= cur_pos_ || current_ == nullptr)
		{
			cur_pos_ = 0;
			current_ = head_;
		}
		for (; cur_pos_ < position - 1; cur_pos_++)
		{
			current_ = current_->next_;
		}
	}
	void merge_sort_(node<T>*& head) {
		if (head&&head->next_)
		{
			node<T>* h2 = divided(head);
			merge_sort_(head);
			merge_sort_(h2);
			head = merge(head, h2);
		}
	}
	node<T>* divided(node<T>* head) {
		if (head&&head->next_)
		{
			node<T>* p1 = head;
			node<T>* p2 = head;
			while (p2&&p2->next_&&p2->next_->next_)
			{
				p1 = p1->next_;
				p2 = p2->next_->next_;
			}
			node<T>* res = p1->next_;
			p1->next_ = nullptr;
			return res;
		}
		return nullptr;
	}
	node<T>* merge(node<T>* head1, node<T>* head2) {
		node<T>* dummy = new node<T>;
		node<T>* tmp3 = dummy;
		node<T>* tmp1 = head1;
		node<T>* tmp2 = head2;
		while (tmp1&&tmp2) {
			if (tmp1->data_ > tmp2->data_)
			{
				tmp3->next_ = tmp2;
				tmp2 = tmp2->next_;
			}
			else
			{
				tmp3->next_ = tmp1;
				tmp1 = tmp1->next_;
			}
			tmp3 = tmp3->next_;
		}
		if (tmp1)
			tmp3->next_ = tmp1;
		if (tmp2)
			tmp3->next_ = tmp2;
		return dummy->next_;
	}
public:
	Slist() {
		size_ = 0;
		cur_pos_ = 0;
		current_ = nullptr;
		head_ = nullptr;
	}
	Slist(const Slist& other) {
		if (other.head_)
		{
			head_ = new node<T>(other.head_->data_);
			node<T>* tmp1 = head_;
			node<T>* tmp2 = other.head_;
			size_ = other.size_;
			while (tmp2->next_)
			{
				tmp1->next_ = new node<T>(tmp2->next_->data_);
				tmp1 = tmp1->next_;
				tmp2 = tmp2->next_;
			}
			set_pos(other.cur_pos_);
		}
		
	}
	~Slist() {
		clear();
	}
	bool empty()const {
		return size_ == 0;
	}
	int size()const {
		return size_;
	}
	void clear() {
		while (!empty())
			pop_back();
		size_ = 0;
		cur_pos_ = 0;
		current_ = nullptr;
		head_ = nullptr;
	}
	void traverse(void(*visit)(T& items)) {
		node<T>* temp = head_;
		while (temp)
		{
			visit(temp->data_);
			temp = temp->next_;
		}
	}
	Error_type push_back(const T& item) {
		return insert(size_, item);
	}
	Error_type push_front(const T& item) {
		return insert(0, item);
	}
	Error_type pop_back() {
		return remove(size_ - 1);
	}
	Error_type pop_front() {
		return remove(0);
	}
	Error_type insert(int pos, const T& item) {
		if (pos > size_)
			return overflow;
		if (pos < 0)
			return underflow;
		if (pos <= cur_pos_)
			cur_pos_++;
		node<T>* new_node = new node<T>(item);
		node<T>* tmp;
		if (pos == 0)
		{
			new_node->next_ = head_;
			head_ = new_node;
			size_++;
			return success;
		}
		set_pos(pos);
		if (pos == size_)
		{
			current_->next_ = new_node;
			size_++;
			return success;
		}
		tmp = current_->next_;
		current_->next_ = new_node;
		new_node->next_ = tmp;
		size_++;
		return success;
	}
	Error_type remove(int pos) {
		if (pos >= size_)
			return overflow;
		if (pos < 0)
			return underflow;
		if (size_ == 0)
			return underflow;
		if (pos < cur_pos_)
			cur_pos_--;
		node<T>* tmp;
		if (pos == 0)
		{
			tmp = head_;
			head_ = head_->next_;
			delete tmp;
			size_--;
			return success;
		}
		set_pos(pos);
		if (pos == size_ - 1)
		{
			delete current_->next_;
			current_->next_ = nullptr;
			size_--;
			return success;
		}
		tmp = current_->next_->next_;
		delete current_->next_;
		current_->next_ = tmp;
		size_--;
		return success;
	}
	Error_type front(T& item)const {
		if (head_ == nullptr)
			return underflow;
		item = head_->data_;
		return success;
	}
	void operator=(const Slist& other) {
		clear();
		if (!other.head_)
			return;
		head_ = new node<T>(other.head_->data_);
		node<T>* tmp1 = head_;
		node<T>* tmp2 = other.head_;
		size_ = other.size_;
		while (tmp2->next_)
		{
			tmp1->next_ = new node<T>(tmp2->next_->data_);
			tmp1 = tmp1->next_;
			tmp2 = tmp2->next_;
		}
		set_pos(other.cur_pos_);
	}
	void insertion_sort() {
		if (size_ < 2)
			return;
		node<T>* first_unsorted;
		node<T>* last_sorted = head_;
		node<T>* cur;
		node<T>* tail;
		while (last_sorted->next_)
		{
			first_unsorted = last_sorted->next_;
			if (first_unsorted->data_ < head_->data_)
			{
				last_sorted->next_ = first_unsorted->next_;
				first_unsorted->next_ = head_;
				head_ = first_unsorted;
			}
			else
			{
				tail = head_;
				cur = tail->next_;
				while (first_unsorted->data_ > cur->data_)
				{
					tail = cur;
					cur = cur->next_;
				}
				if (first_unsorted == cur)
				{
					last_sorted = first_unsorted;
				}
				else
				{
					last_sorted->next_ = first_unsorted->next_;
					tail->next_ = first_unsorted;
					first_unsorted->next_ = cur;
				}
			}
		}
	}
	void selection_sort() {
		node<T>* temp = head_;
		for (int i = 1; temp; i++,temp=temp->next_) {
			node<T>* temp1 = temp;
			int mini = INT_MAX;
			int pos = 0;
			for (int j = i; temp1; j++, temp1 = temp1->next_)
			{
				if (temp1->data_ < mini)
				{
					mini = temp1->data_;
					pos = j;
				}
			}
			set_pos(pos);
			int tmp = temp->data_;
			temp->data_ = current_->data_;
			current_->data_ = tmp;
		}
	}
	void merge_sort() {
		merge_sort_(head_);
	}
};