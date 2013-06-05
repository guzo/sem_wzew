all: strength_reduction.s mtune

strength_reduction.s: strength_reduction.c
	cc -c -S -masm=intel -O3 strength_reduction.c

mtune:
	for cpu in atom barcelona corei7; do gcc-4.8 -masm=intel -S -Og -mtune=$$cpu -omtune_$$cpu.s strength_reduction.c; done

clean:
	rm -v *.s *.o

.PHONY: all mtune clean
