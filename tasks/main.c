#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <string.h>

const char *MSGS[] = {"0. Quit", "1. Removing even numbers in an array", "2. Finding the largest and smallest element in an array", "3. Line reversal", "4. Binary search"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int dialog(const char *msgs[], int n);
void function_1();
void function_2();
void function_3();
void function_4();
void enter_array(int **array, int *len);
void array_print(int *array);
char *enter_str();
int array_check(int *array);

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
    int *array = NULL, *array_new = NULL;
    int len;
    printf("Enter array elements\n");
    enter_array(&array, &len);
    if((len - 1)!= 0){
        array_print(array);
        array_new = delete_even_numbers(array);
        array_print(array_new);
    }else{
        printf("You entered an empty array. Try next time :(\n");
    }
    scanf("%*c");
    free(array_new);
    free(array);
}

void function_2(){
    printf("***\nOption 2 - Finding the largest and smallest element in an array\n***\n");
    int *array = NULL;
    int min, max, len;
    printf("Enter array elements\n");
    enter_array(&array, &len);
    if((len - 1)!= 0){
        array_print(array);
        find(array, &min, &max);
        printf("Minimum element in an array = %d\nMaximum element in an array = %d\n", min, max);
    }else{
        printf("You entered an empty array. Try next time :(\n");
    }
    scanf("%*c");
    free(array);
}
void function_3(){
    printf("***\nOption 3 - Line reversal\n***\n");
    char *str = NULL;
    char *str_new = NULL;
    str = enter_str();
    if(strlen(str)) {
        str_new = reverse_str(str);
        printf("%s\n", str_new);
    } else {
        printf("You entered an empty line. Try next time :(\n");
    }
    free(str);
    free(str_new);

}

void function_4(){
    printf("***\nOption 4 - Binary search in a sorted array\n***\n");
    int n = 0, len = 0;
    int *array = NULL;
    printf("Enter array elements in ascending order\n");
    enter_array(&array, &len);
    if((len - 1) != 0) {
        array_print(array);
        if (array_check(array) == 1) {
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


void array_print(int *array){
    int i = 0;
    printf("[ ");
    while(array[i]){
        printf("%d ", array[i]);
        i++;
    }
    printf("]\n");
}

void enter_array(int **array, int *len) {
    int *new_array = (int*) calloc(3, sizeof(int));
    int n = 0;
    int i = 0;
    do{
        printf("Write a number\n");
        new_array = (int*) realloc(new_array, (i + 2)*sizeof(int));
        scanf("%d", &n);
        new_array[i] = n;
        i++;
    }while(n != 0);
    *array = new_array;
    *len = i;
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

int array_check(int *array){
    int i = 0, n = 1;
    while(array[i] && (n == 1)){
        if(array[i+1]){
            if(array[i] > array[i+1]){
                n = 0;
            }
        }
        i++;
    }
    return n;
}