/*
 * hello.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

template<typename Iterator, typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T &result)
	{
		std::cout << "thread " << std::this_thread::get_id()
				<< " computing....." << std::endl;
		result = std::accumulate(first, last, result);
	}
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	unsigned long const len = std::distance(first, last);
	if (!len)
		return init;
	unsigned long const min_per_thread = 6;
	unsigned long const max_thread =
			(len + min_per_thread - 1) / min_per_thread;

	unsigned long const hardware_threads = std::thread::hardware_concurrency();
	unsigned long const thread_nums = std::min(
			hardware_threads != 0 ? hardware_threads : 2, max_thread);

	unsigned long const block_size = len / thread_nums;
	std::vector<T> result(thread_nums);
	std::vector<std::thread> threads(thread_nums - 1); // the creator thread is also doing some work

	Iterator block_start = first;
	std::cout << "max_thread " << max_thread << std::endl;
	std::cout << "len " << len << std::endl;
	std::cout << "min_per_thread " << min_per_thread << std::endl;
	std::cout << "thread_nums " << thread_nums << std::endl;
	std::cout << std::endl;
	for (unsigned long i = 0; i < (thread_nums - 1); ++i) {
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start,
				block_end, std::ref(result[i]));
		block_start = block_end;
	}

	accumulate_block<Iterator, T>()(block_start, last, result[thread_nums - 1]);
	std::for_each(threads.begin(), threads.end(),
			std::mem_fn(&std::thread::join));

	return std::accumulate(result.begin(), result.end(), init);

}

void hello()
{
	std::cout << "Hello" << std::endl;
}

int main()
{
	std::vector<std::thread> threads;

	for (int i = 0; i < 20; ++i)
		threads.push_back(std::thread(hello));
	std::for_each(threads.begin(), threads.end(),
			std::mem_fn(&std::thread::join));

	std::vector<int> t = { 1, 2, 3, 4, 4, 5, 6, 76, 7, 3, 4, 5, 4, 56, 34, 64,
			7, 345, 24, 57, 3467, 356, 73, 67 };

	int ans = parallel_accumulate<std::vector<int>::iterator, int>(t.begin(),
			t.end(), 0);
	std::cout << ans << std::endl;
}

