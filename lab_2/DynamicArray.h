//
// Created by User on 03.04.2021.
//

#ifndef LABA_2_DYNAMICARRAY_H
#define LABA_2_DYNAMICARRAY_H

template <class T> class DynamicArray{
public:
    T* array;
    int size;
    DynamicArray(int _size)
    :size(_size)
    ,array(new T(_size))
    {

    };
    DynamicArray(const T* _array, int _size)
    :size(_size)
    ,array(new T(_size))
    {
        for(int i = 0; i < _size; i++){
            array[i] = _array[i];
        }
    };
    DynamicArray(DynamicArray <T> const &dynamicArray)
    :size(dynamicArray.size)
    ,array(dynamicArray.array)
    {

    };
    void printArray()
    {
        for (int i = 0; i < size; i++)
            std::cout<< " " << array[i];
        std::cout << std::endl;
    };
    T& get(int index)
    {
        return array[index];
    };
    void set(int index, T &value)
    {
        array[index] = value;
    }
    int getSize()
    {
        return size;
    }
    void resize(int newSize)
    {
        T* newArray = static_cast <T*> (calloc(newSize, sizeof(T)));// У меня не получилось использовать тут new(
      //Если с New,то при обычном запуске не работает
      // и выдает ошибку Process finished with exit code -1073740940 (0xC0000374) в фунциях append,prepend, insetrAt
//Но если запустить с debug то все работает
        if(size > newSize){
            for(int i = 0; i < newSize; i++){
                newArray[i] = std::move(array[i]);
            }
        } else if(size <= newSize){
            for(int i = 0; i < size; i++){
                newArray[i] = std::move(array[i]);
            }
        }
        *array = std::move(*newArray);
        size = newSize;
    }
};

#endif //LABA_2_DYNAMICARRAY_H
