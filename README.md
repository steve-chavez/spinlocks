# Spinlocks

```
make atomic_fetch_add

./atomic_fetch_add.o
The atomic counter is: 10000
The non-atomic counter is: 8241
```

```
make spinlock

time ./spinlock.o 1
The count is: 100000

real    0m0.009s
user    0m0.008s
sys     0m0.000s

time ./spinlock.o 2
The count is: 199816

real    0m0.027s
user    0m0.051s
sys     0m0.001s

time ./spinlock.o 3
The count is: 257334

real    0m0.050s
user    0m0.143s
sys     0m0.001s
```
