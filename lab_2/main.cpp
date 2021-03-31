#include <iostream>

using namespace std;

template <class T> class Item{
public:
    T data;
    Item *next;
    Item(const T& _data, Item* _next = NULL)
    :data(_data),
    next(_next)
    {

    }
    Item():next(NULL){};
};

template <class T> class LinkedList{
public:
    Item <T> *head;
    Item <T> *tail;
    //Создание пустого списка
    LinkedList()
        :head(NULL)
        ,tail(NULL)
        {

        }
    //Создание списка из массива
    LinkedList(const T* array, int size = 0) {
        Item <T> *ptr, *last;
        head = new Item<T>(array[0], NULL);//А если вместо int будет string, например, то по идее нужно сипользовать move?
        last = head;
        for (int i = 1; i < size; i++) {
            ptr = new Item<T>(array[i], NULL);
            last -> next = ptr;
            last = ptr;
        }
        tail = last;
    };
    //Копирующий конструктор
    LinkedList(LinkedList <T> const &linkedList) {
        Item <T> *ptr = linkedList.head, *last, *temp;
        head = new Item <T> (static_cast <T> (ptr -> data), NULL);
        last = head;
        ptr = ptr -> next;
        while(ptr != NULL){
            temp = new Item <T> (static_cast <T> (ptr -> data), NULL);
            last -> next = temp;
            last = temp;
            ptr = ptr -> next;
        }
        tail = last;
    }
    //Получение первого элемента из списка
    T getFirst(){
        return head -> data;
    }
    //В этих трех функциях надо получать значение элемента или указетель на сам элемент?
    //Получение последнего элемента из списка
    T getLast(){
        return tail -> data;
    }
    //Получение элемента по индексу
    T get(const int index){
        Item <T> *ptr = head;
        for(int i = 0; i < index; i++){
            ptr = ptr -> next;
        }
        return ptr -> data;
    }
    //Получение подлиста
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
};


int main() {
    cout << "Hello, World!" << endl;
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList <int> a();
    LinkedList <int> b(array, 5);
    Item <int> *ptr = b.head;
    for(int i = 0; i < 5; i++){
        cout << ptr -> data << endl;
        ptr = ptr -> next;
    }
    LinkedList<int> c(b);
    Item <int> *ptr_2 = c.head;
    for(int i = 0; i < 5; i++){
        cout << ptr_2 -> data << endl;
        ptr_2 = ptr_2 -> next;
    }
    cout << "Value of tail is " << c.tail -> data << endl;
    cout << "Value of first element " << c.getFirst() << endl;
    cout << "Value of last element " << c.getLast() << endl;
    cout << "Element of index 3 - " << c.get(3) << endl;
    cout << "Create sublist" << endl;
    LinkedList <int> sub = c.getSubList(0, 3);
    Item <int> *ptr_3 = sub.head;
    for(int i = 0; i < 3; i++){
        cout << ptr_3 -> data << endl;
        ptr_3 = ptr_3 -> next;
    }
    return 0;
}
