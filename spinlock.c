#include <stdbool.h>
#include <stdio.h>
#include <threads.h>
#include <stdlib.h>
#include <stdatomic.h>

struct spinlock {
	bool locked;
};

void lock(struct spinlock* spinlock) {
	while (atomic_exchange(&spinlock->locked, true));
}

void unlock(struct spinlock* spinlock) {
	atomic_store(&spinlock->locked, false);
}

typedef struct thread_args {
	struct spinlock* slock;
	int* count;
} thread_args;

int inc(void* args) {
	thread_args* targs = args;
	for (int i = 0; i < 100000; i++) {
			lock(targs->slock);
			(*targs->count)++;
			unlock(targs->slock);
	}
	return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
	struct spinlock slock = { 0 };
	int count = 0;
	int nthreads = argv[1]? atoi(argv[1]): 1;

	thrd_t threads[nthreads];
	thread_args args = { .slock = &slock, .count = &count };

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
