#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int delete_even_numbers(int *array, int len){
    int j = 0, counter = 0;
    for(int i = 0; i < len ; i++){
         if((array[i] % 2 == 0) && array[i] != 0){
            counter += 1;
            for(j = i; j < (len); j++){
                array[j] = array[j+1];
            }
            if((array[i] % 2 == 0) && (array[i] != 0)){
                i--;
            }
         }
    }
    return len - counter;
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
