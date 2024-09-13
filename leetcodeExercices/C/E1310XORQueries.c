#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int* xorQueries(int *arr, int **queries, int queriesSize,  int* queriesColSize){
    //Debemos de, dado un array de queries, hacer el XOR de la pareja de valores del primer array. Luego, lo devolvemos
    
    int *arrayResultado = malloc((queriesSize));

    for(int i = 0; i < sizeof(*arrayResultado); i++){
        *(arrayResultado+i) = arr[queries[i][0]] ^ arr[queries[i][1]];
    }

    return arrayResultado;
}

int myRand(){
    return rand()/8;
}

/**
 * @brief Get the Random Number object
 * 
 * @param max 
 * @return int 
 */
int getRandomNumber(int max){
    int numeroGenerado = myRand()/max;
    while(numeroGenerado > max){
        numeroGenerado /= max;
    }
    return numeroGenerado;
}

void println(char * cadena){
    printf("%s\n", cadena);
}

void printResults(int *arr, int **queries, int *result){
    println("Array Base");
    for(int i = 0; i < sizeof(*arr); i++){
        printf("%d\n", arr[i]);
    }
    println("Queries");
    for(int i = 0; i < sizeof(**queries); i++){
        printf("%d %d\n", queries[i][0], queries[i][1]);
    }
    println("Resultados");
    for(int i = 0; i < sizeof(*result); i++){
        printf("%d\n",result[i]);
    }
}

int main(){
    srand(time(NULL));
    int *arr = malloc(8*sizeof(int));
    int **queries = malloc(sizeof(4*sizeof(int)));

    //Debemos de popular los arrays de datos y queries
    for(int i = 0; i < sizeof(*arr); i++){
        *(arr+i) = i;
    }

    for(int i = 0; i < sizeof(**queries); i++){
        *(queries + i) = malloc(2*sizeof(int));
        int num1, num2;

        num1 = getRandomNumber(sizeof(*arr) - 1);
        num2 = getRandomNumber(sizeof(*arr) - 1);

        queries[i][0] = num1;
        queries[i][1] = num2;
    }
    int sd = 2;
    int* arrObtenido = xorQueries(arr, queries, 4, &sd);

    //Liberacion

    printResults(arr, queries, arrObtenido);

    free(arr);
    free(*queries);
    free(arrObtenido);

    return 0;
}

int main();