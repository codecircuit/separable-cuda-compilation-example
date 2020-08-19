#include "header.h"
#include "accelerated.h"

#include <thrust/device_vector.h>
#include <thrust/transform.h>
#include <thrust/execution_policy.h>

void do_all_accelerated(const int* is, const struct mystruct_t* ss, int* result, int N) {
	thrust::device_vector<mystruct_t> ss_d(N);
	thrust::device_vector<int> is_d(N);
	thrust::device_vector<int> result_d(N);
	thrust::copy(is, is + N, is_d.begin());
	thrust::copy(ss, ss + N, ss_d.begin());
	int i;
	for (i = 0; i < N; ++i) {
		result[i] = func(is[i], ss[i]);
	}
	thrust::transform(is_d.begin(), is_d.end(), ss_d.begin(), result_d.begin(), [] __device__ __host__ (int i, mystruct_t s) { return func(i, s); } );
	thrust::copy(result_d.begin(), result_d.end(), result);
}

