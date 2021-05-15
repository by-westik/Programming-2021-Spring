//
// Created by User on 04.04.2021.VVVVVVVVVVVVV

#ifndef LABA_2_LINKEDLIST_H
#define LABA_2_LINKEDLIST_H
#include "classesForStack.cpp"
#include "Error.cpp"

template <class T> class Item{
public:
    T data;
    Item *next;
    Item(const T& _data, Item* _next = NULL)
    :data(_data),
    next(_next)
    {
    };
};

template <class T> class LinkedList{
public:
    Item <T> *head;
    Item <T> *tail;
    int size;
    LinkedList()
    :head(NULL)
    ,tail(NULL)
    ,size(0)
    {
    };
    LinkedList(const T* array, int _size)
        :size(_size)
        {
        Item <T> *ptr, *last;
        head = new Item<T>(array[0], NULL);
        last = head;
        for (int i = 1; i < _size; i++) {
            ptr = new Item<T>(array[i], NULL);
            last -> next = ptr;
            last = ptr;
        }
        tail = last;
    }
    LinkedList(LinkedList <T> const &linkedList)
        :size(linkedList.size)
        {
        if(!linkedList.size){
            head = NULL;
            tail = NULL;
        } else {
            Item <T> *ptr = linkedList.head, *last, *temp;
            head = new Item <T> (static_cast <T> (ptr -> data), NULL);
            last = head;
            ptr = ptr -> next;
            while(ptr){
                temp = new Item <T> (static_cast <T> (ptr -> data), NULL);
                last -> next = temp;
                last = temp;
                ptr = ptr -> next;
            }
            tail = last;
        }
    }
    ~LinkedList(){
        Item <T> *ptr = this -> head, *ptr_pred = this -> head;
        while(ptr){
            ptr = ptr -> next;
            delete ptr_pred;
            ptr_pred = ptr;
        }
    }
    T& getFirst(){
        if(!head)
            throw Error("List is empty");
        return head -> data;
    }
    T& getLast(){
        if(!tail)
            throw Error("List is empty");
        return tail -> data;
    }
    T& get(int index) {
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        Item <T> *ptr = head;
        for(int i = 0; i < index; i++){
            ptr = ptr -> next;
        }
        return ptr -> data;
    }
    T& operator[](int index){
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        Item <T> *ptr = head;
        for(int i = 0; i < index; i++){
            ptr = ptr -> next;
        }
        return ptr -> data;
    }
    void getSubList(int start, int end, LinkedList <T> &subList){
        if((start < 0) || (end < 0) || (start >= size) || (end >= size) || (start > end))
            throw Error("Index out of range");
        for(int i = start; i < end; i++){
            subList.prepend(this -> get(i));
        }
        subList.size = end - start;
    }
    int getLength(){
        return this -> size;
    }
    void printList(){
        Item <T> *ptr = this -> head;
        while(ptr != NULL){
            std::cout << ptr -> data << " ";
            ptr = ptr -> next;
        }
        std::cout << std::endl;
    }
    void append(T value){
        Item <T> *newHead = new Item <T>(value, head);
        this -> head = newHead;
        if(!tail){
            this -> tail = newHead;
        }
        this -> size++;
    }
    void prepend(T value) {
        Item <T> *newTail = new Item <T> (value, NULL);
        if(!head){
            this -> head = newTail;
            this -> tail = newTail;
        } else {
            this -> tail -> next = newTail;
            this -> tail = newTail;
        }
        this -> size++;
    }
    void insertAt(T value, int index) {
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        if(!index){
            append(value);
        } else {
            Item <T> *ptr = this -> head;
            for(int i = 0; i < index - 1; i++){
                ptr = ptr -> next;
            }
            Item <T> *newElement = new Item <T> (value, ptr -> next);
            ptr -> next = newElement;
            this -> size++;
        }
    }
    void concat(LinkedList <T> *list, LinkedList <T> &newList){
        Item <T> *ptr = this -> head, *ptr_2 = list -> head;
        while(ptr){
            newList.prepend(ptr -> data);
            ptr = ptr -> next;
        }
        while(ptr_2){
            newList.prepend(ptr_2 -> data);
            ptr_2 = ptr_2 -> next;
        }
        newList.size = this -> size + list -> size;
    }
};

template <> void LinkedList <Student>::printList(){
    Item <Student> *ptr = this -> head;
    while(ptr){
        ptr -> data.printStudent();
        ptr = ptr -> next;
    }
}
template <> void LinkedList <Teacher>::printList(){
    Item <Teacher> *ptr = this -> head;
    while(ptr){
        ptr -> data.printTeacher();
        ptr = ptr -> next;
    }
}

template <> void LinkedList <Complex>::printList(){
    Item <Complex> *ptr = this -> head;
    while(ptr){
        ptr -> data.printComplex();
        ptr = ptr -> next;
    }
}



#endif //LABA_2_LINKEDLIST_H
