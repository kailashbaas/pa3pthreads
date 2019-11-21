/*
 * File: cd140barrier.c
 *
 */

#include "cs140barrier.h"
#define FALSE 0
#define TRUE  1


/******************************************************
 * Initialize variables in a cs140barrier.
 * It should initize the assoicated phtread mutex and condition variables
 * It should also set the intial values for other fields.
 * The odd_round field should be intiaized to be False.
 *
 * Argument:  bstate -- keep the state of a cs140barrier,
 *                      where bstate->odd_round is initialized to be False.
 *            total_nthread -- the number of threads using this barrier.
 *
 * Return:   0 successful, otherwise -1 meaning failed.
 */

int cs140barrier_init(cs140barrier *bstate, int total_nthread) {

	int mutex_stat = pthread_cond_init(&bstate->barrier_cond, NULL);
	int cond_stat  = pthread_mutex_init(&bstate->barrier_mutex, NULL);

	bstate->total_nthread = total_nthread;
	bstate->odd_round = FALSE;
	bstate->arrive_nthread = 0;

  if (
			bstate->total_nthread != total_nthread ||
			bstate->odd_round != FALSE ||
			bstate->arrive_nthread != 0 || 
			mutex_stat != 0 ||
			cond_stat != 0
		 )
		return -1;
	return 0;
}

/******************************************************
 * This function shall synchronize participating threads at the barrier
 * referenced by bstate. The calling thread shall block
 * until the required number of threads have called cs140barrier_wait().
 * This completes this round of synchronization.
 *
 * Argument:  bstate -- keep the state of a cs140barrier.
 *
 * Return:   Upon successful completion, the last thread which observes all
 *           threads have arrived in this barrier round should return 1,
 *           and other threads should return 0.
 *
 * Algorithm: Use the sense reversal technique discussed in class.
 *            If a thread that calls this function is not the last thread,
 *            it should conditionally wait until the round flag changes.
 *            The last thread should change the flag and other fields.
 */

int cs140barrier_wait(cs140barrier *bstate) {

	pthread_mutex_lock(&bstate->barrier_mutex);
	bstate->arrive_nthread += 1;
	if (bstate->arrive_nthread == bstate->total_nthread)
	{
		//Set state for new round
		bstate->arrive_nthread = 0;
		bstate->odd_round ^= 1;    //1^1 = 0 ... 0^1 = 1

		//Wake up all other threads
		pthread_cond_broadcast(&bstate->barrier_cond);

		//Release the lock then return 1;
		pthread_mutex_unlock(&bstate->barrier_mutex);
		return 1;
	}

	else
	{
		int is_odd_round = bstate->odd_round;	
		while(is_odd_round == bstate->odd_round){
			pthread_cond_wait(&bstate->barrier_cond, &bstate->barrier_mutex);	
		}
	}
	
	pthread_mutex_unlock(&bstate->barrier_mutex);

  return 0;
}

/******************************************************
 * Destroy mutex and cond variables in a cs140barrier.
 * Note that the memory of bstate is not freed here.
 *
 * Argument:  bstate -- keep the state of a cs140barrier,
 *
 * Return:   0 successful, otherwise an error number is returned.
 */

int cs140barrier_destroy(cs140barrier *bstate) {
  /*Your solution*/
	int mutex_stat = pthread_mutex_destroy(&bstate->barrier_mutex);	
	int cond_stat  = pthread_cond_destroy(&bstate->barrier_cond);
  return (mutex_stat | cond_stat);
}
