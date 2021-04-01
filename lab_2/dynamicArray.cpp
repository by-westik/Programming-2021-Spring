#include <iostream>
#include <cstdlib>
#include "DynamicArray.h"

using namespace std;
//Я правильно объявляю конструктор? просто если написать DynamicArray(int _size = 0), то появляется ошибка
//Создание массива, указанной длины
template <class T> DynamicArray <T>:: DynamicArray(int _size)
    :size(_size)
    {

    }

//Создание динамического массива из статического массива
template <class T> DynamicArray <T>::DynamicArray(const T *_array, int _size)
    :size(_size)
    ,array(new T(_size))
    {
        for(int i = 0; i < _size; i++){
            array[i] = _array[i];
        }
    }


//Копирующий конструктор
template <class T> DynamicArray <T>::DynamicArray(const DynamicArray<T> &dynamicArray)
    :size(dynamicArray.size)
    ,array(dynamicArray.array)
    {

    }

//Вывод массива на экран
template <class T> void DynamicArray <T>::printArray() {
    for (int i = 0; i < size; i++)
        cout<< " " << array[i];
    cout << endl;
}

//Получить элемент по индексу
template <class T> const T& DynamicArray <T>::get(int index) {
    return array[index];
}

//Задать элемент по индексу
template <class T> void DynamicArray <T>::set(int index, T value) {
    array[index] = value;//Я все сломала( На этом моменте появляется ошибка сегментации
    // (ಥ﹏ಥ) памагите, пожалуйста
}

//Получить длину массива
template <class T> int DynamicArray <T>::getSize() {
    return size;
}

//Изменить размер массива
template <class T> void DynamicArray <T>::resize(int newSize) {
    if(size > newSize){
        array = (T*) realloc(array, newSize * sizeof(T));
    }else if (size < newSize){
        T* newArray  = (T*) realloc(array, newSize * sizeof(T));
        array = newArray;
    }
    size = newSize;
}

int main() {
    cout << "Int array" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    DynamicArray<int> a(arr, 5);
    a.printArray();
    //cout << a.get(3) << endl;
    DynamicArray<int> b(7);
    for(int i = 0; i < 7; i++){
        b.set(i, i);
    }
    b.printArray();
    for(int i = 0; i < b.size; i++){
        cout << "Element of index " << i << " - " << b.get(i) << endl;
    }
    cout << "Size of array a - " << a.getSize() << " or " << a.size << endl;
    cout << "Size of array b - " << b.getSize() << " or " << b.size << endl;
    cout << "Copy array" << endl;
    DynamicArray<int> a_copy(a);
    a_copy.printArray();
    cout << "Resize array a_copy - " << endl;
    a_copy.resize(3);
    cout << "New size array a_copy - " << a_copy.size << " or " << a_copy.getSize() << endl;
    a_copy.printArray();
    cout << "Resize array a - " << endl;
    a.resize(4);
    cout << "New size array a - " << a.size << " or " << a.getSize() << endl;
    a.printArray();
    cout << "Resize array b - " << endl;
    b.resize(5);
    cout << "New size array b - " << b.size << " or " << b.getSize() << endl;
    b.printArray();
    cout << "Resize array a + " << endl;
    a.resize(12);
    cout << "New size array a - " << a.size << " or " << a.getSize() << endl;
    for(int i = 4; i < 12; i++){
        a.set(i, i);
    }
    a.printArray();
    cout << "Char array" << endl;
    char arr_2[5] = "abdg";
    DynamicArray<char> a_2(arr_2, 5);
    a_2.printArray();
    return 0;
}
