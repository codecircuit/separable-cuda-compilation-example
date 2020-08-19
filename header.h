#ifndef HEADER_H
#define HEADER_H

#ifdef __CUDACC__
#define HDFLAGS __host__ __device__ __forceinline__
#else
#define HDFLAGS inline
#endif

struct mystruct_t {
	int b;
};

HDFLAGS int func(int a, struct mystruct_t s) {
	return a * 7 * s.b;
}

#endif // HEADER_H
