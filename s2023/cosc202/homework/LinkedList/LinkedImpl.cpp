/*
Author: Isaac abella

Description: Dynamically Allocated Arrays in c++
c++ has no implementation to do things such as erase, insert, and display
dynamically allocated arrys

however we can make our own implementations using template
I will also assume that making a template array for this will be sufficient, however we can do more data types!
*/

#include <iostream>

template <class T>
class Dynamic
{
private:
    T *tracker;
    int length;
    int next;

public:
    Dynamic(int size);
    ~Dynamic();

    T &operator[](int index);

    // Idk what functions you guys asked for so I'm just gonna implement a basic vector.
    int add(T val);
    void print();
    void clear();
    bool is_empty();
    bool is_full();
    size_t size();
    void pop();
};

// initialization
template <class T>
Dynamic<T>::Dynamic(int size)
{
    tracker = new T[size];
    length = size;
    next = 0;
}

template <class T>
Dynamic<T>::~Dynamic()
{
    delete[] tracker;
}

template <class T>
T &Dynamic<T>::operator[](int index)
{
    if (index < 0 || index > length)
    {
        std::runtime_error e("index out of bounds!\n");
    }
    return index[tracker];
}

template <class T>
int Dynamic<T>::add(T val)
{
    // checks to see if the vector in this case needs to be resized by expanding.
    if (next == length)
    {
        // when you add to vectors you double the version so we double the length
        T *tracker_increase = new T[length * 2];
        for (int i = 0; i < length; i++)
        {
            tracker_increase = tracker[i];
        }
        delete tracker;
        tracker = tracker_increase;
        length *= 2;
    }
    tracker[next++];
}

template <class T>
void Dynamic<T>::print()
{
    for (int i = 0; i < next; i++)
    {
        std::cout << tracker[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void Dynamic<T>::clear()
{
    delete[] tracker;
    tracker = new T[1];
    next = 0;
}

template <class T>
bool Dynamic<T>::is_empty()
{
    return next == 0;
}

template <class T>
bool Dynamic<T>::is_full()
{
    return next == length;
}

template <class T>
size_t Dynamic<T>::size()
{
    return next;
}

template <class T>
void Dynamic<T>::pop()
{
    if (!is_empty())
    {
        T *burner = next - 1;
        next--;
        delete burner;
    }
}
