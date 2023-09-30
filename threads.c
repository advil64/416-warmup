/*
* ac1771 Advith Chegu
* tsc95 Tajvir Chahal
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t t1, t2, t3, t4;
pthread_mutex_t mutex;
int x = 0;
//int loop = 10000; 
// commented out the loop global variable just to make sure pthread is properly used

/* Counter Incrementer function:
 * This is the function that each thread will run which
 * increments the shared counter x by LOOP times.
 *
 * Your job is to implement the incrementing of x
 * such that update to the counter is sychronized across threads.
 *
 */
void *add_counter(void *arg) {

    int i;
    int loop = *((int*)arg); //convert the argument back to an int

    printf("Amount to be added to x: %d \n", loop);

    /* Add thread synchronizaiton logic in this function */	

    // 2. lock the x variable to synchronize the threads
    pthread_mutex_lock(&mutex);

    // add to the x variable
    for(i = 0; i < loop; i++){

	x = x + 1;
    }

    // unlock
    pthread_mutex_unlock(&mutex);

    return NULL;
}


/* Main function:
 * This is the main function that will run.
 *
 * Your job is to create four threads and have them
 * run the add_counter function().
 */
int main(int argc, char *argv[]) {

    if(argc != 2){
        printf("Bad Usage: Must pass in a integer\n");
        exit(1);
    }

    int loop = atoi(argv[1]);

    printf("Going to run four threads to increment x up to %d\n", 4 * loop);

    /* Implement Code Here */

    /*
        to compile & run:
        gcc threads.c -o thread
        ./thread [loop value]

        example output:
        ./thread 500
        The final value of x is 2000
    */

    //1. create pthreads, pass the function paramater, and pass the argument for add counter
    pthread_create(&t1, NULL, add_counter, &loop);
    pthread_create(&t2, NULL, add_counter, &loop);
    pthread_create(&t3, NULL, add_counter, &loop);
    pthread_create(&t4, NULL, add_counter, &loop);

    //3. Join the pthreads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);


    printf("The final value of x is %d\n", x);

    return 0;
}