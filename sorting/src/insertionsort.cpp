#include "insertionsort.h"
#include <algorithm>

void insertionsort(int* xs, const int lo, const int hi) {
	int j;
	for (int i = lo + 1; i <= hi; ++i) {
		j = i;
		while (j > lo && xs[j] < xs[j - 1]) {
			std::swap(xs[j], xs[j - 1]);
			--j;
		}
	}
}

void insertionsort(int* xs, size_t length) {
	insertionsort(xs, 0, length - 1);
}
