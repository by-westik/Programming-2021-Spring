#include <iostream>
#include "LinkedList.h"

using namespace std;

//Консруктор одного элемента списка
template <class T> Item <T>::Item(const T& _data, Item* _next)
    :data(_data)
    ,next(_next)
    {

    }

//Конструктор пустого списка
template <class T> LinkedList <T>::LinkedList()
    :head(NULL)
    ,tail(NULL)
    {

    }

//Создание списка из массива
template <class T> LinkedList <T>::LinkedList(const T *array, int size){
    Item <T> *ptr, *last;
    head = new Item<T>(array[0], NULL);//А если вместо int будет string, например, то по идее нужно сипользовать move?
    last = head;
    for (int i = 1; i < size; i++) {
        ptr = new Item<T>(array[i], NULL);
        last -> next = ptr;
        last = ptr;
    }
    tail = last;
    }

//Копирующий конструктор
template <class T> LinkedList <T>::LinkedList(const LinkedList<T> &linkedList) {
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

//Получение первого элемента из списка
template <class T> T LinkedList <T> ::getFirst() {
    return head -> data;
}

//Получение последнего элемента из списка
template <class T> T LinkedList <T> ::getLast() {
    return tail -> data;
}

//Получение элемента по индексу
template <class T> T LinkedList <T> ::get(const int index) {
    Item <T> *ptr = head;
    for(int i = 0; i < index; i++){
        ptr = ptr -> next;
    }
    return ptr -> data;
}
//В трех функциях выше нужно возвращать именно элемент, то есть указеталь, а  не его значение?

//Получение подсписка
template <class T> LinkedList <T> LinkedList <T> ::getSubList(const int start, const int end){
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

//Получение длины списка
template <class T> int LinkedList <T>::getLength() {
    Item <T> *ptr = head;
    int len = 0;
    while(ptr){
        len++;
        ptr = ptr -> next;
    }
    return len;
}

//Вывод списка на экран
template <class T> void LinkedList <T>::printList() {
    Item <T> *ptr = head;
    while(ptr){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}

//Добавление элемента в начало списка
template <class T> void LinkedList <T>::append(T value) { //Здесь надо передавать ссылку на value?
    Item <T> *newHead = new Item <T> (value, head);
    this -> head = newHead;
    if(!tail){
        this -> tail = newHead;
    }
}

//Добавление элемента в конец списка
template <class T> void LinkedList <T>::prepend(T value) {//Тут тоже по ссылке значение надо передавать?
    Item <T> *newTail = new Item <T> (value, NULL);
    if(!head){
        this -> head = newTail;
    } else {
        tail->next = newTail;
    }
    this -> tail = newTail;
}

//Вставка элемента по индексу
template <class T> void LinkedList <T>::insertAt(T value, int index) {
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

//Объединение двух списков
template <class T> LinkedList <T> LinkedList <T>::concat(LinkedList<T> *list) {
    tail -> next = list -> head;
    this -> tail = list -> tail;
}

int main() {
    cout << "Hello, World!" << endl;
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList <int> a;
    LinkedList <int> b(array, 5);
    b.printList();
    LinkedList<int> c(b);
    c.printList();
    cout << "Value of tail is " << c.tail -> data << endl;
    cout << "Value of first element " << c.getFirst() << endl;
    cout << "Value of last element " << c.getLast() << endl;
    cout << "Element of index 3 - " << c.get(3) << endl;
    cout << "Create sublist" << endl;
    LinkedList <int> sub = c.getSubList(0, 3);
    sub.printList();
    cout << "Length of list a - " << a.getLength() << endl;
    cout << "Length of list b - " << b.getLength() << endl;
    cout << "Length of list c - " << c.getLength() << endl;
    cout << "Length of sublist - " << sub.getLength() << endl;
    cout << "Append two elements in list a" << endl;
    a.append(4);
    a.append(7);
    a.printList();
    cout << "Append five elements in list b" << endl;
    for(int i = 5; i < 10; i++){
        b.append(i);
    }
    b.printList();
    cout << "Append one element in list c" << endl;
    c.append(10);
    c.printList();
    cout << "Append seven elements in sublist" << endl;
    for(int i = 6; i < 13; i++){
        sub.append(i);
    }
    sub.printList();
    cout << "Prepend two elements in list a" << endl;
    a.prepend(11);
    a.prepend(12);
    cout << "a head - " << a.head -> data<< " or " << a.getFirst() << " a tail - " << a.tail -> data << " or " << a.getLast() << endl;
    a.printList();
    cout << "Prepend four elements in list b" << endl;
    for(int i = 7; i < 11; i++){
        b.prepend(i);
    }
    cout << "b head - " << b.head -> data<< " or " << b.getFirst() << " b tail - " << b.tail -> data << " or " << b.getLast() << endl;
    b.printList();
    LinkedList<int> empty;
    cout << "Append element in empty list" << endl;
    empty.append(7);
    empty.printList();
    cout << "empty head - " << empty.head -> data<< " or " << empty.getFirst() << " empty tail - " << empty.tail -> data << " or " << empty.getLast() << endl;
    cout << "Prepend element in empty_2 list" << endl;
    LinkedList<int> empty_2;
    empty_2.prepend(9);
    empty_2.printList();
    cout << "empty_2 head - " << empty_2.head -> data<< " or " << empty_2.getFirst() << " empty tail - " << empty_2.tail -> data << " or " << empty_2.getLast() << endl;
    cout << "Insert 13 in list b position 7" << endl;
    b.insertAt(13, 7);
    b.printList();
    cout << "Append list a to list b" << endl;
    b.concat(&a);
    b.printList();
    cout << "b head - " << b.head -> data<< " or " << b.getFirst() << " b tail - " << b.tail -> data << " or " << b.getLast() << endl;
    return 0;
}
