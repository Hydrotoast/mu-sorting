#include "mergesort.h"
#include "insertion_sort.h"
#include <algorithm>

inline void merge(int* buffer, int* left, size_t left_length, int* right, 
		   size_t right_length) {
	int k = 0;
	int i = 0;
	int j = 0;
	int size = left_length + right_length;
	while (i < left_length && j < right_length)
		buffer[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
	if (i < left_length)
		std::copy(left + i, left + left_length, buffer + k);
	if (j < right_length)
		std::copy(right + j, right + right_length, buffer + k);
	std::copy(buffer, buffer + size, left);
}

void mergesort(int* xs, int* buffer, int lo, int hi, size_t base_size) {
	if (lo >= hi)
		return;
	if (hi - lo <= base_size) {
		insertion_sort(xs, lo, hi);
		return;
	}

	int mid = (hi + lo) / 2;
	mergesort(xs, buffer, lo, mid, base_size);
	mergesort(xs, buffer, mid + 1, hi, base_size);
	merge(buffer, xs + lo, mid - lo + 1, xs + mid + 1, hi - mid);
}

void mergesort(int* xs, size_t length, size_t base_size) {
	int* buffer = new int[length];
	mergesort(xs, buffer, 0, length - 1, base_size);
	delete[] buffer;
}

void mergesort(int* xs, size_t length) {
	mergesort(xs, length, 32);
}
