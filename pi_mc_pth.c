/*
 * File:     pi_mc_pth.c
 *
 * Purpose:  Thread function that Estimates pi using a monte carlo method
 */

#include "pi_mc_pth.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* Global variables */
int thread_count;
long long int number_in_circle = 0;
long long int number_of_tosses;

/* mutex */
pthread_mutex_t
    mutex; /*this mutex may be used for synchronization in this file*/

/*---------------------------------------------------------------------
 * Function:  thread_work
 * Purpose: Calculate number_in_circle using monte carlo method
 * In arg:  rank
 * Global in vars:  number_of_tosses: The total number of tosses for all
 *                  threads thread_count: The number of threads to be allocated
 * Global out vars: number_in_circle: The number of hits inside the circle
 */

void* thread_work(void* rank) {
  /*Your solution*/

  return NULL;
}

/*---------------------------------------------------------------------
 * Function:  parallel_pi
 * Purpose:   Calculate number in circle using monte carlo method in parallel.
 *            Create a number of threads specified by "no_threads" and calls
 *            thread_work by each thread.
 * In arg:
 *            no_tosses: the total number of tosses
 *            thread_count: number of threads used to execute
 * Global out vars:
 *            number_in_circle: The total number of hits inside the circle
 */
double parallel_pi(long long int no_tosses, int no_threads) {
  /*Your solution*/

  return 0;
}
