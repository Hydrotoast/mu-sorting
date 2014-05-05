#include "quicksort.h"
#include "insertion_sort.h"
#include <algorithm>

inline int median_of_three(int* xs, int lo, int hi) {
	int mid = (hi + lo) / 2;
	if (xs[hi] < xs[lo]) std::swap(xs[lo], xs[hi]);
	if (xs[mid] < xs[lo]) std::swap(xs[lo], xs[mid]);
	if (xs[hi] < xs[mid]) std::swap(xs[mid], xs[lo]);
	return mid;
}

inline int partition(int* xs, int lo, int hi) {
	int mid = median_of_three(xs, lo, hi);
	std::swap(xs[lo], xs[mid]);
	int p = xs[lo];
	int left = lo + 1;
	int right = hi;
	while (left < right) {
		while (xs[left] <= p) left++;
		while (xs[right] > p) right--;
		if (left < right) std::swap(xs[left], xs[right]);
	}
	std::swap(xs[lo], xs[right]);
	return right;
}

void quicksort(int* xs, int lo, int hi, size_t base_size) {
	if (lo >= hi)
		return;
	if (hi - lo <= base_size) {
		insertion_sort(xs, lo, hi);
		return;
	}

	int pivot = partition(xs, lo, hi);
	// Recursive partition
	quicksort(xs, lo, pivot - 1, base_size);
	quicksort(xs, pivot + 1, hi, base_size);
}

void quicksort(int* xs, size_t length, size_t base_size) {
	quicksort(xs, 0, length - 1, base_size);
}

void quicksort(int* xs, size_t length) {
	quicksort(xs, length, 32);
}
