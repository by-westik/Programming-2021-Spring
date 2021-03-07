#include "void_str.h"
#include <stdio.h>
#include <stdlib.h>

void* el_of_indx_void_str(const struct void_str* const this, const size_t index);
void* push_back_void_str(struct void_str* const this);
struct void_str* copy_void_str(const struct void_str* const this);
char* data_alloc_void_str(size_t size_of_data, size_t size_of_element);
void double_volume_void_str(struct void_str* const this);
void copy_data_void_str(const struct void_str* const of, struct void_str* const in);
void copy_element(void* of, void* in, const size_t size_of_element);
void delete_void_str(struct void_str str);
void delete_void_ptr_str(struct void_str* str);

int main(){
    printf("(по)Пытка\n\nСейчас попробуем сделать тесты\n");
    struct void_str str = init_void_str(5, sizeof(void));
//Я не знаю, как правильно тестить( НО попробуем
    printf("Исходная строка не void, а просто char - 'abcdf'\n");
    char proba[5] = "abcdf";
    for(int i = 0; i < 5; i++){
        *(char*)str.el_of_indx(&str, i) = proba[i];//Как бы тут void, и, наверное, неправильно преобразовывать к char, но иначе выдает ошибку...
    }
    printf("Выведем получившуюся строчку\n");
    for(int i = 0; i < 5; i++){
        printf("%c", *(char*)str.el_of_indx(&str, i));
    }
    printf("\nТеперь добавим еще 5 элементов к строке\n");
    char proba_2[5] = "ertyu";
    for(int i = 0; i < 5; i++){
        *(char*)str.push_back(&str) = proba_2[i];
    }
    printf("И снова выведем получившуюся строчку\n");
    for(int i = 0; i < 10; i++){
        printf("%c", *(char*)str.el_of_indx(&str, i));
    }
    printf("\nПопробуем скопировать void строку в другую void строку\n");
    struct void_str* str_2 = str.copy(&str);
    printf("Выведем скопированную строчку\n");
    for(int i = 0; i < 10; i++){
        printf("%c", *(char*)str_2 -> el_of_indx(str_2, i));
    }
    printf("\nТеперь добавим еще 3 элемента к новой строке\n");
    char proba_3[3] = "\tad";
    for(int i = 0; i < 3; i++){
        *(char*)str_2 -> push_back(str_2) = proba_3[i];
    }
    printf("Измененная сокпированная строка\n");
//А я могу у пользваотеля спрашивать, какой длины строку он хочет вести?
//Или лучше сделать какой-то минимальный фиксированный размер, а потом его увеличивать, до тех пор пока не нажмется Enter?
    for(int i = 0; i < 13; i++){
        printf("%c", *(char*)str_2 -> el_of_indx(str_2, i));
    }

    for(int i = 0; i < 13; i++){
        printf("%c", *(char*)str_2 -> el_of_indx(str_2, i));
    }
    printf("\nstr_2 -> element_size = %ld\nsizeof(str_2 -> element_size) = %ld\n", str_2 -> element_size, sizeof(str_2 -> element_size));
    printf("str_2 -> size = %ld\nsizeof(str_2 -> size) = %ld\n", str_2 -> size, sizeof(str_2 -> size));
    printf("str_2 -> volume = %ld\nsizeof(str_2 -> volume) = %ld\n", str_2 -> volume, sizeof(str_2 -> volume));
    delete_void_str(str);
    delete_void_str(*str_2);
    delete_void_ptr_str(str_2);
}

void* el_of_indx_void_str(const struct void_str* const this, const size_t index){
    if(index >= this -> size){
        return NULL;
    }
    return &(this -> data[index * (this -> element_size)]);
}

void copy_element(void* of, void* in, const size_t size_of_element){
    char *one = (char*) of;//Вот тут как бы идет char, потому что логично, символы как бы на вряд ли будут другого типа
    char *two = (char*) in;//Но по идее программа же должна работать со всеми типами, и какое-то нелогичное присваивание в void сразу к char.
//Но я не знаю, как иначе сделать( + Вот цикл тоже вызывает вопросы, в том плане, что для копирования одного символа, он, конечно, не очень нужен
//А вот если будут подаваться не символы, а что-нибудь другое, например, те же строки, то цикл может и нужен...
    for(size_t i = 0; i < size_of_element; ++i){
        two[i] = one[i];
    }
//Но получается, когда я буду создавать char_str, то там преобразование к char, как выше, и надо делать?
//И, соответсвенно, преобразовывать void к char функции тоже?
}

void copy_data_void_str(const struct void_str* const of, struct void_str* const in){
    for(size_t i = 0; i < of -> size; i++){
        copy_element(of -> el_of_indx(of, i), in -> el_of_indx(in, i), of -> element_size);
    }
}

char* data_alloc_void_str(size_t size_of_data, size_t size_of_element){
    if(!size_of_data){
        return NULL;
    }
    return (char *) malloc(size_of_data * size_of_element);
}

//Вот увеличение размера в два раза, чтобы, допустим, при добавлении элемента в конец не приходилось каждый раз увеличивать размер на 1, тут мне и объем и нужен
void double_volume_void_str(struct void_str* const this){
    if(!(this -> volume)){
        this -> volume = 1;
    }
    this -> volume *= 2;
    struct void_str* temporary = init_void_ptr_str(this -> volume, this -> element_size);
    copy_data_void_str(this, temporary);
    free(this -> data);
    this -> data = temporary -> data;
    free(temporary);
}

void* push_back_void_str(struct void_str* const this){
    if(this -> size >= this -> volume){
        double_volume_void_str(this);
    }
    ++(this -> size);
    return this -> el_of_indx(this, this -> size - 1);
}

struct void_str* copy_void_str(const struct void_str* const this){
    struct void_str* result = init_void_ptr_str(this -> volume, this -> element_size);
    result -> size = this -> size;
    copy_data_void_str(this, result);
    return result;
}

struct void_str init_void_str(size_t size_of_str, size_t size_of_one_element){
    struct void_str result;
    result.size = size_of_str;
    result.element_size = size_of_one_element;
    result.volume = size_of_str;
    result.data = data_alloc_void_str(result.volume, result.element_size);
    result.el_of_indx = &el_of_indx_void_str;
    result.copy = &copy_void_str;
    result.push_back = &push_back_void_str;
    return result;
}

struct void_str* init_void_ptr_str(size_t size_of_str, size_t size_of_one_element){
    struct void_str *result = (struct void_str*) calloc(1, sizeof(struct void_str));
    *result = init_void_str(size_of_str, size_of_one_element);
    return result;
}

void delete_void_str(struct void_str str){
    free(str.data);
}

void delete_void_ptr_str(struct void_str* str){
    free(str);
}