#include "function.h"
#include <stdlib.h>
#include <string.h>

int *delete_even_numbers(int *array){
    int i = 0, j = 0;
    int *array_new = (int*) calloc(1, sizeof(int));
    while(array[i]){
        if(array[i] % 2 == 0){
            i += 1;
            continue;
        } else {
            array_new = (int*) realloc(array_new,(j + 3) * sizeof(int));
            array_new[j] = array[i];
            j++;
        }
        i += 1;
    }
    array_new = (int*) realloc(array_new, (j + 1) * sizeof(int));
    array_new[j] = 0;
    return array_new;
}


void find(int *array, int *min, int *max){
    int min_a = array[0], max_a = array[0], i = 1;
    while(array[i]){
        if(array[i] >= max_a){
            max_a = array[i];
        }else if(array[i] <= min_a){
            min_a = array[i];
        }
        i++;
    }
    *min = min_a;
    *max = max_a;
}

char *reverse_str(char *str){
    char *str_new = NULL;
    str_new = (char*) calloc(strlen(str) + 2, sizeof(char));
    int j = 0;
    for(int i = strlen(str) - 1; i >= 0; i--){
        str_new[j] = str[i];
        j++;
    }
    str_new[j] = '\0';
    str_new = (char*) realloc(str_new, j + 1);
    return str_new;
}


int binary_search(int *array, int n, int len){
    int start = 0, end = len -1, middle;
    while(start <= end){
        middle = (start + end) / 2;
        if(array[middle] > n){
            end = middle - 1;
        } else if (array[middle] < n){
            start = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}
