#include "insertion_sort.h"
#include "mergesort.h"
#include "quicksort.h"

#include "debug.h"
#include "benchmark.h"

#include <fstream>
#include <sstream>
#include <cstdlib>

#define SAMPLE_SZ 10000000

using namespace std;

int main(int argc, char* argv[]) {
	int* samples = new int[SAMPLE_SZ];
	ifstream input("/tmp/samples.bin", ios::in | ios::binary);

	LOG_INFO("Compiled with -O3")
	LOG_INFO("Sorting 10,000,000 integers")
	LOG_INFO("x ~ U(0, 1024*1024)")
	cout << endl;

	input.seekg(0);
	input.read((char*)samples, sizeof(int)*SAMPLE_SZ);
	benchmark::unit("glibc-qsort", [samples]() {
		qsort(samples, SAMPLE_SZ, sizeof(int), [](const void* a, const void* b) -> int {
			int arg1 = *reinterpret_cast<const int*>(a);
			int arg2 = *reinterpret_cast<const int*>(b);
			if(arg1 < arg2) return -1;
			if(arg1 > arg2) return 1;
			return 0;
		});
	});

	ostringstream oss;
	for (int i = 8; i <= 64; i *= 2) {
		input.seekg(0);
		input.read((char*)samples, sizeof(int)*SAMPLE_SZ);
		
		oss << "gcielo-mergesort(base_size=" << i << ")";
		benchmark::unit(oss.str(), [samples, i]() {
			mergesort(samples, SAMPLE_SZ, i);
		});
		oss.str("");
	}

	for (int i = 8; i <= 64; i *= 2) {
		input.seekg(0);
		input.read((char*)samples, sizeof(int)*SAMPLE_SZ);

		oss << "gcielo-quicksort(base_size=" << i << ")";
		benchmark::unit(oss.str(), [samples, i]() {
			quicksort(samples, SAMPLE_SZ, i);
		});
		oss.str("");
	}

	input.close();
	delete[] samples;
}
