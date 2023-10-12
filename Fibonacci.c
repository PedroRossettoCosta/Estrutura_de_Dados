#include <stdio.h>


int fibo(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibo(n-1) + fibo(n-2);
    }
}

int main() {
    int k = 0;

    printf("Os primeiros 15 numero da sequencia de Fibonacci sao: \n");

    for(int i = 0; i <=14 ; i++){
        int resultado = fibo(k);

        printf("%d  ", resultado);


        k++;


    }
    

    return 0;
}