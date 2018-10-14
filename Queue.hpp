#pragma once
#include "primitives.hpp"

template <class T>
class Queue
{
  private:
    T *data_;
    int size_;
    int rear_;
    int front_;

  public:
    Queue();
    Queue(const Queue &other);
    Error_type pop();
    Error_type push(const T &item);
    Error_type front(T &item);
    bool empty();
    int size();
    ~Queue();
    void operator=(const Queue &other);
};

template <class T>
Queue<T>::Queue()
{
    data_ = new T[MAX_SIZE_QUEUE];
    size_ = 0;
    rear_ = 0;
    front_ = 0;
}
template <class T>
Queue<T>::Queue(const Queue &other)
{
    data_ = new T[MAX_SIZE_QUEUE];
    size_ = other.size_;
    rear_ = other.rear_;
    front_ = other.front_;
    for (int i = 0; i <= other.size_; i++)
    {
        data_[i] = other.data_[i];
    }
}
template <class T>
Error_type Queue<T>::pop()
{
    if (size_ == 0)
    {
        return underflow;
    }
    else
    {
        data_[front_] = 0;
        front_ = (front_ + 1) % MAX_SIZE_QUEUE;
		size_--;
    }
    return success;
}

template <class T>
Error_type Queue<T>::push(const T &item)
{
    if (size_ + 1 == MAX_SIZE_QUEUE)
    {
        return overflow;
    }
    else
    {
        data_[rear_] = item;
		rear_ = (rear_ + 1) % MAX_SIZE_QUEUE;
		size_++;
    }
    return success;
}
template <class T>
Error_type Queue<T>::front(T &item)
{
    if (size_ == 0)
    {
        return underflow;
    }
    else
    {
        item = data_[front_];
        return success;
    }
}
template <class T>
bool Queue<T>::empty()
{
    return size_ == 0;
}
template <class T>
int Queue<T>::size()
{
    return size_;
}

template <class T>
Queue<T>::~Queue()
{
    delete data_;
    size_ = 0;
}
template <class T>
void Queue<T>::operator=(const Queue &other)
{
    for (int i = 0; i < MAX_SIZE_QUEUE; i++)
    {
        data_[i] = other.data_[i];
    }
    size_ = other.size_;
    rear_ = other.rear_;
    front_ = other.front_;
}
