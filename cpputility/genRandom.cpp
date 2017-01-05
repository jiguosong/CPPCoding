/*
 * genRandom.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: songjiguo
 */

#include <random>
#include <iostream>

int main()
{
	std::random_device rd;
	std::mt19937 some_generator(rd());
	std::uniform_int_distribution<uint32_t> dist(1,10);

	std::cout << dist(some_generator) << std::endl;
}

