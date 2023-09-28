bitops: bitops.c
	gcc -o bitops bitops.c

stack: stack.c
	gcc -m32 stack.c -o stack

clean:
	rm -rf bitops stack