#!/bin/bash

gcc serial_sum.c -o serial.out -fopenmp
gcc omp_sum.c -o omp.out -fopenmp
gcc omp_critical_sum.c -o omp_critical.out -fopenmp
gcc omp_local_sum.c -o omp_local.out -fopenmp
gcc opt_local_sum.c -o opt_local.out -fopenmp
