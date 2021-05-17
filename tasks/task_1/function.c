#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int delete_even_numbers(int *array, int len){
    int j = 0, counter = 0, n = 0;
    for(int i = 0; i < len ; i++){
        int j = i;
        while((array[j]% 2 == 0 && array[j] != 0) && (j < len)){
            j++;
            counter++;
        }
        if(j == len){
            break;
        }
        array[n] = array[j];
        i = j;
        n++;
    }
    return len - counter;
}

void find(int *array, int *min, int *max, int len){
    int min_a = array[0], max_a = array[0];
    for(int i = 0; i < len; i++){
        if(array[i] >= max_a){
            max_a = array[i];
        }
        if(array[i] <= min_a){
            min_a = array[i];
        }
    }
    *min = min_a;
    *max = max_a;
}

void reverse_str(char *str){
    char symbol;
    int j = strlen(str) - 1, i = 0;
    while(i < j){
        symbol = str[j];
        str[j] = str[i];
        str[i] = symbol;
        i++;
        j--;
    }
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
