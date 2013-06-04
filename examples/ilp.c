#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint64_t sum_ilp(char* a, size_t n) {
	uint64_t sum1 = 0, sum2 = 0;
	for(size_t i = 0; i < n; i += 2) {
		sum1 += a[i];
		sum2 += a[i+1];
	}
	return sum1 + sum2;
}

uint64_t sum(char* a, size_t n) {
	uint64_t sum = 0;
	for(size_t i = 0; i < n; i += 2) {
		sum += a[i];
		sum += a[i+1];
	}
	return sum;
}

int main() {
	size_t sz = 258*1024*1024;
	char* a = memset(malloc(sz), 0x01, sz);
	clock_t start,end; uint64_t s;
	start = clock(); s = sum_ilp(a,sz); end = clock();
	printf("%"PRIu64": %f\n", s, (double)(end-start)/(double)CLOCKS_PER_SEC);
	start = clock(); s = sum(a,sz); end = clock();
	printf("%"PRIu64": %f\n", s, (double)(end-start)/(double)CLOCKS_PER_SEC);
}
