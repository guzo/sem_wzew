#include <stdio.h>

typedef float v4f __attribute__ (( vector_size(4*4) ));
typedef int   v4i __attribute__ (( vector_size(4*4) ));

__attribute__ ((target ("sse")))     void foo() {
	//#include <x86intrin.h>
	v4f a = {3,2,32,8}; //__m128
	v4f b = {1,2,32,8};
	v4i s = {3,2,1,0};
	v4i e = (a == b); // -1 := all bits set, _mm_cmpeq_ps
	a = __builtin_shuffle(a+b, s); //_mm_shuffle_ps
	a = __builtin_ia32_rsqrtps(a); //_mm_rsqrt_ps
	printf(
		"1/sqrt((a+b).wzyx) == {%.3f, %.3f, %.3f, %.3f}; "
		"(a==b) == {%i, %i, %i, %i}\n",
		a[0], a[1], a[2], a[3],
		e[0], e[1], e[2], e[3]
	);
}

__attribute__ ((target ("default"))) void foo () {
	puts("SSE: haha, stary sprzet");
}

__attribute__ ((target ("sse4.2")))  void bar() {
	puts("SSE4.2: zoptymalizowany kod");
}

__attribute__ ((target ("default"))) void bar () {
	puts("SSE4.2: haha, stary sprzet");
}

int main() {
	if(__builtin_cpu_supports("sse"))    puts("sse");
	if(__builtin_cpu_supports("sse4.2")) puts("sse4.2");
	foo();
	bar();
}
