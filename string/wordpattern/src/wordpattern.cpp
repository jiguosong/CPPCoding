/*
 * wordpattern.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "wordpattern.h"
#include <unordered_map>
#include <sstream>
#include <iostream>

// exmple : if the delimeters is not space
//std::string input = "abc,def,ghi";
//std::istringstream ss(input);
//std::string token;
//
//while(std::getline(ss, token, ',')) {
//    std::cout << token << '\n';
//}

bool solution::wordPattern(std::string pattern, std::string str)
{
	std::unordered_map<char, std::string> map;

	std::istringstream in(str);
	std::string tmp;
	unsigned int i = 0;
	while(in >> tmp) {
		if(map.find(pattern[i]) == map.end()) {  // not found
			for(std::unordered_map<char, std::string>::iterator it = map.begin();
					it != map.end(); ++it) {
				if(it->second == tmp) return false;
			}
			map[pattern[i]] = tmp;
		} else {
			if (map[pattern[i]] != tmp) return false;
		}
		++i;
	}

	return i == pattern.size();

}

bool solution::wordPatternMatch(std::string pattern, std::string str)
{
	//TODO: this is hard

	return true;
}
