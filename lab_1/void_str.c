#include "void_str.h"
#include <stdio.h>
#include <stdlib.h>

void* el_of_indx_void_str(const struct void_str* const this, const size_t index);
void* push_back_void_str(struct void_str* const this);
struct void_str* copy_void_str(const struct void_str* const this);
void* data_alloc_void_str(size_t size_of_data, size_t size_of_element);
void double_volume_void_str(struct void_str* const this);
void copy_data_void_str(const struct void_str* const of, struct void_str* const in);
void copy_element(void* of, void* in, const size_t size_of_element);
void delete_void_str(struct void_str str);
void delete_void_ptr_str(struct void_str* str);
void reserve_void_str(struct void_str* const this, const size_t new_size);

void* el_of_indx_void_str(const struct void_str* const this, const size_t index){
    if(index >= this -> size){
        return NULL;
    }
    void *data = (char*) this -> data;
    for(size_t i = 0; i < index; i++){
        *((char*)data++);
    }
    return data;
}

void copy_element(void* of, void* in, const size_t size_of_element){
    for(size_t i = 0; i < size_of_element; i++){
        *((char*) in + i) = *((char*) of + i);
    }
}

void copy_data_void_str(const struct void_str* const of, struct void_str* const in){
    for(size_t i = 0; i < of -> size; i++){
        copy_element(of -> el_of_indx(of, i), in -> el_of_indx(in, i), of -> element_size);
    }
}

void* data_alloc_void_str(size_t size_of_data, size_t size_of_element){
    if(!size_of_data){
        return NULL;
    }
    void *result = calloc(size_of_data + 1, size_of_element);
    return result;
}

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
    if(this -> size == 0){
        ++(this -> size);
        return this -> el_of_indx(this, this -> size - 1);
    }
    void *data = (char*) this -> data;
    for(size_t i = 0; i < this -> size - 1; i++){
        *((char*) data++);
    }
    if(*(char*) data == '\0'){
        return this -> el_of_indx(this, this -> size - 1);
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

void reserve_void_str(struct void_str* const this, const size_t new_size){
    if(new_size > this -> volume){
        this -> volume = new_size;
        struct void_str* temporary = init_void_ptr_str(this -> volume, this -> element_size);
        copy_data_void_str(this, temporary);
        free(this -> data);
        this -> data = temporary -> data;
        free(temporary);
    }
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
    result.reserve = &reserve_void_str;
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
