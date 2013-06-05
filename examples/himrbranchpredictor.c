#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void test(int8_t* bytes, size_t size) {
	clock_t start, end;
	long    upper = 0, lower = 0;
	start = clock();
	for(size_t i = 0; i < size; ++i)
		if(bytes[i] > 0) ++upper;
		else             ++lower;
	end = clock();
	printf("upper == %ld; lower == %ld; time == %fs\n", upper, lower, (double)(end - start)/CLOCKS_PER_SEC);
}

int compare_int8_t(const void* a, const void* b) {
	return (*(int8_t*)a-*(int8_t*)b);
}

int main(int argc, char* argv[]) {
	size_t size = (argc == 2) ? atoi(argv[1]) : 50*1024*1024;

	printf("C version. Testing on %zu elements.\n", size);

	int8_t* bytes = malloc(size*sizeof(*bytes));
	if(!bytes) {
		fputs("Ain't have that much mem, man!\n", stderr);
		return EXIT_FAILURE;
	}
	for(size_t i = 0; i < size; bytes[i++] = rand());

	fputs("without sorting: ", stderr); test(bytes, size);
	qsort(bytes, size, sizeof(*bytes), compare_int8_t);
	fputs("with    sorting: ", stderr); test(bytes, size);

	free(bytes);

	return EXIT_SUCCESS;
}
