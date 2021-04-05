//
// Created by User on 04.04.2021.
//

#ifndef LABA_2_LINKEDLIST_H
#define LABA_2_LINKEDLIST_H

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
    LinkedList()
    :head(NULL)
    ,tail(NULL)
    {

    };//Можно ли внутри листа еще его длину хранить, чтоб все время не считать?
    LinkedList(const T* array, int size){
        Item <T> *ptr, *last;
        head = new Item<T>(array[0], NULL);
        last = head;
        for (int i = 1; i < size; i++) {
            ptr = new Item<T>(array[i], NULL);
            last -> next = ptr;
            last = ptr;
        }
        tail = last;
    }
    LinkedList(LinkedList <T> const &linkedList) {
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
    T& getFirst(){
        return head -> data;
    }
    T& getLast(){
        return tail -> data;
    }
    T& get(int index) {
        Item <T> *ptr = head;
        for(int i = 0; i < index; i++){
            ptr = ptr -> next;
        }
        return ptr -> data;
    }
    LinkedList <T> getSubList(const int start, const int end){
        Item <T> *ptr = head, *tmp, *last;
        LinkedList <T> subList;
        for(int i = 0; i < start; i++){
            ptr = ptr -> next;
        }
        subList.head = new Item <T>(ptr -> data, NULL);
        last = subList.head;
        ptr = ptr -> next;
        for(int i = start + 1; i <  end; i++){
            tmp = new Item <T>(ptr -> data, NULL);
            last -> next = tmp;
            last = tmp;
            ptr = ptr -> next;
        }
        subList.tail = last;
        return subList;
    }
    int getLength(){
        Item <T> *ptr = head;
        int len = 0;
        while(ptr){
            len++;
            ptr = ptr -> next;
        }
        return len;
    }
    void printList(){
        Item <T> *ptr = head;
        while(ptr){
            std::cout << ptr -> data << " ";
            ptr = ptr -> next;
        }
        std::cout << std::endl;
    }
    void append(T value){
        Item <T> *newHead = new Item <T> (value, head);
        this -> head = newHead;
        if(!tail){
            this -> tail = newHead;
        }
    }
    void prepend(T value) {
        Item <T> *newTail = new Item <T> (value, NULL);
        if(!head){
            this -> head = newTail;
        } else {
            tail->next = newTail;
        }
        this -> tail = newTail;
    }
    void insertAt(T value, int index) {
        if(!index){
            append(value);
        } else {
            Item <T> *ptr = head;
            for(int i = 0; i < index - 1; i++){
                ptr = ptr -> next;
            }
            Item <T> *newElement = new Item <T> (value, ptr -> next -> next);
            ptr -> next = newElement;
        }
    }
    LinkedList <T> concat (LinkedList <T> *list) {
        tail -> next = list -> head;
        this -> tail = list -> tail;
    }
};
#endif //LABA_2_LINKEDLIST_H
