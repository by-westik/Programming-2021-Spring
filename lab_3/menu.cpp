#ifndef LAB_3_MENU_CPP
#define LAB_3_MENU_CPP

#include "binaryHeap.h"
#include <iostream>

const char *MAIN[] = {"0. Выход",  "1. Int", "2. Double"};
const int MAIN_SIZE = sizeof(MAIN) / sizeof(MAIN[0]);

const char *FUNC[] = {"0. Выход", "1. Вставка элемента", "2. Удаление максимального элемента", "3. Изменение элемента по индексу", "4. Поиск элемента в куче", "5. Извлечение поддерева по индексу", "6. Сортировка массива с помощью кучи"};
const int FUNC_SIZE = sizeof(FUNC) / sizeof(FUNC[0]);

void menu();
int dialog(const char *msgs[], const int size);
template <class T> void createHeap();
template <class T, template <class> class DynamicArray> void functionForHeap(binaryHeap <T, DynamicArray> *heap);

int main(){
    menu();
};

void menu(){
    bool chosenType = true;
    int a = 0;
    while(chosenType){
        a = dialog(MAIN, MAIN_SIZE);
        switch(a){
            case 0:
                chosenType = false;
                break;
            case 1:
                {
                    createHeap <int> ();
                }
                break;
            case 2:
                {
                    createHeap <double> ();
                }
                break;
            default:
                std::cout << "Error" << std::endl;
                chosenType = false;
                break;
        };
    };
};

int dialog(const char *msgs[], const int size){
    for(int i = 0; i < size; i++){
        std::cout << msgs[i] << std::endl;
    }
    std::cout << "Make your choice:" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
};

template <class T> void createHeap(){
    cout << "Введите количество элементов в куче" << endl;
    int n = 0;
    cin >> n;
    T array[n];
    for(int i = 0; i < n; i++){
        cout << "Введите " << i << "-ый элемент кучи" << endl;
        T a;
        cin >> a;
        array[i] = std::move(a);
    };
    binaryHeap <T, DynamicArray> *heap = new binaryHeap <T, DynamicArray> (array, n);
    cout << "Binary max-heap" << endl;
    heap -> printHeap();
    functionForHeap <T, DynamicArray> (heap);
    delete heap;
};


template <class T, template <class> class DynamicArray> void functionForHeap(binaryHeap <T, DynamicArray> *heap){
    bool chosenFunc = true;
    int a = 0;
    while(chosenFunc){
        a = dialog(FUNC, FUNC_SIZE);
        switch(a){
            case 0:
                cout << "Exit" << endl;
                chosenFunc = false;
                break;
            case 1:
                {
                    cout << "Введите значение нового элемента" << endl;
                    T newKey;
                    cin >> newKey;
                    heap -> insertKey(newKey);
                    heap -> printHeap();
                };
                break;
            case 2:
                {
                    cout << "Максимальный элемент - " << heap -> getMax() << endl;
                    heap -> deleteMax();
                    heap -> printHeap();
                };
                break;
            case 3:
                {
                    cout << "Введите индекс" << endl;
                    int i;
                    cin >> i;
                    try {
                        cout << "Элемент по индексу " << i << " равен " << heap -> get(i) << endl;
                        cout << "Введите новое значение элемента (не меньше предыдущего)" << endl;
                        T newKey;
                        cin >> newKey;
                        heap -> updateKey(i, newKey);
                        heap -> printHeap();
                    }
                    catch (Error &error){
                        std::cout << "Error: " << error.getError() << std::endl;
                    };
                };
                break;
            case 4:
                {
                    cout << "Введите значение элемента для поиска" << endl;
                    T key;
                    cin >> key;
                    if(heap -> findKey(key) != -1){
                        cout << "Элемент находится по индексу " << heap -> findKey(key) << endl;
                    }else {
                        cout << "Элемент не найден" << endl;
                    };
                };
                break;
            case 5:
                {
                    cout << "Введите индекс, с которого извлекается поддерево" << endl;
                    int n;
                    cin >> n;
                    binaryHeap <T, DynamicArray> *subHeap = new binaryHeap <T, DynamicArray> ();
                    try{
                        heap -> getSubHeap(n, *subHeap);
                        subHeap -> printHeap();
                    }
                    catch(Error &error){
                        std::cout << "Error: " << error.getError() << std::endl;
                    };
                    delete subHeap;
                };
                break;
            case 6:
                {
                    cout << "Введите количество элементов в массиве" << endl;
                    int n = 0;
                    while(n <= 0){
                        cin >> n;
                    };
                    T array[n];
                    for(int i = 0; i < n; i++){
                        cout << "Введите значение " << i << "-ого элемента массива" << endl;
                        T temp;
                        cin >> temp;
                        array[i] = temp;
                    };
                    heap -> heapSort(array, n);
                    for(int i = 0; i < n; i++){
                        cout << array[i] << " ";
                    };
                    cout << endl;
                };
                break;
            default:
                cout << "Error" << endl;
                chosenFunc = false;
                break;
        };
    };
};