#include "insertion_sort.h"
#include "quicksort.h"
#include "mergesort.h"

#include "unittest.h"

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace unittest;

int main()
{
	TestRunner runner;

	runner.runTest("insertion_sort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		insertion_sort(xs, 5);
		int expected[5] = {1, 2, 3, 4, 5};
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTest("mergesort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		mergesort(xs, 5);
		int expected[5] = {1, 2, 3, 4, 5};
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTest("quicksort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		quicksort(xs, 5);
		int expected[5] = {1, 2, 3, 4, 5};
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTests();
}
