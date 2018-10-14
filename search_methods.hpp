#pragma once
#include <iostream>
#include <vector>
using namespace std;

int binary_search_recursive_1_com(vector<int>& data,int key,int start,int end)
{
	int mid = (start + end) / 2;
	if (start >= end) {
		if (data[start] == key)
			return start;
		else
			return -1;
	}
	else {
		if (data[mid] < key)
		{
			return binary_search_recursive_1_com(data, key, mid + 1, end);
		}
		else
		{
			return binary_search_recursive_1_com(data, key, start, mid);
		}
	}
	

}
int binary_search_recursive_2_com(vector<int>& data, int key, int start, int end)
{
	int mid = (start + end) / 2;
	if (start >= end) {
		if (data[start] == key)
			return start;
		else
			return -1;
	}
	else {
		if (data[mid] == key)
		{
			return mid;
		}
		else if(data[mid] < key)
		{
			return binary_search_recursive_2_com(data, key, mid + 1, end);
		}
		else
		{
			return binary_search_recursive_2_com(data, key, start, mid - 1);
		}
	}

}
int binary_search_iterative_1_com(int key, vector<int>& data)
{
	int start = 0;
	int end = data.size() - 1;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (data[mid] < key)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
	if (data[start] == key)
		return start;
	else
		return -1;
}
int binary_search_iterative_2_com(int key, vector<int>& data)
{
	int start = 0;
	int end = data.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (data[mid] == key)
		{
			return mid;
		}
		else if (data[mid] < key)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}
//for evenly distributed data elements,it works efficiently.
int interpolation_search(int key, vector<int>& data)
{
	int lo = 0;
	int hi = data.size() - 1;
	while (lo <= hi && key >= data[lo] && key <= data[hi])
	{
		int pos = lo + ((double)(hi - lo) / (data[hi] - data[lo]))*(key - data[lo]);
		if (data[pos] == key)
			return pos;
		else if(data[pos] < key)
		{
			lo = pos + 1;
		}
		else
		{
			hi = pos - 1;
		}
	}
	return -1;
}
