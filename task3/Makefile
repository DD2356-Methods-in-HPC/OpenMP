
serial omp omp_critical omp_local opt_local: %:
	gcc $@_sum.c -o $@.out -fopenmp
	bash runner.sh $@.out $@.txt

clean:
	rm -f *.out *.txt
	rm -f a.out