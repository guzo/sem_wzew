#include <iostream>
using std::cout;
struct C {
	 C()         {cout << " C()\n";}
	 C(const C&) {cout << " C(const C&)\n";}
	~C()         {cout << "~C()\n";}
};

__attribute__((noinline)) C foo() {	C a = C(); return a; }

int main() {
	C a;                         // "C()"
	C b = C();                   // "C()"
	C c = C(C(C(C(C(C(C())))))); // "C()"
	C d = foo();                 // "C()"
	// "~C()\n" x 4
}
