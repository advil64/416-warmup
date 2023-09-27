/*
* Add NetID and names of all project partners
*
*/

#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h> 

jmp_buf jump_buffer;
// jmp_buf type = stores information about the execution context of program


void signal_handle(int signalno) {
    printf("Handling segmentation fault!\n");

    // Set a flag to indicate that the signal has been handled
    volatile int handled = 1;

    // Jump back to the main function - transfer control to main
    longjmp(jump_buffer, 1);
}

int main(int argc, char *argv[]) {
    int r2 = 0;

    // Sig handler (SIGSEV - 11)
    signal(SIGSEGV, signal_handle);

    // if the segmentation is not handled run r2
    if (setjmp(jump_buffer) == 0) {
        // Attempt to access memory address 0 (will cause a segmentation fault)
        r2 = *((int *)0);
    } else {
        // This block will be executed after handling the segmentation fault
        //printf("temp\n");
        r2 = r2 + 1 * 30;
    }

    printf("result after handling segfault %d!\n", r2);

    return 0;
}






