run: run_undef run_true_true

run_undef:
	gcc --version | grep \\.
	gcc -std=c99 -Wall -Wextra -pedantic undef.c
	./a.out
	clang --version | grep \\.
	clang -std=c99 -Wall -Wextra -pedantic undef.c
	./a.out
run_true_true:
	gcc-4.8 -std=c99 true_true.c && ./a.out
clean:
	-rm -v *.out *.s
