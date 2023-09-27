#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Element
{
    T data;
    Element* next;
    Element* prev;
};

template <class T>
class QueueList
{
private:
    Element<T>* head;
    Element<T>* tail;
    int count;
public:
    QueueList();
    ~QueueList();
    void push(T data);
    void print();
    void extract();
    void delete_all();
};

template <class T>
QueueList<T>::QueueList()
{
    head = tail = NULL;
    count = 0;
}
template <class T>
QueueList<T>::~QueueList()
{
    delete_all();
}
template <class T>
void QueueList<T>::push(T data)
{
    Element<T>* elem = new Element<T>;
    elem->next = elem->prev = NULL;
    elem->data = data;
    if (head == NULL)
        head = tail = elem;
    else
    {
        tail->next = elem;
        elem->prev = tail;
        tail = elem;
    }
    count++;
}

template <class T>
void QueueList<T>::print()
{
    Element<T>* counter = head;
    if (head == NULL)
        cout << "No elements to print" << endl;
    while (counter != NULL)
    {
        cout << counter->data <<' ';
        counter = counter->next;
    }
    cout << endl;
}
template <class T>
void QueueList<T>::extract()
{
    if (head == NULL)
        cout << "No elements to delete" << endl;
    else //FIFO
    {
        Element<T>* temp = head;
        head = head->next;
        delete[]temp;
        count--;
    }
}
template <class T>
void QueueList<T>::delete_all()
{
    while (head != NULL)
        extract();
}

int main()
{
    QueueList<int> a;
    a.push(5);
    a.push(6);
    a.push(7);
    a.print();
    a.extract();
    a.print();
    a.delete_all();
    a.print();
    return 0;
}
