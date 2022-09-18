atomic_fetch_add: atomic_fetch_add.c
	gcc -pthread -o atomic_fetch_add.o atomic_fetch_add.c

spinlock: spinlock.c
	gcc -pthread -o spinlock.o spinlock.c

spinlockally: spinlockally.c
	gcc -pthread -o spinlockally.o spinlockally.c
