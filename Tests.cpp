#include "LinkedQueue.hpp"
#include "LinkedStack.hpp"
#include "Slist_plus_sorts.hpp"
#include "List.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "DynamicPro.hpp"
#include "search_methods.hpp"
#include "sort_methods_vector.hpp"
#include "utilities.hpp"
#include "hash_table.hpp"
#include <iomanip>
#include <algorithm>
#include <set>
#define PERMUTATION_SIZE 4
void print(int& item)
{
	cout << item << " ";
}
void test_slist(Slist<int>& sl) {
	for (int i = 10; i < 20; i++)
	{
		sl.push_back(i);
	}
	for (int i = 0; i < 10; i++)
	{
		sl.push_front(i);
	}
	sl.traverse(print);
	cout << endl;
	Slist<int> sl2(sl);
	for (int i = 0; i < 30; i++)
	{
		int temp = 0;
		if (sl.front(temp) != underflow)
		{
			
			sl.pop_front();
			cout << temp << " ";
		}
		else
		{
			cout << endl << "no more data" << endl;
			break;
		}
	}
	sl2.pop_front();
	sl2.pop_front();
	sl2.pop_back();
	sl2.pop_back();
	sl2.traverse(print);
	cout << endl;
	sl2.insert(5, 20);
	sl2.insert(5, 30);
	sl2.remove(5);
	sl2.remove(3);
	sl2.traverse(print);
	cout << endl;
}
void test_prim(LinkedQueue<int>& lq, LinkedStack<int>& ls, Stack<int>& s, Queue<int>& q)
{
	for (int i = 0; i < 20; i++)
	{
		lq.push(i);
		ls.push(2 * i);
		s.push(3 * i);
		if (q.push(4 * i) == overflow)
			cout << "queue is full!" << endl;
	}
	for (int i = 0; i < 30; i++)
	{
		int tmp = 0;
		if (lq.head(tmp) != underflow)
		{
			cout << tmp << " ";
			lq.pop();
		}
		else
		{
			cout << endl << "no more data." << endl;
			break;
		}
	}
	for (int i = 0; i < 30; i++)
	{
		int tmp = 0;
		if (ls.top(tmp) != underflow)
		{
			cout << tmp << " ";
			ls.pop();
		}
		else
		{
			cout << endl << "no more data." << endl;
			break;
		}
	}
	for (int i = 0; i < 30; i++)
	{
		int tmp = 0;
		if (q.front(tmp) != underflow)
		{
			cout << tmp << " ";
			q.pop();
		}
		else
		{
			cout << endl << "no more data." << endl;
			break;
		}
	}
	for (int i = 0; i < 30; i++)
	{
		int tmp = 0;
		if (s.top(tmp) != underflow)
		{
			cout << tmp << " ";
			s.pop();
		}
		else
		{
			cout << endl << "no more data." << endl;
			break;
		}
	}
	lq.clear();
	ls.clear();
	for (int i = 10; i < 30; i++)
	{
		lq.push(i);
		ls.push(2 * i);
	}
	for (int i = 0; i < 30; i++)
	{
		int tmp = 0;
		if (lq.head(tmp) != underflow)
		{
			cout << tmp << " ";
			lq.pop();
		}
		else
		{
			cout << endl << "no more data." << endl;
			break;
		}
	}
	for (int i = 0; i < 30; i++)
	{
		int tmp = 0;
		if (ls.top(tmp) != underflow)
		{
			cout << tmp << " ";
			ls.pop();
		}
		else
		{
			cout << endl << "no more data." << endl;
			break;
		}
	}
}
void test_coins(void) {
	vector<int> values = { 1,2,4,10,20,40,100,200,400,1000,2000 };
	double a = 1.1;
	while (a != 0.00)
	{
		cin >> a;
		int total = a * 20;
		cout << setprecision(4)<< setiosflags(ios::fixed) << a << setw(17)<< setiosflags(ios::right)<<count(total, values) << endl;
	}
	cout.unsetf(ios_base::fixed);
}
void test_search(void) {
	clock_t start, finish;
	vector<int> data = random_data(50, 5, 50000);
	int key = 41823;
	sort(data.begin(), data.end());
	//print_arr(data);

	start = clock();
	cout << binary_search_iterative_1_com(key, data);
	finish = clock();
	cout << "   " << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;

	start = clock();
	cout << binary_search_iterative_2_com(key, data);
	finish = clock();
	cout << "   " << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;

	start = clock();
	cout << binary_search_recursive_1_com(data, key, 0, data.size() - 1);
	finish = clock();
	cout << "   " << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;

	start = clock();
	cout << binary_search_recursive_2_com(data, key, 0, data.size() - 1);
	finish = clock();
	cout << "   " << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;

	start = clock();
	cout << interpolation_search(key, data);
	finish = clock();
	cout << "   " << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
}
void test_sort(void) {
	clock_t start, finish;
	vector<int> data = random_data(1000, 1,9999);
	print_arr(data);
	vector<vector<int> > dataset;
	for (int i = 0; i < 7; i++)
		dataset.push_back(data);
	Slist<int> s;
	for (int i = 0; i < data.size(); i++)
		s.push_back(data[i]);

	start = clock();
	selection_sort(dataset[0]);
	finish = clock();
	cout << "    selection:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
	//print_arr(dataset[0]);

	start = clock();
	insertion_sort_1(dataset[1]);
	finish = clock();
	cout << "    insertion:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
	//print_arr(dataset[1]);

	start = clock();
	insertion_sort_2(dataset[2]);
	finish = clock();
	cout << "refinedINSERT:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
	//print_arr(dataset[2]);

	start = clock();
	shell_sort(dataset[3]);
	finish = clock();
	cout << "        shell:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
	//print_arr(dataset[3]);

	start = clock();
	quick_sort(dataset[4]);
	finish = clock();
	cout << "        quick:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
	//print_arr(dataset[4]);

	start = clock();
	heap_sort(dataset[5]);
	finish = clock();
	cout << "         heap:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
	//print_arr(dataset[5]);

	start = clock();
	radix_sort(dataset[6]);
	finish = clock();
	cout << "        radix:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
	//print_arr(dataset[6]);

	set< vector<int> > set_for_dup(dataset.begin(), dataset.end());
	if (set_for_dup.size() != 1)
		cout << "some one is wrong!!!" << endl;
	else
		cout << "ALL methods sort wonderfully as the same....." << endl;
	Slist<int> s2 = s;
	Slist<int> s3 = s;

	start = clock();
	s.insertion_sort();
	finish = clock();
	cout << " insertion:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;

	start = clock();
	s2.merge_sort();
	finish = clock();
	cout << " mergesort:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;

	start = clock();
	s3.selection_sort();
	finish = clock();
	cout << " selection:" << (double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;



	set< vector<int> > set_for_list = { print_list_to_vec(s,3000),\
		print_list_to_vec(s2,3000),print_list_to_vec(s3,3000) };
	if (set_for_list.size() != 1)
		cout << "some one is wrong!!!" << endl;
	else
		cout << "ALL methods work....." << endl;
}
void test_list(List<int>& l) {
	vector<int> data = random_data(20, 5, 50);
	print_arr(data);
	for (int i = 0; i < data.size(); i++)
	{
		l.push_back(data[i]);
	}
	List<int> l2(l);
	for (int i = 0; i < data.size() + 5; i++)
	{
		cout << l.front() << " ";
		l.pop_front();
	}
	cout << endl;
	for (int i = 0; i < data.size() + 5; i++)
	{
		cout << l2.back() << " ";
		l2.pop_back();
	}
	cout << endl;
	for (int i = 0; i < data.size(); i++)
	{
		l2.push_front(data[i]);
	}
	l = l2;
	for (int i = 0; i < data.size() + 5; i++)
	{
		cout << l2.front() << " ";
		l2.pop_front();
	}
	cout << endl;
	l.reverse();
	for (int i = 0; i < data.size() + 5; i++)
	{
		cout << l.front() << " ";
		l.pop_front();
	}
	cout << endl;
	vector<int> data2 = random_data(10, 25, 50);
	print_arr(data);
	print_arr(data2);
	for (int i = 0; i < data.size(); i++)
	{
		l.push_back(data[i]);
	}
	for (int i = 0; i < data2.size(); i++)
	{
		l2.push_back(data2[i]);
	}
	l.sort();
	l2.sort();
	for (int i = 0; i < data.size(); i++)
	{
		cout << l.front() << " ";
		l.pop_front();
	}
	cout << endl;
	for (int i = 0; i < data2.size(); i++)
	{
		cout << l2.front() << " ";
		l2.pop_front();
	}
	cout << endl;
	for (int i = 0; i < data.size(); i++)
	{
		l.push_back(data[i]);
	}
	for (int i = 0; i < data2.size(); i++)
	{
		l2.push_back(data2[i]);
	}
	l.sort();
	l2.sort();
	l.merge(l2);
	for (int i = 0; i < data.size() + data2.size(); i++)
	{
		cout << l.front() << " ";
		l.pop_front();
	}
}
void test_hash(void)
{
	hashTable_probing<int> hp;
	hashTable_chaining<int> hc;
	vector<int> data;
	for (int i = 0; i < 40; i++)
	{
		hp.insert(i);
		hc.insert(i);
	}
	if (hp.retrive(5))
		cout << "5 is in hp" << endl;
	if (!hp.retrive(50))
		cout << "50 is not in hp" << endl;
	if (hc.retrive(15))
		cout << "15 is in the hc" << endl;
	if (!hc.retrive(50))
		cout << "50 is not in hc" << endl;
	hc.remove(15);
	if(!hc.retrive(15))
		cout << "15 is not in the hc" << endl;

	hashTable_probing<string> hp1;
	hashTable_chaining<string> hc1;
	hp1.insert("cat");
	hp1.insert("dog");
	if (hp1.retrive("cat"))
		cout << "cat is in hp1" << endl;
	if (!hp1.retrive("catty"))
		cout << "catty is not in hp1" << endl;
	hc1.insert("dodge");
	hc1.insert("doggy");
	if (hc1.retrive("dodge"))
		cout << "dodge is in hc1" << endl;
	if(!hc1.retrive("catt"))
		cout << "catt is not in hc1" << endl;
	hc1.remove("dodge");
	if (!hc1.retrive("dodge"))
		cout << "dodge is not in hc1" << endl;
}
int main()
{
	LinkedQueue<int> lq;
	LinkedStack<int> ls;
	Slist<int> sl;
	List<int> l;
	Stack<int> s;
	Queue<int> q;
	return 0;
}