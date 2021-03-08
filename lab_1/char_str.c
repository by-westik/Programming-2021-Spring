
#include "char_str.h"
#include <stdio.h>
#include <stdlib.h>

char* el_of_indx_char_str(const struct char_str* const this, const size_t index);
char push_back_char_str(struct char_str* const this, char value);
struct char_str* copy_char_str(const struct char_str* const this);
char* data_alloc_char_str(size_t size_of_data);
void double_volume_char_str(struct char_str* const this);
void copy_data_char_str(const struct char_str* const of, struct char_str* const in);
void delete_char_str(struct char_str str);
void delete_char_ptr_str(struct char_str* str);

int main(){
    printf("Попытка №2\n\nСейчас попробуем сделать тесты\n");
    struct char_str str = init_char_str(5);
    printf("Исходная строка char - 'abcdf'\n");
    char proba[5] = "abcdf";
    for(int i = 0; i < 5; i++){
        *str.el_of_indx(&str, i) = proba[i];
    }
//Нормально ли что код для void и для char в чем-то отличаются? Как, например, добавление '\0' к строке char.
    str.push_back(&str, '\0');
    printf("Выведем получившуюся строчку\n");
    for(int i = 0; i < str.size; i++){
        printf("%c", *str.el_of_indx(&str, i));
    }
    printf("\nТеперь добавим еще 5 элементов к строке\n");
    char proba_2[5] = "ertyu";
    for(int i = 0; i < 5; i++){
        str.push_back(&str, proba_2[i]);
    }
    str.push_back(&str, '\0');
    printf("И снова выведем получившуюся строчку\n");
    for(int i = 0; i < str.size; i++){
        printf("%c", *str.el_of_indx(&str, i));
    }
    printf("\nПопробуем скопировать char строку в другую char строку\n");
    struct char_str* str_2 = str.copy(&str);
    printf("Выведем скопированную строчку\n");
    printf("%s\n", str_2 -> data);
    printf("Теперь добавим еще 3 элемента к новой строке\n");
    char proba_3[3] = "\tad";
    for(int i = 0; i < 3; i++){
        str_2 -> push_back(str_2, proba_3[i]);
    }
    str_2 -> push_back(str_2, '\0');
    printf("Измененная сокпированная строка\n");
    for(int i = 0; i < str_2 -> size; i++){
        printf("%c", (*(str_2 -> el_of_indx(str_2, i))));
    }
    printf("\nstr_2 -> size = %ld\nsizeof(str_2 -> size) = %ld\n", str_2 -> size, sizeof(str_2 -> size));
    printf("str_2 -> volume = %ld\nsizeof(str_2 -> volume) = %ld\n", str_2 -> volume, sizeof(str_2 -> volume));
    delete_char_str(str);
    delete_char_str(*str_2);
    delete_char_ptr_str(str_2);
}

char* el_of_indx_char_str(const struct char_str* const this, const size_t index){
    if(index >= this -> size){
        return NULL;
    }
    return &this -> data[index];
}

char push_back_char_str(struct char_str* const this, char value){
    if(this -> size >= this -> volume){
        double_volume_char_str(this);
    }
    if(this -> data[this -> size - 1] == '\0'){
         this -> data[this -> size - 1] = value;
    } else {
         this -> data[this -> size ++] = value;
    }
}

struct char_str* copy_char_str(const struct char_str* const this){
    struct char_str* result = init_char_ptr_str(this -> volume);
    result -> size = this -> size;
    copy_data_char_str(this, result);
    return result;
}

char* data_alloc_char_str(size_t size_of_data){
    if(!size_of_data){
        return NULL;
    }
    char *result = (char*) calloc(size_of_data, sizeof(char));
    return result;
}

void double_volume_char_str(struct char_str* const this){
    if(!(this -> volume)){
        this -> volume = 1;
    }
    this -> volume *= 2;
    struct char_str* temporary = init_char_ptr_str(this -> volume);
    copy_data_char_str(this, temporary);
    free(this -> data);
    this -> data = temporary -> data;
    free(temporary);
}

void copy_data_char_str(const struct char_str* const of, struct char_str* const in){
    for(size_t i = 0; i < of -> size; i++){
        *in -> el_of_indx(in, i ) = *of -> el_of_indx(of, i);
    }
}

struct char_str init_char_str(size_t size_of_str){
    struct char_str result;
    result.size = size_of_str;
    result.volume = size_of_str;
    result.data = data_alloc_char_str(size_of_str);
    result.el_of_indx = &el_of_indx_char_str;
    result.copy = &copy_char_str;
    result.push_back = &push_back_char_str;
    return result;
}

struct char_str* init_char_ptr_str(size_t size_of_str){
    struct char_str* result = (struct char_str*) malloc(sizeof(struct char_str));
    *result = init_char_str(size_of_str);
    return result;
}

void delete_char_str(struct char_str str){
    free(str.data);
}

void delete_char_ptr_str(struct char_str* str){
    free(str);
}