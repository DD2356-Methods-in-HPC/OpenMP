#!/bin/bash

bash runner.sh serial.out output/serial.txt

bash runner.sh omp.out output/omp.txt 32

critical_thread_counts=(1 2 4 8 16 20 24 28 32)
for threads in "${critical_thread_counts[@]}"; do
    bash runner.sh omp_critical.out output/omp_critical"$threads".txt "$threads"
done

local_thread_counts=(1 32 64 128)
for threads in "${local_thread_counts[@]}"; do
    bash runner.sh omp_local.out output/omp_local"$threads".txt "$threads"
done

local_thread_counts=(1 32 64 128)
for threads in "${local_thread_counts[@]}"; do
    bash runner.sh opt_local.out output/opt_local"$threads".txt "$threads"
done

