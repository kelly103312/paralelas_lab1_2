#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(10)
    {
        if(omp_get_thread_num() %2 ==0){
            printf("Hello from thread %d PAR\n", omp_get_thread_num());
        }else{
            printf("Hello from thread %d IMPAR\n", omp_get_thread_num());
        }
    }
    return 0;
}