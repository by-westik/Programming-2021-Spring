#include <assert.h>
#include <stdio.h>

#include "void_str.h"

void test_void_str();

int main(){
    test_void_str();
    return 0;
}

void test_el_of_indx(){
    struct void_str str = init_void_str(5, sizeof(void));
    char test_str[5] = "1Bn90";
    for(int i = 0; i < 5; i++){
        *(char*)str.el_of_indx(&str, i) = test_str[i];
    }
    for(int i = 0; i < 5; i++){
        assert(*(char*)str.el_of_indx(&str, i) == test_str[i]);
    }
    assert(str.el_of_indx(&str, 10) == NULL);
}

void test_init(){
    struct void_str str = init_void_str(7, sizeof(void));
    assert(str.size == 7);
    assert(str.volume == 7);

    struct void_str* ptr_str = init_void_ptr_str(13, sizeof(void));
    assert(ptr_str -> size == 13);
    assert(ptr_str -> volume == 13);
}

void test_push_back(){
    struct void_str str = init_void_str(0, sizeof(void));
    char str_test[5] = " )9j1";
    for(int i = 0; i < 5; i++){
        *(char*)str.push_back(&str) = str_test[i];
        assert(*(char*)str.el_of_indx(&str, i) == str_test[i]);
    }
    for(int i = 0; i < 5; i++){
        assert(*(char*)str.el_of_indx(&str, i) == str_test[i]);
    }
}

void test_copy(){
    struct void_str str = init_void_str(5, sizeof(void));
    char test_str[5] = "n B7*";
    for(int i = 0; i < 5; i++){
        *(char*)str.el_of_indx(&str, i) = test_str[i];
    }
    struct void_str* str_copy = str.copy(&str);
    assert(str.size == str_copy -> size);
    assert(str.volume == str_copy -> volume);
    for(int i = 0; i < 5; i++){
        assert(*(char*)str.el_of_indx(&str, i) == *(char*) str_copy -> el_of_indx(str_copy, i));
        assert(*(char*)str_copy -> el_of_indx(str_copy, i) == test_str[i]);
    }
}

void test_void_str(){
    void test_el_of_indx();
    void test_init();
    void test_push_back();
    void test_copy();
}