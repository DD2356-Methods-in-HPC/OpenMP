serial omp omp_critical omp_local: %:
	gcc $@_sum.c -o $@.out -fopenmp
	bash runner.sh $@.out $@.txt
	cat $@.txt

clean:
	rm -f *.out *.txt
