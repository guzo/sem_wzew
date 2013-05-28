#include <stdio.h>
int main() {
	volatile _Bool a;
	*(char*)&a = 0xff;
	if(a)  puts("true");
	if(!a) puts("false");
}
