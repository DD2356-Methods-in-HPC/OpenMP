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
  double sum_val = 0.0;
  #pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
      #pragma omp critical
      {
        sum_val += x[i];
      }
    }

  //printf("%f \n", sum_val);
  return sum_val;
}


#define ARR_SIZE 10000000
int main(int argc, char *argv[]){
  if(argc == 2){
    int num_threads = atoi(argv[1]);
    omp_set_num_threads(num_threads);
  }
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
