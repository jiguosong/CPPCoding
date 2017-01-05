using namespace std;

#include <iostream>

class palindromenumber{
public:
	bool isPalindromenumber(int num) {
		int k = 0;
		int p = num;

		while(p) {
			k = k*10 + p%10;
			p = p/10;
		}

		return (k == num);
	}


};

int main(int argc, char **argv){
		cout << "CPP:isPalindromenumber" << endl;
		int num = 121;
		palindromenumber test;
		if (test.isPalindromenumber(num)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
