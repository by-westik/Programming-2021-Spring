#include <iostream>
#include <cstdlib>

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
            :size(dynamicArray.size)
            ,array(dynamicArray.array)
            {

            }
    //Вывод массива на экран
    void printArray(){
        for (int i = 0; i < size; i++)
            cout<< " " << array[i];
        cout << endl;
    };
    //Получить элемент по индексу
    T get(const int &index){
        return array[index];
    };
    //Задать элемент по индексу
    void set(int index, T value){
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
    void resize(const int &newSize){
        if(size > newSize){
            array = (T*) realloc(array, newSize * sizeof(T));
        }else if (size < newSize){
          //  T* newArray = array;
            T* newArray  = (T*) realloc(array, newSize * sizeof(T));
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
