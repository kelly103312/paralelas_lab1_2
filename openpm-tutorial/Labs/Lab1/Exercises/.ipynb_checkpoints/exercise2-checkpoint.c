#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000; 
    int value = 0; 
    int avg;

     #pragma omp parallel num_threads(100)
    {
        //printf("Hello from thread %d \n", omp_get_thread_num());
        for (int i = 0; i < 100; i++){
           value= rand() % 10000;
           printf("Valor dato  %d max %d min %d\n", Array[i], max,min);
           Array[i] = value;
           if(value > max){
               max=  value;
           }
           if(value < min){
               min = value;
           }
           avg += value;
        }
    } 
    printf("Valor minimo  %d \n", min);
    printf("Valor maximo  %d \n", max);
    printf("Valor avg  %d \n", avg);
    for (int e = 0; e < 100; e++){
        printf("Elemento número %d  valor %d\n",e, Array[e]);
    }
    
    return 0;
}