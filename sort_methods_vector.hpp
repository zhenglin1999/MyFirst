#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "LinkedQueue.hpp"
using namespace std;
void swap(int& data1, int& data2)
{
	int temp = data1;
	data1 = data2;
	data2 = temp;
}
int find_max(int low, int high, vector<int>& data) {
	int res = 0;
	if (low <= high) {
		int max = INT_MIN;
		for (int i = low; i < high; i++)
		{
			if (data[i] > max) {
				res = i;
				max = data[i];
			}
		}
	}
	return res;
}
//---------------------------------------------------------------------
void selection_sort(vector<int>& data) {
	for (int i = 0; i < data.size(); i++) {
		int temp = find_max(0, data.size() - i, data);
		swap(data[temp], data[data.size() - 1 - i]);
	}
}
//---------------------------------------------------------------------
void insertion_sort_1(vector<int>& data)
{
	if (data.size() < 2)
		return;
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] < data[i - 1])
		{
			int j = i;
			while (j > 0 && data[j] < data[j - 1])
			{
				swap(data[j], data[j - 1]);
				j--;
			}
		}
	}
}
void insertion_sort_2(vector<int>& data)
{
	int pos;
	int current;
	if (data.size() < 2)
		return;
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] < data[i - 1])
		{
			pos = i;
			current = data[i];
			while (pos > 0 && current < data[pos-1])
			{
				data[pos] = data[pos - 1];
				pos--;
			}
			data[pos] = current;
		}
	}
}
//---------------------------------------------------------------------
void insertion_sort_interval(vector<int>& data,int inc,int start)
{
	int pos;
	int current;
	if (data.size() < 2)
		return;
	for (int i = start + inc; i < data.size(); i+=inc)
	{
		if (data[i] < data[i - inc])
		{
			pos = i;
			current = data[i];
			while (pos - inc >= 0 && current < data[pos - inc])
			{
				data[pos] = data[pos - inc];
				pos -= inc;
			}
			data[pos] = current;
		}
	}
}
void shell_sort(vector<int>& data)
{
	int inc = data.size();
	do {
		inc = inc / 3 + 1;
		for (int i = 0; i < inc; i++) {
			insertion_sort_interval(data, inc, i);
		}
	} while (inc > 1);
}
//---------------------------------------------------------------------
void quick_sort_recursive(vector<int>& data,int low,int high) {
	if (low < high)
	{
		int pivot = (low + high) / 2;
		swap(data[pivot], data[low]);
		int last_less = low + 1;
		for (int i = low + 1; i < high; i++)
		{
			if (data[i] < data[low])
			{
				swap(data[i], data[last_less]);
				last_less++;
			}
		}
		swap(data[last_less - 1], data[low]);
		quick_sort_recursive(data, low, last_less - 1);
		quick_sort_recursive(data, last_less, high);
	}
}
void quick_sort(vector<int>& data)
{
	quick_sort_recursive(data, 0, data.size());
}
//---------------------------------------------------------------------
void insert_heap(vector<int>& data, int cur, int low, int high) {
	int larger = 2 * low + 1;
	while (larger <= high)
	{
		
		if (larger < high&&data[larger] < data[larger + 1])
		{
			larger++;
		}
		if (cur > data[larger])
		{
			break;
		}
		else {
			data[low] = data[larger];
			low = larger;
			larger = 2 * low + 1;
		}
	}
	data[low] = cur;
}
void build_heap(vector<int>& data) {
	for (int i = data.size() / 2 - 1; i >= 0; i--)
	{
		int cur = data[i];
		insert_heap(data, cur, i, data.size() - 1);
	}
}
void heap_sort(vector<int>& data) {
	if (data.size() < 2)
		return;
	build_heap(data);
	for (int i = 0; i < data.size(); i++)
	{
		int cur = data[data.size() - 1 - i];
		data[data.size() - 1 - i] = data[0];
		insert_heap(data, cur, 0, data.size() - i - 2);
	}
}
//---------------------------------------------------------------------
int getOrder(int t,int digits)
{
	int ans = 0;
	if (digits > log10(t) + 1)
		return 0;
	for (int i = 0; i < digits; i++)
	{
		ans = t % 10;
		t /= 10;
	}
	return ans + 1;
}
void recombine(vector<LinkedQueue<int> >& lq, vector<int>& data)
{
	data.clear();
	for (int i = 0; i < 11; i++)
	{
		while (!lq[i].empty())
		{
			int tmp;
			lq[i].head(tmp);
			data.push_back(tmp);
			lq[i].pop();
		}
	}
}
void radix_sort(vector<int>& data) {
	vector<LinkedQueue<int> >  lq(11);
	auto t = max_element(data.begin(), data.end());
	int digits = log10(*t) + 1;
	for (int i = 1; i <= digits; i++)
	{
		for (auto it = data.begin(); it != data.end(); it++)
		{
			lq[getOrder(*it, i)].push(*it);
		}
		recombine(lq, data);
	}
}