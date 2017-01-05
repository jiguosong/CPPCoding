/*

*/

#include "generalizedabbreviation.h"

void generalizedabbreviation::dummy() {
}

static void helper(string &word, int level, vector<string> &res) {
    for (int i = level; i < word.size(); ++i) {
        for (int j = 1; i + j <= word.size(); ++j) {
            string t = word.substr(0, i);
            t += std::to_string(j) + word.substr(i + j);
            res.push_back(t);
            helper(t, i + 1 + std::to_string(j).size(), res);
        }
    }
}

vector<string> generalizedabbreviation::generateAbbreviations(string word) {
    vector<string> res{word};
    helper(word, 0, res);
    return res;
}