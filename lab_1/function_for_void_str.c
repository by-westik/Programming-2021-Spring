#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "function_for_void_str.h"

int main(){
    struct void_str str_1 = init_void_str(5, sizeof(void));
    struct void_str* str_2 = init_void_ptr_str(3, sizeof(void));
    char char_str_1[5] = "abcmd";
    char char_str_2[3] = "Bc";
    for(int i = 0; i < 5; i++){
        *(char*)str_1.el_of_indx(&str_1, i) = char_str_1[i];
    }
    *(char*)str_1.push_back(&str_1) = '\0';
    printf("Выведем строчку str_1 '%s'  %ld   %ld\n", (char*) str_1.data, str_1.size, str_1.volume);
    *(char*)str_1.push_back(&str_1) = 'f';
    *(char*)str_1.push_back(&str_1) = '\0';
    printf("Выведем строчку str_1'%s'  %ld   %ld\n", (char*) str_1.data, str_1.size, str_1.volume);
    for(int i = 0; i < 3; i++){
        *(char*)str_2 -> el_of_indx(str_2, i) = char_str_2[i];
    }
    *(char*)str_2 -> push_back(str_2) = '\0';
    for(int i = 0; i < str_2 -> size; i++){
        printf("%c", *(char*)str_2 -> el_of_indx(str_2, i));
    }
    printf("\nВыведем строчку str_2 по другому '%s'\n", (char*) str_2 -> data);
    struct void_str* result_2 = concatenation_2(&str_1, str_2);
    printf("\nВыведем объединенные строчки '%s'\n", (char*) result_2 -> data);
    for(int i = 0; i < result_2 -> size; i++){
        printf("%c", *(char*)result_2 -> el_of_indx(result_2, i));
    }
    struct void_str* sub_str = substring(&str_1, 1, 1);
    if(sub_str){
       printf("\nsize = %ld\nПодстрока '%s'\n", sub_str -> size,(char*) sub_str -> data);
    }
    size_t index = find_substr_r(&str_1, str_2);
    printf("1.   Первое вхождение подстроки в строку начинается с индекса %ld (чувствительное к регистру)\n", index);
    size_t index_2 = find_substr_unr(&str_1, str_2);
    printf("2.   Первое вхождение подстроки в строку начинается с индекса %ld (не чувствительное к регситру)\n", index_2);
    delete_void_str(str_1);
    delete_void_str(*str_2);
    delete_void_ptr_str(str_2);
    return 0;
}

struct void_str* concatenation_2(struct void_str* void_str_1, const struct void_str* const void_str_2){
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

size_t find_substr_r(const struct void_str* const this, const struct void_str* substring){
    size_t index;
    for(size_t i = 0; i < this -> size - 1; i++){
        index = i;
        size_t j = i;
        size_t n = 0;
        while((*(char*) this -> el_of_indx(this, j) == *(char*) substring -> el_of_indx(substring, n)) && (j < this -> size - 1) && ( n < substring -> size - 1)){
            j++;
            n++;
        }
        if(n == substring -> size - 1){
             return index;
        }
    }
}

size_t find_substr_unr(const struct void_str* const this, const struct void_str* substring){
    size_t index;
    for(size_t i = 0; i < this -> size - 1; i++){
        index = i;
        size_t j = i;
        size_t n = 0;
        while((tolower(*(char*) this -> el_of_indx(this, j)) == tolower(*(char*) substring -> el_of_indx(substring, n))) && (j < this -> size - 1) && ( n < substring -$            j++;
            n++;
        }
        if(n == substring -> size - 1){
             return index;
        }
    }
}
