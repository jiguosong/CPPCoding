using namespace std;
#include <iostream>

class solution{
public:
	int lengthOfLongestNoRepSubstring(string s) {
		int res = 0;
		int m[256] = {0};
		int left = 0;

		for (int i = 0; (size_t)i < s.size(); i++) {
			if (m[s[i]] == 0 || m[s[i]] < left) {
				res = max(res, i-left+1);
			} else {
				left = m[s[i]];
			}
			m[s[i]] = i+1;  // make it different from 0
		}
		return res;
	}

	static solution &Instance() {
		solution *p = new solution;
		return *p;
	}

private:
	solution(){};
	~solution(){};
	solution(const solution &other);
	const solution &operator=(const solution &other);
};

int main(){
	cout << "CPP:lengthOfLongestSubstring" << endl;
	string A = "abbca";
	cout << A << endl;

	solution &test = solution::Instance();
	int result = test.lengthOfLongestNoRepSubstring(A);
	cout << result << endl;

	return 0;
}
