atomic_fetch_add: atomic_fetch_add.c
	gcc -pthread -o atomic_fetch_add.o atomic_fetch_add.c

spinlock: spinlock.c
	gcc -pthread -o spinlock.o spinlock.c

spinlockally: spinlockally.c
	gcc -pthread -o spinlockally.o spinlockally.c

spinlock_active_backoff: spinlock_active_backoff.c
	gcc -pthread -o spinlock_active_backoff.o spinlock_active_backoff.c

spinlock_passive_backoff: spinlock_passive_backoff.c
	gcc -pthread -o spinlock_passive_backoff.o spinlock_passive_backoff.c

spinlock_exp_backoff: spinlock_exp_backoff.c
	gcc -pthread -o spinlock_exp_backoff.o spinlock_exp_backoff.c
