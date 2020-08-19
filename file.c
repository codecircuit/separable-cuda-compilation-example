#include <stdlib.h>
#include "header.h"
#include "accelerated.h"

void do_all(const int* is, const struct mystruct_t* ss, int* result, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		result[i] = func(is[i], ss[i]);
	}
}

int main() {

	int N=  100;
	struct mystruct_t* ss = (struct mystruct_t*) malloc(sizeof(struct mystruct_t) * N);
	int* is = (int*) malloc(sizeof(int) * N);
	int* result = (int*) malloc(sizeof(int) * N);

	do_all(is, ss, result, N);
	do_all_accelerated(is, ss, result, N);

	free(ss);
	free(is);
}
