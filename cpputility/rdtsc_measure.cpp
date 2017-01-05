/*
 * rdtsc_measure.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <chrono>

namespace x
{

struct clock
{
	typedef unsigned long long rep;
	typedef std::ratio<1, 2800000000> period; // My machine is 2.8 GHz
	typedef std::chrono::duration<rep, period> duration;
	typedef std::chrono::time_point<clock> time_point;
	static const bool is_steady = true;

	static time_point now() noexcept
	{
		unsigned lo, hi;
		asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
		return time_point(duration(static_cast<rep>(hi) << 32 | lo));
	}
};
}  // x

template<class clock>
void test_empty_loop()
{
	// Define real time units
	typedef std::chrono::duration<unsigned long long, std::pico> picoseconds;
	// or:
	// typedef std::chrono::nanoseconds nanoseconds;
	// Define double-based unit of clock tick
	typedef std::chrono::duration<double, typename clock::period> Cycle;
	using std::chrono::duration_cast;
	const int N = 100000000;
	// Do it
	auto t0 = clock::now();
	for (int j = 0; j < N; ++j)
		asm volatile("");
	auto t1 = clock::now();
	// Get the clock ticks per iteration
	auto ticks_per_iter = Cycle(t1 - t0) / N;
	std::cout << ticks_per_iter.count() << " clock ticks per iteration\n";
	// Convert to real time units
	std::cout << duration_cast<picoseconds>(ticks_per_iter).count() << "ps per iteration\n";
}

int main()
{
	std::cout << "\nUsing rdtsc:\n";
	test_empty_loop<x::clock>();

	std::cout << "\nUsing std::chrono::high_resolution_clock:\n";
	test_empty_loop<std::chrono::high_resolution_clock>();

	std::cout << "\nUsing std::chrono::system_clock:\n";
	test_empty_loop<std::chrono::system_clock>();
}

