#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "function_for_void_str.h"

int funk(int value);
struct void_str* create_void_str();

int main(){
    printf("Введите первую строку\n");
    struct void_str* str_1 = create_void_str();
    printf("Введите вторую строку\n");
    struct void_str* str_2 = create_void_str();
    printf("Первая строка - '%s'\n", (char*) str_1 -> data);
    printf("Вторая строка - '%s'\n", (char*) str_2 -> data);
    struct void_str* result_con = concatenation(str_1, str_2);
    printf("Объединение двух строк - '%s'\n", (char*) result_con -> data);
    size_t index_unr_2 = find_substr(str_1, str_2, tolower);
    printf("Первое вхождение строки 2 в строку 1 начинается по индексу - %ld (не чувствительное к регистру)\n", index_unr_2);
    size_t index_r_2 = find_substr(str_1, str_2, funk);
    printf("Первое вхождение строки 2 в строку 1 начинается по индексу - %ld (чувствительное к регистру)\n", index_r_2);
    size_t start, end;
    printf("Введите первый индекс подсторки, который хотите выделить в строке 1\n");
    scanf("%ld", &start);
    printf("Введите второй индекс подсторки, который хотите выделить в строке 1\n");
    scanf("%ld", &end);
    struct void_str* sub_str = substring(str_1, start, end);
    printf("Подстрока - '%s'\n", (char*) sub_str -> data);
    delete_void_str(*str_1);
    delete_void_str(*str_2);
    delete_void_str(*result_con);
    delete_void_str(*sub_str);
    delete_void_ptr_str(str_1);
    delete_void_ptr_str(str_2);
    delete_void_ptr_str(result_con);
    delete_void_ptr_str(sub_str);
    return 0;
}

int funk(int value){
    return value;
}

struct void_str* create_void_str(){
    void *buf[80];
    void *data_result = NULL;
    size_t len = 0;
    size_t n = 0;
    do{
        n = scanf("%80[^\n]", (char*) buf);
        if(n < 0){
            if(!data_result){
                printf("Введена пустая строка\n");
                return NULL;
            }
        } else if (n > 0){
            size_t part_len = strlen((char*)buf);
            size_t str_len = len + part_len;
            data_result = realloc(data_result, str_len + 1);
            memcpy((char*) (data_result + len),(char*) buf, part_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);
    struct void_str* result = init_void_ptr_str(len + 1, sizeof(void));
    memcpy((char*) result -> data, (char*) data_result, len);
    *(char*) result -> el_of_indx(result, result -> size - 1) = '\0';
    free(data_result);
    return result;
}

size_t find_substr(const struct void_str* const this, const struct void_str* substring, int function(int)){
    size_t index;
    for(size_t i = 0; i < this -> size - 1; i++){
        index = i;
        size_t j = i;
        size_t n = 0;
        while((function(*(char*) this -> el_of_indx(this, j)) == function(*(char*) substring -> el_of_indx(substring, n))) && (j < this -> size - 1) &&  ( n < substrin$            j++;
            n++;
        }
        if(n == substring -> size - 1){
             return index;
        }
    }
}

struct void_str* substring(const struct void_str* const this, const size_t start, const size_t end){
    if((this -> size <= start) || (this -> size <= end)){
        printf("\n\n***Выход за пределы строки***\n\n");
        return NULL;
    }
    if(start == end){
        printf("\n\n***Введен пустой диапазон для выделения подстроки***\n\n");
        return NULL;
    }
    struct void_str* sub_str = init_void_ptr_str(end - start + 1, sizeof(void));
    size_t i = 0;
    for(size_t j = start; j < end; j++){
        *(char*) sub_str -> el_of_indx(sub_str, i) = *(char*) this -> el_of_indx(this, j);
         i++;
    }
    *(char*) sub_str -> el_of_indx(sub_str, i) = '\0';
    return sub_str;
}

struct void_str* concatenation(struct void_str* void_str_1, const struct void_str* const void_str_2){
    if(void_str_1 -> volume >= void_str_1 -> size + void_str_2 -> size){
        for(size_t i = 0; i < void_str_2 -> size - 1; i++){
            *(char*)void_str_1 -> push_back(void_str_1) = *(char*) void_str_2 -> el_of_indx(void_str_2, i);
        }
        *(char*) void_str_1 -> push_back(void_str_1) = '\0';
        return void_str_1;
    }
    struct void_str* result = init_void_ptr_str(void_str_1 -> size + void_str_2 -> size - 1, sizeof(void));
    size_t i = 0;
    for(i = 0; i < void_str_1 -> size - 1; i++){
        *(char*)result -> el_of_indx(result, i) = *(char*)void_str_1 -> el_of_indx(void_str_1, i);
    }
    size_t j = 0;
    for(i; i < result -> size; i++){
        *(char*)result -> el_of_indx(result, i) = *(char*)void_str_2 -> el_of_indx(void_str_2, j);
        j++;
    }
    return result;
}
