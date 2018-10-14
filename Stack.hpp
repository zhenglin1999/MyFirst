#pragma once
#include "primitives.hpp"

template <class T>
class Stack
{
private:
  T *data_;
  int size_;

public:
  Stack();
  Stack(const Stack &other);
  Error_type pop();
  Error_type push(const T &item);
  Error_type top(T &item);
  bool empty();
  int size();
  ~Stack();
  void operator=(const Stack &other);
};

template <class T>
Stack<T>::Stack()
{
  data_ = new T[MAX_SIZE];
  size_ = 0;
}
template <class T>
Stack<T>::Stack(const Stack &other)
{
  data_ = new T[MAX_SIZE];
  size_ = other.size_;
  for (int i = 0; i <=  other.size_; i++)
  {
    data_[i] = other.data_[i];
  }
}
template <class T>
Error_type Stack<T>::pop()
{
  if (size_ - 1 == -1)
  {
    return underflow;
  }
  else
  {
    data_[size_--] = 0;
  }
  return success;
}

template <class T>
Error_type Stack<T>::push(const T &item)
{
  if (size_ + 1 == MAX_SIZE)
  {
    return overflow;
  }
  else
  {
    data_[++size_] = item;
  }
  return success;
}
template <class T>
Error_type Stack<T>::top(T &item)
{
  if (size_ == 0)
  {
    return underflow;
  }
  else
  {
    item = data_[size_];
    return success;
  }
}
template <class T>
bool Stack<T>::empty()
{
  return size_ == 0;
}
template <class T>
int Stack<T>::size()
{
  return size_;
}

template <class T>
Stack<T>::~Stack()
{
  delete data_;
  size_ = 0;
}
template <class T>
void Stack<T>::operator=(const Stack &other)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    data_[i] = other.data_[i];
  }
  size_ = other.size_;
}
//brackets matching problem
vector<int> parentheses_match(string a)
{
  Stack<char> s;
  vector<int> Error_types(2, 0);
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] == '(' || a[i] == '[' || a[i] == '{')
    {
      Error_types[0] = i;
      s.push(a[i]);
    }

    if (a[i] == ')' || a[i] == ']' || a[i] == '}')
    {
      if (s.empty())
      {
        Error_types[1] = i;
        return Error_types;
      }
      char temp;
      s.top(temp);
      if (temp == '(' && a[i] == ')' ||
          temp == '[' && a[i] == ']' ||
          temp == '{' && a[i] == '}')
      {
        s.pop();
      }
      else
      {
        Error_types[1] = i;
        return Error_types;
      }
    }
  }
  Error_types[0] = 0;
  return Error_types;
}