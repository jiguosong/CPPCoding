/*
 * multithreadMonteCarlo.cpp
 *
 *  Created on: Dec 28, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "prng_engine.hpp"

std::mutex mutex;
long thread_counter;
long total_samples;
long total_sum;

void threadfunc()
{
	sitmo::prng_engine eng;
	long sum = 0;
	long samples = 1000000;

	// Initialize the prng in this thread with a unique seed
	{
		std::lock_guard<std::mutex> guard(mutex);
		eng.seed(thread_counter++);
	}

	// Compute the sum or 1 million random samples
	for (long i = 0; i < samples; ++i)
		sum += eng();

	// Add the computed values in this thread to the global sum
	{
		std::lock_guard<std::mutex> guard(mutex);
		total_sum += sum;
		total_samples += samples;
	}
}

int main()
{
	total_samples = 0;
	total_sum = 0;

	// Launch 128 threads
	std::vector<std::thread> threads;
	for (int i = 0; i < 128; ++i) {
		threads.push_back(std::thread(threadfunc));
	}

	// Wait for all threads to finish
	for (auto& thread : threads) {
		thread.join();
	}

	std::cout << thread_counter << " threads generated " << total_samples
			<< " random numbers, the sum of them is " << total_sum << std::endl;
}
