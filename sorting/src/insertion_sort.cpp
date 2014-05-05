#include "insertion_sort.h"
#include <algorithm>

void insertion_sort(int* xs, const int lo, const int hi) {
	int j;
	for (int i = lo + 1; i <= hi; ++i) {
		j = i;
		while (j > lo && xs[j] < xs[j - 1])
			std::swap(xs[j], xs[--j]);
	}
}

void insertion_sort(int* xs, size_t length) {
	insertion_sort(xs, 0, length - 1);
}
