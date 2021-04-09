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

//Я добавила size в этот класс, потому что если где-то впоследствии нужна будет длины LinkedListSequence, то не придется проходить по списку, чтоб эту длину узнать
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
        :size(_size){
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
    ~LinkedList(){
        Item <T> *ptr = this -> head, *ptr_pred = this -> head;
        while(ptr){
            ptr = ptr -> next;
            delete ptr_pred;
            ptr_pred = ptr;
        }
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
    LinkedList <T>* getSubList(int start, int end){
        Item <T> *ptr = head, *tmp, *last;
        LinkedList <T> *subList(new LinkedList<T>());
        //std::cout << " * " << std::endl;
        for(int i = 0; i < start; i++){
            ptr = ptr -> next;
        }
        subList -> head = new Item <T>(ptr -> data, NULL);
       // std::cout << subList -> head -> data << std::endl;
        last = subList -> head;
        ptr = ptr -> next;
        for(int i = start + 1; i <  end; i++){
            tmp = new Item <T>(ptr -> data, NULL);
            last -> next = tmp;
            last = tmp;
            ptr = ptr -> next;
        }
        subList -> tail = last;
        subList -> size = end - start;
      //  std::cout << " ! " << std::endl;
      //  subList -> printList();
        return subList;
    }
    int getLength(){
        return this -> size;
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
        this -> size++;
    }
    void prepend(T value) {
        Item <T> *newTail = new Item <T> (value, NULL);
        if(!head){
            this -> head = newTail;
        } else {
            tail->next = newTail;
        }
        this -> tail = newTail;
        this -> size++;
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
            ptr -> next -> next = newElement;
            this -> size++;
        }
    }
    LinkedList <T>* concat (LinkedList <T> *list) {
        LinkedList <T> *concatList(new LinkedList(*this));
        concatList -> tail -> next = list -> head;
        concatList -> tail = list -> tail;
        concatList -> size = this -> size + list -> size;
        return concatList;
    }
};
#endif //LABA_2_LINKEDLIST_H
