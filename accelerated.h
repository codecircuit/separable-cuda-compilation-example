#ifndef ACCELERATED_H
#define ACCELERATED_H

#ifdef __CUDACC__
#define CEXTERN extern "C"
#else
#define CEXTERN
#endif
CEXTERN void do_all_accelerated(const int* is, const struct mystruct_t* ss, int* result, int N);

#endif // ACCELERATED_H
