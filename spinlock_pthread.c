#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <threads.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <immintrin.h>

typedef struct thread_args {
	pthread_spinlock_t* slock;
	int* count;
} thread_args;

int inc(void* args) {
	thread_args* targs = args;
	for (int i = 0; i < 100000; i++) {
			pthread_spin_lock(targs->slock);
			(*targs->count)++;
			pthread_spin_unlock(targs->slock);
	}
	return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
  pthread_spinlock_t sl;
  pthread_spin_init(&sl, PTHREAD_PROCESS_PRIVATE);

	int count = 0;
	int nthreads = argv[1]? atoi(argv[1]): 1;

	thrd_t threads[nthreads];
	thread_args args = { .slock = &sl, .count = &count };

	for (int i = 0; i < nthreads; ++i) {
			int rc = thrd_create(&threads[i], inc, &args);
			if (rc == thrd_error) {
					printf("ERROR: thrd_create() failed\n");
					exit(EXIT_FAILURE);
			}
	}
	for (int i = 0; i < nthreads; ++i) {
			int rc = thrd_join(threads[i], NULL);
			if (rc == thrd_error) {
					printf("ERROR: thrd_join() failed\n");
					exit(EXIT_FAILURE);
			}
	}
	printf("The count is: %d\n", count);

	return EXIT_SUCCESS;
}
