/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

    Consider the palindromes of odd vs even length. What difference do you notice?
    Count the frequency of each character.
    If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?


*/

#include "palindromepermutation.h"
#include <unordered_map>
#include <set>
#include <bitset>

void palindromepermutation::dummy() {
}

bool palindromepermutation::canPermutePalindrome(string s) {
//    std::unordered_map<char, int> count_map;
//    for (auto c:s) ++count_map[c];
//    int num_odd = 0;
//    for (auto it = count_map.begin(); it != count_map.end(); ++it) {
//        if (it->second & 1 == 1) ++num_odd;
//    }
//    return num_odd <= 1;

//    std::set<char> cset;
//    for (auto c:s) {
//        if (cset.find(c) == cset.end()) cset.insert(c);
//        else cset.erase(c);
//    }
//    return cset.empty() || cset.size() == 1;

    std::bitset<256> cbitset;
    for (auto c:s) {
        cbitset[c].flip();
    }

    return cbitset.count() < 2;
}


