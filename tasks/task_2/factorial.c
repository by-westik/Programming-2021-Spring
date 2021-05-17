
#include <stdio.h>

long int factorial(int n);

int main(){
    int n = 0;
    do{
        printf("Enter up to what moment to element the factorial\n");
        scanf("%d", &n);
    } while(n <= 0);
    printf("%ld\n", factorial(n));
    return 0;
}

long int factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return (long int) (n * factorial(n - 1));
    }
}
