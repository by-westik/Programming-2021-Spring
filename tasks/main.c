#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <string.h>

const char *MSGS[] = {"0. Quit", "1. Removing even numbers in an array", "2. Finding the largest and smallest element in array", "3. Line reversal", "4. Binary search"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int dialog(const char *msgs[], int n);
void function_1();
void function_2();
void function_3();
void function_4();
void enter_array(int **array, int *len);
void array_print(int *array, int len);
char *enter_str();
int array_check(int *array, int len);

int main() {
    int c;
    do {
        c = dialog(MSGS, MSGS_SIZE);
        switch(c) {
        case 0:
            break;
        case 1:
            function_1();
            break;
        case 2:
            function_2();
            break;
        case 3:
            function_3();
            break;
        case 4:
            function_4();
            break;
        }
    } while (c != 0);

    return 0;

}

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        puts(error);
        error = "You're wrong. Try again!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        choice = getchar() - '0';
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

void function_1(){
    printf("***\nOption 1 - Removing even numbers in an array\n***\n");
    int *array = NULL;
    int len;
    enter_array(&array, &len);
    if((len) > 0){
        array_print(array, len);
        len = delete_even_numbers(array, len);
        array_print(array, len);
    }else{
        printf("You entered an empty array. Try next time :(\n");
    }
    scanf("%*c");
    free(array);
}
#раньше при вводе нуля выводило бы ошибку, теперь не должно...

void function_2(){
    printf("***\nOption 2 - Finding the largest and smallest element in an array\n***\n");
    int *array = NULL;
    int min, max, len;
    enter_array(&array, &len);
    if(len > 0){
        array_print(array, len);
        find(array, &min, &max, len);
        printf("min = %d\nmax = %d\n", min, max);
    }else{
        printf("You entered an empty array. Try next time :(\n");
    }
    scanf("%*c");
    free(array);
}

void function_3(){
    printf("***\nOption 3 - Line reversal\n***\n");
    char *str = NULL;
    str = enter_str();
    if(strlen(str)) {
        reverse_str(str);
        printf("%s\n", str);
    } else {
        printf("You entered an empty line. Try next time :(\n");
    }
    free(str);
}



void function_4(){
    printf("***\nOption 4 - Binary search in a sorted array\n***\n");
    int n = 0, len = 0;
    int *array = NULL;
    printf("Enter array elements in ascending order\n");
    enter_array(&array, &len);
    if(len > 0) {
        array_print(array, len);
        if (array_check(array, len) == 1) {
            printf("Enter the value of the element to find\n");
            scanf("%d", &n);
            printf("index of element = %d\n", binary_search(array, n, len));
        } else{
            printf("You entered an unsorted array. Try next time :(\n");
        }
    }else{
        printf("You entered an empty array. Try next time :(\n");
    }
    scanf("%*c");
    free(array);
}

void array_print(int *array, int len){
    printf("[ ");
    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void enter_array(int **array, int *len) {
    int n = 0;
    printf("Enter the number of elements of the array\n");
    scanf("%d", &n);
    if(n > 0){
        int *new_array = (int*) calloc(n + 1, sizeof(int));
        for(int i = 0; i < n; i++){
            printf("Enter the value of the array element\n");
            scanf("%d", &new_array[i]);
            }
        *array = new_array;
    }
    *len = n;
}

char *enter_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

int array_check(int *array, int len){
    int n = 1;
    for(int i = 0; i < len ; i++){
        if(array[i + 1] && n == 1){
            if(array[i] > array[i + 1]){
                n = 0;
            }
        }
    }
    return n;
}
#проверка, что массив введенный пользователем точно отсортирован
