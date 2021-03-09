#include <stdlib.h>
#include <stdio.h>

#include "function_for_void_str.h"

struct void_str concatenation(const struct void_str const void_str_1, const struct void_str const void_str_2);

int main(){
    struct void_str str_1 = init_void_str(5, sizeof(void));
    struct void_str* str_2 = init_void_ptr_str(7, sizeof(void));
    char char_str_1[5] = "abcdf";
    char char_str_2[7] = "zxcvbnm";
    for(int i = 0; i < 5; i++){
        *(char*)str_1.el_of_indx(&str_1, i) = char_str_1[i];
    }
    *(char*)str_1.push_back(&str_1) = '\0';
    printf("Выведем строчку по другому '%s'   %ld\n", (char*) str_1.data, str_1.size);
    *(char*)str_1.push_back(&str_1) = 'f';
    *(char*)str_1.push_back(&str_1) = '\0';
    printf("Выведем строчку по другому '%s'   %ld\n", (char*) str_1.data, str_1.size);
    for(int i = 0; i < 7; i++){
        *(char*)str_2 -> el_of_indx(str_2, i) = char_str_2[i];
    }
    *(char*)str_2 -> push_back(str_2) = '\0';
    for(int i = 0; i < str_2 -> size; i++){
        printf("%c", *(char*)str_2 -> el_of_indx(str_2, i));
    }
    printf("\nВыведем строчку по другому '%s'\n", (char*) str_2 -> data);
    struct void_str result = concatenation(str_1, *str_2);
    printf("\nВыведем строчку по другому '%s'\n", (char*) result.data);
    for(int i = 0; i < result.size; i++){
        printf("%c", *(char*)result.el_of_indx(&result, i));
    }
    return 0;
}

struct void_str concatenation(const struct void_str const void_str_1, const struct void_str const void_str_2){
    struct void_str result = init_void_str(void_str_1.size + void_str_2.size - 1, sizeof(void));
    size_t i = 0;
    for(i = 0; i < void_str_1.size - 1; i++){
        *(char*)result.el_of_indx(&result, i) = *(char*)void_str_1.el_of_indx(&void_str_1, i);
    }
    size_t j = 0;
    for(i; i < result.size; i++){
        *(char*)result.el_of_indx(&result, i) = *(char*)void_str_2.el_of_indx(&void_str_2, j);
        j++;
    }
    return result;
}