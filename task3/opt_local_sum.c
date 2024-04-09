#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <unistd.h>

#include <omp.h>

void generate_random(double *input, size_t size){
  for (size_t i = 0; i < size; i++) {
    input[i] = rand() / (double)(RAND_MAX);
  }
}

double omp_sum(double *x, size_t size){
typedef struct{
  double sum;
  char pad[128];
} Sum_padded;


  double sum_val = 0.0;
  int threads = omp_get_max_threads();
  Sum_padded local_sum[threads];
  #pragma omp parallel shared(local_sum)
  {
    int id = omp_get_thread_num();
    local_sum[id].sum = 0;
    #pragma omp for
    for (size_t i = 0; i < size; i++) {
      local_sum[id].sum += x[i];
    }
  }
  //printf("%f \n", sum_val);
  for(int i = 0 ; i < threads ; i ++){
    sum_val += local_sum[i].sum;
  }
  return sum_val;
}


#define ARR_SIZE 10000000
int main(){
  //Setup
  srand(time(NULL) * getpid()); //Set seed
  double* arr = malloc(ARR_SIZE * sizeof(double));
  generate_random(arr, ARR_SIZE); //populate array with random values


  //Calculate sum and measure execution time
  double start = omp_get_wtime();

  double sum_val = omp_sum(arr, ARR_SIZE);

  double end = omp_get_wtime();
  double exec_time = end - start;
  
  printf("%f ", exec_time);

  free(arr);
}
