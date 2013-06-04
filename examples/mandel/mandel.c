/**
 * \author  Michał Wielgus
 * \date    2013-06-27
 * \license BSD
 */
#include <stdint.h>
#include <stdlib.h>
#include  <stdio.h>
#include   <time.h>

#ifndef FAST
	typedef uint8_t byte;
#else
	typedef uint_fast8_t byte;
#endif

#ifndef SMALLFUNC
	// demo: __attrib__s, inline, static inline
	#define SMALLFUNC
#endif

byte* mandelbrot(byte* mem, float X_min, float X_max, float Y_min, float Y_max, size_t w, size_t h, size_t iterations);

int main(int argc, char *argv[]) {
	const float X_min = -2.0, X_max = 1.0,
	            Y_min = -1.5, Y_max = 1.5;
	size_t w = 8192, h = 8192, iterations = 250;

	if(argc < 2) exit(EXIT_FAILURE);
	if(argc == 3) w = h = atoi(argv[2]);

	byte* mem = malloc(w*h*sizeof(*mem));//[w*h];
	for(int i = 0; i < 5; ++i) {
		clock_t start, end;
		start = clock();
		mandelbrot(mem, X_min, X_max, Y_min, Y_max, w, h, iterations);
		end   = clock();
		printf("generated  in %.2fms\n", (float)(end-start)/((float)CLOCKS_PER_SEC/1000.f));
	}

	FILE *output = fopen(argv[1], "w");
	if(output)  {
		fprintf(output, "P5\n%zu %zu\n%zu\n", w, h, iterations);
		fwrite(mem, sizeof(byte), w*h, output);
		fclose(output);
	} else {
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

SMALLFUNC float scale(float a, float a_min, float a_max, float b_min, float b_max) {
	return ( (a - a_min)/(a_max - a_min) ) * (b_max - b_min) + b_min;
}

SMALLFUNC byte mandel_color(float x, float y, int iterations) {
	size_t i;
	float X = x, Y = y;
	for(i = 0; (i < iterations) && ( (X*X + Y*Y) < (2*2) ); ++i) {
		float X_tmp = X;
		X = X*X - Y*Y + x;
		Y = 2*X_tmp*Y + y;
	}
	return i;
}

byte* mandelbrot(byte* mem, float X_min, float X_max, float Y_min, float Y_max, size_t w, size_t h, size_t iterations) {
	for(size_t y = 0; y < h; y += 1) {
		const float Y = scale(y, h, 0, Y_min, Y_max);
		for(size_t x = 0; x < w; x += 1) {
			float X = scale(x, 0, w, X_min, X_max);
			*(mem + y*w + x) = mandel_color(X, Y, iterations);
		}
	}
	return mem;
}
