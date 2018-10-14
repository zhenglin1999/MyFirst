#pragma once
#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 100
#define MAX_SIZE_QUEUE 10
using namespace std;
enum Error_type { success, underflow, overflow };

template <class T>
struct node
{
	T data_;
	node *next_;
	node() : data_(0), next_(nullptr) {}
	node(T data) :data_(data), next_(nullptr) {}
	node(T data,node* next) :data_(data), next_(next) {}
};

template <class T>
struct ListNode
{
	T data_;
	ListNode *prev_;
	ListNode *next_;
	ListNode() : data_(0),prev_(nullptr), next_(nullptr) {}
	ListNode(T data) :data_(data), prev_(nullptr), next_(nullptr) {}
	ListNode(T data,ListNode* prev,ListNode* next):
		data_(data), prev_(prev), next_(next) {}
};