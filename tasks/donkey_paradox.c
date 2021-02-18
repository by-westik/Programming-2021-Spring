#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, x_1, x_2, y_1, y_2;
    int counter = 0;
    scanf("%d %d", &N, &M);
    scanf("%d %d", &x_1, &y_1);
    scanf("%d %d", &x_2, &y_2);
    for(int i = 1;i <= N; i++){
        for(int j = 1;j <= M;j++){
            if(abs(x_1-i)+abs(y_1-j)==abs(x_2-i)+abs(y_2-j)){
                counter++;
            }
        }
    } 
    
    printf("%d",counter); 
    return 0;
}