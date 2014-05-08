#include "countingsort.h"

#include <algorithm>
#include <climits>

void countingsort(int* xs, size_t length, const int min, const int max) {
	int range = max - min + 1;
	int* hist = new int[range];
	std::fill_n(hist, range, 0);
	
	// Compute histogram
	for (int i = 0; i < range; ++i) hist[xs[i] - min]++;

	// Prefix sum
	hist[0]--;
	for (int i = 1; i < range; ++i) hist[i] += hist[i - 1];

	// Compute sorted buffer
	int* buffer = new int[length];
	for (int i = 0; i < length; ++i)
		buffer[hist[xs[i] - min]++] = xs[i];

	// Swap buffer
	std::copy(buffer, buffer + length, xs);
}

void countingsort(int* xs, size_t length) {
	// Find min and max elements
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < length; ++i) {
		min = std::min(xs[i], min);
		max = std::max(xs[i], max);
	}

	countingsort(xs, length, min, max);
}
