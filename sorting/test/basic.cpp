#include "insertionsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "countingsort.h"

#include "bootstrap/unittest.h"

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
using namespace unittest;

int main()
{
	TestRunner runner;

	runner.runTest("insertion_sort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		int expected[5] = {1, 2, 3, 4, 5};

		insertionsort(xs, 5);
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTest("mergesort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		int expected[5] = {1, 2, 3, 4, 5};

		mergesort(xs, 5);
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTest("heapsort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		int expected[5] = {1, 2, 3, 4, 5};

		heapsort(xs, 5);
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTest("quicksort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		int expected[5] = {1, 2, 3, 4, 5};

		quicksort(xs, 5);
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTest("countingsort", []() {
		int xs[5] = {4, 5, 1, 3, 2};
		int expected[5] = {1, 2, 3, 4, 5};

		countingsort(xs, 5);
		assertArrayEquals<int>(expected, xs, 5);
	});

	runner.runTests();
}
