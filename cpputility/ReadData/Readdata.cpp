/*
 * getinputdata.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

/*
http://en.cppreference.com/w/cpp/io

http://upload.cppreference.com/mwiki/images/0/06/std-io-complete-inheritance.svg

 ios_base <-- ios <--  istream  <--  iostream  <--  fstream <--  stringstream
                  <--  ostream

 */

/*
 *
 *   Read the stream data, delimiter ","
 *
 *
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::stringstream;
using std::cout;
using std::string;
using std::vector;

using namespace std;

class getinputdata {
public:
    void read_input_int(vector<int> &input_data_int);
};

void getinputdata::read_input_int(vector<int> &input_data_int) {
    ifstream infile(
            "/home/songjiguo/workspace/interviewCode/src/cpputility/ReadData/dummy_int_data"); // need specifyt the name and path

    while (infile) {
        string s;
        if (!getline(infile, s))
            break;

        istringstream ss(s);

        while (ss) {
            string s;
            if (!getline(ss, s, ','))
                break;
            stringstream ints(s);
            int tmp = 0;  // (default value is 0)
            ints >> tmp;
            input_data_int.push_back(tmp);
        }

    }

    if (!infile.eof()) {
        std::cerr << "Failed to read!\n";
    }

}

int main() {
    getinputdata test;
    vector<int> data;
    test.read_input_int(data);
    for (auto e : data)
        cout << e << endl;
}
