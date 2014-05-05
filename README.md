Building
========

Benchmarks and tests can be built by executing the build program, SCons.

```
$ scons
```

Note: the program currently cannot be built without my benchmarking and unit
testing libraries. Feel free to write your own benchmarks in the meanwhile.

Benchmarks
==========

The current benchmarks are executed on an i5-3230M with 12 GB of RAM on Ubuntu
13.10 LTS x86_64.

```
[INFO] sorting/benchmarks/basic.cpp:20: Compiled with -O3
[INFO] sorting/benchmarks/basic.cpp:21: Sorting 10,000,000 integers
[INFO] sorting/benchmarks/basic.cpp:22: x ~ U(0, 1024*1024)

glibc-qsort: 1.5580e+03 ms
gcielo-mergesort(base_size=8): 1.2730e+03 ms
gcielo-mergesort(base_size=16): 1.2340e+03 ms
gcielo-mergesort(base_size=32): 1.2210e+03 ms
gcielo-mergesort(base_size=64): 1.2330e+03 ms
gcielo-quicksort(base_size=8): 8.3500e+02 ms
gcielo-quicksort(base_size=16): 8.0400e+02 ms
gcielo-quicksort(base_size=32): 8.2300e+02 ms
gcielo-quicksort(base_size=64): 8.7100e+02 ms
```

Executing Benchmarks
--------------------

Benchmarks can be executed by running the benchmark executable, `benchmark`, in
the `build/bin` directory.
