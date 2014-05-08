#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <sstream>
#include <functional>
#include <chrono>
#include <cmath>

namespace benchmark {

void unit(std::string name, std::function<void()> f) {
	auto start = std::chrono::steady_clock::now();
	f();
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	double duration = (double)elapsed.count();

	std::cout.precision(4);
	std::cout << std::scientific;
	std::cout << name << ": " << duration << " ms" << std::endl;
}

}

#endif
