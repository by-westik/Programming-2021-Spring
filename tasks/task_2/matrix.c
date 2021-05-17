#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix{
    int rows;
    int columns;
    int **data;
} Matrix;

Matrix create_matrix(int n_rows, int n_columns){
    Matrix matrix;
    matrix.rows = n_rows;
    matrix.columns = n_columns;
    matrix.data = (int **) calloc(n_rows + 1, sizeof(int*));
    for(int i = 0; i < n_rows; i++){
        matrix.data[i] = (int*) calloc(n_columns + 1, sizeof(int));
    }
    return matrix;
}

void fill_matrix(Matrix matrix);
void print_matrix(Matrix matrix);
void free_matrix(Matrix matrix);
void function_matrix(Matrix matrix);

int main(){
    int row = 0, column = 0;
    do{
        printf("Введите количество строк\n");
        scanf("%d", &row);
    }while(row <= 0);
    do{
        printf("Введите количество столбцов\n");
        scanf("%d", &column);
    }while(column <= 0);
    Matrix m = create_matrix(row, column);
    fill_matrix(m);
    printf("Исходная матрица\n");
    print_matrix(m);
    function_matrix(m);
    printf("Измененная матрица\n");
    print_matrix(m);
    free_matrix(m);
    return 0;
}

void fill_matrix(Matrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.columns; j++){
            printf("Введите значение %d строки %d столбца\n", i, j);
            scanf("%d", &matrix.data[i][j]);
        }
    }
}

void print_matrix(Matrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.columns; j++){
            printf("[%d]", matrix.data[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(Matrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void function_matrix(Matrix matrix){
    int counter = 0;
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.columns; j++){
             counter++;
             matrix.data[i][j] = matrix.data[i][j] + counter;
        }
    }
}
