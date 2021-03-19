#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "function_for_void_str.h"

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
                printf("\n\n***Введена пустая строка***\n\n");
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
    if(len == 0){
        return NULL;
    }
    struct void_str* result = init_void_ptr_str(len + 1, sizeof(void));
    memcpy((char*) result -> data, (char*) data_result, len);
    *(char*) result -> el_of_indx(result, result -> size - 1) = '\0';
    free(data_result);
    return result;
}

int find_substr(const struct void_str* const this, const struct void_str* substring, int function(int)){
    int index;
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
    return -1;
}

size_t create(int n, size_t len){
    if(n >= 0){
        return n;
    }
    return(len - 1 + n);
}

struct void_str* substring(const struct void_str* const this, int start, int end){
    start = create(start, this -> size);
    end = create(end, this -> size);
    if(!this){
        printf("\n\n***Введен пустой указатель на строку!***\n\n");
    }
    if((this -> size <= start) || (this -> size <= end)){
        printf("\n\n***Выход за пределы строки!***\n\n");
        return NULL;
    }
    if(start > end){
        int tmp = start;
        start = end;
        end = tmp;
    }
    struct void_str* sub_str = init_void_ptr_str(end - start + 2, sizeof(void));
    if(start == end){
        *(char*) sub_str -> el_of_indx(sub_str, 0) = *(char*) this -> el_of_indx(this, start);
        *(char*) sub_str -> el_of_indx(sub_str, 1) = '\0';
    } else {
        size_t i = 0;
        for(size_t j = start; j <= end; j++){
            *(char*) sub_str -> el_of_indx(sub_str, i) = *(char*) this -> el_of_indx(this, j);
            i++;
        }
        *(char*) sub_str -> el_of_indx(sub_str, i) = '\0';
    }
    return sub_str;
}

struct void_str* concatenation(struct void_str* void_str_1, const struct void_str* const void_str_2){
    if(void_str_1 -> volume < void_str_1 -> size + void_str_2 -> size){
        void_str_1 -> reserve(void_str_1, void_str_1 -> size + void_str_2 -> size - 1);
    }
    for(size_t i = 0; i < void_str_2 -> size - 1; i++){
        *(char*)void_str_1 -> push_back(void_str_1) = *(char*) void_str_2 -> el_of_indx(void_str_2, i);
    }
    *(char*) void_str_1 -> push_back(void_str_1) = '\0';
    return void_str_1;
}


struct void_str* delete_all_sub_str(struct void_str* this, const struct void_str* const sub_str){
    if(this -> size == 1){
        printf("\n\n***Из пустой строки нельзя удалить элементы!***\n\n");
        return NULL;
    }
    if(this -> size < sub_str -> size){
        printf("\n\n***Длина подстроки не может превышает длину строки!***\n\n");
        return NULL;
    }
    int k = 0;
    for(int i = 0; i < this -> size - 1 ; i++){
        int j = i;
        int i_2 = 0;
        while((*(char*) this -> el_of_indx(this, j) == *(char*) sub_str -> el_of_indx(sub_str, i_2)) && (j < this -> size - 1) && (i_2 < sub_str -> size - 1)){
            j++;
            i_2++;
        }
        if((j == this -> size - 1) && (i_2 != sub_str -> size - 1)){
            break;
        }
        if(i_2 == sub_str -> size - 1){
            k = i;
            while(j < this -> size - 1){
               *(char*) this -> el_of_indx(this, k) = *(char*) this -> el_of_indx(this, j);
                j++;
                k++;
            }
            this -> size = this -> size - sub_str -> size + 1;
            i--;
        }
    }
    *(char*) this -> el_of_indx(this, this -> size - 1) = '\0';
    if(!k){
        printf("Подстроки '%s' в строке '%s' не обнаружено\n", (char*) sub_str -> data, (char*) this -> data);
        return NULL;
    }
}

struct void_str* random_void_str(size_t size, size_t size_of_element){
    struct void_str* result = init_void_ptr_str(size, size_of_element);
    for(int i = 0; i < size; i++){
        if(i % 5 == 0){
            *(char*) result -> el_of_indx(result, i) = rand() % 26 + 'A';
        } else if (i % 2 == 0){
            *(char*) result -> el_of_indx(result, i) = rand() % 26 + 'a';
        } else {
            *(char*) result -> el_of_indx(result, i) = rand() % 10 + '0';
        }
    }
    *(char*) result -> el_of_indx(result, result -> size - 1) = '\0';
    return result;
}
