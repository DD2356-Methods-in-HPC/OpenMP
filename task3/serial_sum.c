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


double serial_sum(double *x, size_t size){
  double sum_val = 0.0;

  for (size_t i = 0; i < size; i++) {
    sum_val += x[i];
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

  double sum_val = serial_sum(arr, ARR_SIZE);

  double end = omp_get_wtime();
  double exec_time = end - start;
  
  printf("%f ", exec_time);

  free(arr);
}
