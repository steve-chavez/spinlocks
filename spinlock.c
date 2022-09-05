#include <stdio.h>
#include <threads.h>
#include <stdlib.h>
#include <stdatomic.h>

#define NTHREADS 1

static int expected = 0;

struct spinlock {
	int lock;
};

void spinlock_lock(struct spinlock* spinlock) {
	while (!atomic_compare_exchange_strong(&spinlock->lock, &expected, 1));
}

void spinlock_unlock(struct spinlock* spinlock) {
	atomic_store(&spinlock->lock, 0);
}

typedef struct thread_args {
	struct spinlock* slock;
	int* count;
} thread_args;

int inc(void* args) {
	thread_args* targs = args;
	for (int i = 0; i < 100000; i++) {
			spinlock_lock(targs->slock);
			(*targs->count)++;
			spinlock_unlock(targs->slock);
	}
	return EXIT_SUCCESS;
}

int main() {
	struct spinlock slock = { 0 };
	int count = 0;

	thrd_t threads[NTHREADS];
	thread_args args = { .slock = &slock, .count = &count };

	for (int i = 0; i < NTHREADS; ++i) {
			int rc = thrd_create(&threads[i], inc, &args);
			if (rc == thrd_error) {
					printf("ERROR: thrd_create() failed\n");
					exit(EXIT_FAILURE);
			}
	}
	for (int i = 0; i < NTHREADS; ++i) {
			int rc = thrd_join(threads[i], NULL);
			if (rc == thrd_error) {
					printf("ERROR: thrd_join() failed\n");
					exit(EXIT_FAILURE);
			}
	}
	printf("The count is: %d\n", count);

	return EXIT_SUCCESS;
}
