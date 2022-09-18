# Spinlocks

## Naive

```
spinlock-bench ./spinlock.o
The count is: 100000

real    0m0.005s
user    0m0.005s
sys     0m0.000s
The count is: 104474

real    0m0.028s
user    0m0.051s
sys     0m0.004s
The count is: 218520

real    0m0.040s
user    0m0.147s
sys     0m0.000s
The count is: 270853

real    0m0.116s
user    0m0.868s
sys     0m0.004s

spinlock-stat ./spinlock.o
The count is: 279345

 Performance counter stats for './spinlock.o 8':

            867.22 msec task-clock:u              #    7.547 CPUs utilized
                 0      context-switches:u        #    0.000 K/sec
                 0      cpu-migrations:u          #    0.000 K/sec
                75      page-faults:u             #    0.086 K/sec
     1,715,099,500      cycles:u                  #    1.978 GHz                      (59.45%)
        16,542,924      instructions:u            #    0.01  insn per cycle           (73.14%)
         5,155,588      branches:u                #    5.945 M/sec                    (75.14%)
           539,935      branch-misses:u           #   10.47% of all branches          (77.49%)
         7,136,885      L1-dcache-loads:u         #    8.230 M/sec                    (77.86%)
         2,859,563      L1-dcache-load-misses:u   #   40.07% of all L1-dcache hits    (77.86%)
         1,002,921      LLC-loads:u               #    1.156 M/sec                    (48.70%)
                 0      LLC-load-misses:u         #    0.00% of all LL-cache hits     (47.03%)

```

## Locally spinnig

```
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
