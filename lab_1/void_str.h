#include <stdlib.h>

struct void_str{
    size_t element_size; //Размер одного эелмента
    size_t size; //Длина строки
    size_t volume; //Это объем, выделенной под строчку памяти
    char* data; //Тут будет значения элементов
    //По идее тут нужен void* data, но когда я потом хочу обратиться, например, к элементу под 3 индексом,то увы( не получается
    //потому что арифметические операции с void указетелем, как я поняла, не выполняются
    //*Функция, возвращающая элемент по заданному индексу
    void* (*el_of_indx)(const struct void_str* const this, const size_t index);
    //*Функция, помещающая новый элемент в конец строки
    void* (*push_back)(struct void_str* const this);
    //*Функция, копирующая поршлую строку, возваращет потом указательна копию
    struct void_str* (*copy)(const struct void_str* const this);
};

struct void_str init_void_str(size_t size_of_str, size_t size_of_one_element);
struct void_str* init_void_ptr_str(size_t size_of_str, size_t size_of_one_element);

void delete_void_str(struct void_str str);
void delete_void_ptr_str(struct void_str* str);

