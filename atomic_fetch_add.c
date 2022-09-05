// From https://www.educative.io/answers/what-is-atomicfetchadd-in-c
#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

atomic_int atomic_count = 0;
int non_atomic_count = 0;

int func(void* input)
{
    for(int n = 0; n < 1000; ++n) {
        atomic_fetch_add(&atomic_count, 1);
        ++non_atomic_count;
    }

    return 0;
}

int main(void)
{
    thrd_t threads[10];
    for(int i = 0; i < 10; i++)
        thrd_create(&threads[i], func, NULL);

    for(int i = 0; i < 10; i++)
        thrd_join(threads[i], NULL);

    printf("The atomic counter is: %d\n", atomic_count);
    printf("The non-atomic counter is: %d\n", non_atomic_count);
}

/*
 *The atomic counter is: 10000
 *The non-atomic counter is: 3207
 */
