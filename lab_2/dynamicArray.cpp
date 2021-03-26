#include <iostream>
#include <vector>
using namespace std;

template <class T> class DynamicArray{
public:
    T* array;
    int size;
    //Создание массива, указанной длины
    DynamicArray(int _size = 0)
            :size(_size)
            ,array(new T(_size))
            {

            }
    //Копирующий конструктор
    DynamicArray(const T* _array, int _size)
            :size(_size)
            ,array(new T(_size))
            {
                for(int i = 0; i < _size; i++){
                array[i] = _array[i];
                }
            }
    //Копирующий конструктор, но он копирует не из простого массива, а из DynamicArray
    DynamicArray(DynamicArray <T> const &dynamicArray)
            :size(dynamicArray -> size)
            ,array(dynamicArray -> array)
            {

            }
    //Вывод массива на экран
    void printArray(){
        for (int i = 0; i < size; i++)
            cout<< " " << *(array + i);
        cout << endl;
    };
    //Получить элемент по индексу
    T Get(int index){
        return array[index];
    };
    //Задать элемент по индексу
    void Set(int index, T value){
        array[index] = value;
    };
    //Получить длину массива(Почему мы не можем просто делать, где надо DynamicArray.size&)
    int getSize(){
        return size;
    }
    /* Изменить длину массива
     * Если new_size > size - выделить память и скопировать туда предыдущую
     * Если new_size < size - обрезать лишние элементы
     */
   /* void Resize(int newSize){
        if (size < newSize){
            array = array[newSize];
        }
        //Что-то не получилось обрузать :( А вектор можно использовать?(ниже я с ним сделала)
    }*/
};

template <class T> class DynamicArrayVector{
public:
    vector <T> array;
    int size;
    //Создание массива, указанной длины
    DynamicArrayVector(int _size = 0)
            :size(_size)
            ,array(vector <T> (_size))
             {

             }
    //Копирующий конструктор
    DynamicArrayVector(const vector <T> _array, int _size)
            :size(_size)
            ,array(vector <T> (_size))
            {
                for(int i = 0; i < _size; i++){
                array[i] = _array[i];
                }
            }
    //Копирующий конструктор, но он копирует не из простого массива, а из DynamicArray
    DynamicArrayVector(DynamicArrayVector <T> const &dynamicArray )
            :size(dynamicArray.size)
            ,array(dynamicArray.array)
             {

             }
    //Вывод массива на экран
    void printArrayVector(){
        for (int i = 0; i < size; i++)
            cout<< " " << array[i];
        cout << endl;
    };
    //Получить элемент по индексу
    T Get(int index){
        return array[index];
    };
    //Задать элемент по индексу
    void Set(int index, T value){
        array[index] = value;
    };
    //Получить длину массива(Почему мы не можем просто делать, где надо DynamicArray.size&)
    int getSize(){
        return size;
    }
    /* Изменить длину массива
     * Если new_size > size - выделить память и скопировать туда предыдущую
     * Если new_size < size - обрезать лишние элементы
     */
    void Resize(int newSize){
        if(size > newSize){
            array.resize(newSize);
        } else if(size < newSize){
            vector <T> newArray = array;
            array.resize(newSize);
            array = newArray;
        }
        size = newSize;
    }
};



int main() {
    cout << "Int array" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    DynamicArray<int> a(arr, 5);
    a.printArray();
    DynamicArray<int> b(7);
    for(int i = 0; i < 7; i++){
        b.Set(i, i);
    }
    b.printArray();
    for(int i = 0; i < b.size; i++){
        cout << "Element of index " << i << " - " << b.Get(i) << endl;
    }
    cout << "Size of array a - " << a.getSize() << " or " << a.size << endl;
    cout << "Size of array b - " << b.getSize() << " or " << b.size << endl;
    vector <int> v{2,3,4,5,6};
    DynamicArrayVector <int> vc(v, 5);
    DynamicArrayVector <int> vc_2(8);
    for(int i = 0; i < 8; i++){
        vc_2.Set(i, i);
    }
    DynamicArrayVector <int> vc_copy(vc);
    vc.printArrayVector();
    vc_2.printArrayVector();
    vc_copy.printArrayVector();
    for(int i = 0; i < 5; i++){
        cout << "Element of index " << i << " - " << vc.Get(i) << endl;
    }
    cout << "Size of array vc - " << vc.getSize() << " or " << vc.size << endl;
    vc.Resize(12);
    cout << "(After resize vc) New size of array vc - " << vc.getSize() << " or " << vc.size << endl;
    cout << "Fill vc" << endl;
    for(int i = 5; i < 12; i++){
        vc.Set(i, i);
    }
    vc.printArrayVector();
    vc_2.Resize(3);
    cout << "(After resize vc_2) New size of array vc_2 - " << vc_2.getSize() << " or " << vc_2.size << endl;
    vc_2.printArrayVector();
    cout << "Char array" << endl;
    char arr_2[5] = "abdg";
    DynamicArray<char> a_2(arr_2, 5);
    a_2.printArray();
    return 0;
}
