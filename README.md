# Spinlocks

## Naive

```
make spinlock

spinlock-bench ./spinlock.o
The count is: 100000

real    0m0.009s
user    0m0.005s
sys     0m0.004s
The count is: 200000

real    0m0.023s
user    0m0.044s
sys     0m0.000s
The count is: 400000

real    0m0.103s
user    0m0.392s
sys     0m0.000s
The count is: 800000

real    0m0.478s
user    0m3.658s
sys     0m0.000s

spinlock-stat ./spinlock.o
The count is: 800000

 Performance counter stats for './spinlock.o 8':

          3,971.95 msec task-clock:u              #    7.469 CPUs utilized
                 0      context-switches:u        #    0.000 K/sec
                 0      cpu-migrations:u          #    0.000 K/sec
                71      page-faults:u             #    0.018 K/sec
     8,174,888,035      cycles:u                  #    2.058 GHz                      (61.85%)
        68,128,831      instructions:u            #    0.01  insn per cycle           (74.56%)
        18,262,842      branches:u                #    4.598 M/sec                    (74.78%)
           832,278      branch-misses:u           #    4.56% of all branches          (75.25%)
        19,736,218      L1-dcache-loads:u         #    4.969 M/sec                    (75.59%)
         8,759,096      L1-dcache-load-misses:u   #   44.38% of all L1-dcache hits    (75.64%)
         1,235,026      LLC-loads:u               #    0.311 M/sec                    (49.92%)
               252      LLC-load-misses:u         #    0.02% of all LL-cache hits     (49.59%)

       0.531788030 seconds time elapsed

       3.969189000 seconds user
       0.004009000 seconds sys
```

## Locally spinning

```
make spinlockally

spinlock-bench ./spinlockally.o
The count is: 100000

real    0m0.004s
user    0m0.004s
sys     0m0.000s
The count is: 200000

real    0m0.023s
user    0m0.044s
sys     0m0.000s
The count is: 400000

real    0m0.083s
user    0m0.323s
sys     0m0.000s
The count is: 800000

real    0m0.219s
user    0m1.668s
sys     0m0.004s

spinlock-stat ./spinlockally.o
The count is: 800000

 Performance counter stats for './spinlockally.o 8':

          2,151.71 msec task-clock:u              #    7.687 CPUs utilized
                 0      context-switches:u        #    0.000 K/sec
                 0      cpu-migrations:u          #    0.000 K/sec
                74      page-faults:u             #    0.034 K/sec
     4,460,741,205      cycles:u                  #    2.073 GHz                      (61.42%)
       807,699,645      instructions:u            #    0.18  insn per cycle           (74.35%)
       269,623,840      branches:u                #  125.307 M/sec                    (74.48%)
         3,527,201      branch-misses:u           #    1.31% of all branches          (75.47%)
       267,746,311      L1-dcache-loads:u         #  124.434 M/sec                    (76.45%)
        11,623,242      L1-dcache-load-misses:u   #    4.34% of all L1-dcache hits    (76.58%)
         7,881,325      LLC-loads:u               #    3.663 M/sec                    (49.73%)
                 4      LLC-load-misses:u         #    0.00% of all LL-cache hits     (48.78%)

       0.279924663 seconds time elapsed

       2.149269000 seconds user
       0.004017000 seconds sys
```

## Active backoff

```
make spinlock_active_backoff

spinlock-bench ./spinlock_active_backoff.o
The count is: 100000

real    0m0.005s
user    0m0.005s
sys     0m0.000s
The count is: 200000

real    0m0.012s
user    0m0.020s
sys     0m0.000s
The count is: 400000

real    0m0.033s
user    0m0.126s
sys     0m0.000s
The count is: 800000

real    0m0.123s
user    0m0.894s
sys     0m0.000s
```

## Passive backoff

```
make spinlock_passive_backoff

spinlock-bench ./spinlock_passive_backoff.o
The count is: 100000

real    0m0.005s
user    0m0.005s
sys     0m0.000s
The count is: 200000

real    0m0.018s
user    0m0.034s
sys     0m0.000s
The count is: 400000

real    0m0.040s
user    0m0.156s
sys     0m0.000s
The count is: 800000

real    0m0.117s
user    0m0.875s
sys     0m0.000s
```
