#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000; 
    int value = 0; 
    int avg,sum;
    srand(time(0));
    for (int i = 0; i < 100; i++){
        Array[i]=rand()%10000;
    }
    
     #pragma omp parallel for reduction(max:max) reduction(min:min) reduction(+:sum) num_threads(100)
        for (int i = 0; i < 100; i++){
             max= Array[i];
             min = Array[i];
             sum += Array[i];
        }
    
    avg= sum/100;
    printf("Valor minimo  %d \n", min);
    printf("Valor maximo  %d \n", max);
    printf("Valor avg  %d \n", avg);
    
    for (int e = 0; e < 100; e++){
        if(Array[e]> max){
            printf("MAX %d\n",e);
        }
        if(Array[e]< min){
            printf("MIN %d\n",e);
        }
        printf("Elemento número %d  valor %d\n",e, Array[e]);
    }
    
    return 0;
}