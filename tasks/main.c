#include <stdio.h>
#include <stdlib.h>

void vvod_array(int **array, int len);
int pair(int *array, int len);


int main() {
    int N = 0, *array = NULL;
    scanf("%d", &N);
    vvod_array(&array, N);
    printf("%lli", pair(array, N));
    free(array);
    return 0;
}

void vvod_array(int **array, int len){
    int *new_array = (int*) calloc(len + 1, sizeof(int));
    for(int i = 0; i < len; i++){
         scanf("%d", &new_array[i]);
    }
    *array = new_array;
}

int pair(int *array, int len){
    long int c_0 = 0, c_1 = 0, c_2 = 0;
    for(int i = 0; i < len; i++){
        if((array[i] % 3) == 0){
            c_0++;
        }
        if((array[i] % 3) == 1){
            c_1++;
        }
        if((array[i] % 3) == 2){
            c_2++;
        }
    }
    return (long long int) c_1*c_2+c_0*(c_0-1)/2;;
}

