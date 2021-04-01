//
// Created by User on 01.04.2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

template <class T> class Item{
public:
    T data;
    Item *next;
    Item(const T& _data, Item* _next);
};

template <class T> class LinkedList{
public:
    Item <T> *head;
    Item <T> *tail;
    LinkedList();
    LinkedList(const T* array, int size = 0);
    LinkedList(LinkedList <T> const &linkedList);
    T getFirst();
    T getLast();
    T get(const int index);
    LinkedList <T> getSubList(const int start, const int end);
    int getLength();
    void printList();
    void append(T value);
    void prepend(T value);
    void insertAt(T value, int index);
    LinkedList <T> concat (LinkedList <T> *list);
};
#endif //LINKEDLIST_LINKEDLIST_H
