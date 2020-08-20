# Separable Compilation

```
gcc -O3 file.c -c -o file.o
nvcc --extended-lambda -std=c++17 -O3 -c accelerated.cu -o accelerated.o
```

There are now multiple ways to link the object files. Most simply with `nvcc`:

```
nvcc file.o accelerated.o -o main
```

For a better understanding read about Name Mangling, which is done by C++ but not by
C compilers.
