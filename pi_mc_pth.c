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
  double x, y, distance_squared;
  long me = (long) rank;

  for (long long int i = me; i < number_of_tosses; i += thread_count) {
      x = 2.0 * rand_r((unsigned int*) &me) / ((double)RAND_MAX) - 1.0;
      y = 2.0 * rand_r((unsigned int*) &me) / ((double)RAND_MAX) - 1.0;
      distance_squared = x * x + y * y;
      if (distance_squared <= 1) {
          pthread_mutex_lock(&mutex);
          number_in_circle++;
          pthread_mutex_unlock(&mutex);
      }
  }

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
  thread_count = no_threads;
  number_of_tosses = no_tosses;
  pthread_t* threads = malloc(no_threads * sizeof(pthread_t));
  pthread_mutex_init(&mutex, NULL);

  for (long i = 0; i < no_threads; i++) {
      pthread_create(&threads[i], NULL, thread_work, (void*) i);
  }

  for (long i = 0; i < no_threads; i++) {
      pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  free(threads);

  return 4.0 * number_in_circle / ((double) no_tosses);
}
