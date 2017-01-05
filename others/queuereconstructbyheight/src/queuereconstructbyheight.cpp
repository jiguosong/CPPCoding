/*

*/

#include "queuereconstructbyheight.h"
#include <algorithm>

void queuereconstructbyheight::dummy() {
}


#include <iostream>
vector<std::pair<int, int>> queuereconstructbyheight::reconstructQueue(vector<std::pair<int, int>> &people) {
/*    sort(people.begin(), people.end(), [](const std::pair<int, int> a, const std::pair<int, int> b) {
        a.first > b.first || (a.first == b.first && a.second < b.second);
    });*/
    sort(people.begin(), people.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return (a.first > b.first || (a.first == b.first && a.second < b.second));
    });

    for(auto p:people) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    std::cout << std::endl;

    vector<std::pair<int, int>> res;
    for (auto a:people) {
        res.insert(res.begin() + a.second, a);
    }

    return res;
}
