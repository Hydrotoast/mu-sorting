#include "heapsort.h"
#include <algorithm>

#include <string>
#include "bootstrap/debug.h"

// Requires that the elements below index i have
// the heap property.
// 
// @xs				heap pointer
// @xs_length		size of the heap
// @i				index of element to heapify
void sift_down(int* xs, size_t xs_length, int i) {
	if (i >= xs_length)
		return;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int max_elem = i;
	if (left < xs_length && xs[left] > xs[max_elem])
		max_elem = left;
	if (right < xs_length && xs[right] > xs[max_elem])
		max_elem = right;
	if (max_elem != i) {
		std::swap(xs[max_elem], xs[i]);
		sift_down(xs, xs_length, max_elem);
	}
}

// Builds a heap from an unsorted array list in-place.
//
// @xs			heap pointer
// @xs_length	size of the heap
void build_heap(int* xs, size_t xs_length) {
	for (int i = xs_length / 2; i >= 0 ; --i)
		sift_down(xs, xs_length, i);
}

void heapsort(int* xs, size_t xs_length) {
	build_heap(xs, xs_length);
	size_t heap_length = xs_length;
	while (heap_length > 0) {
		std::swap(xs[0], xs[--heap_length]);
		sift_down(xs, heap_length, 0);
	}
}
