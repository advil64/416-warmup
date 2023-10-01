bitops: bitops.c
	gcc -o bitops bitops.c

stack: stack.c
	gcc -m32 stack.c -o stack

threads: threads.c
	gcc -lpthread -o threads threads.c

clean:
	rm -rf bitops stack threads