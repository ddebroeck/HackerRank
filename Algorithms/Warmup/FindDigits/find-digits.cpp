#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

#define MIN_TEST_CASES 1
#define MAX_TEST_CASES 15

#define MIN_VALUE 0
#define MAX_VALUE 10000000000

int main(int argc, char **argv)
{
	int testCases = 0;
	cin >> testCases;
	assert(testCases >= MIN_TEST_CASES && testCases <= MAX_TEST_CASES);

	long long n = 0, walker = 0, tmp = 0, result = 0;
	while(testCases--){
		cin >> n;
		assert(n > MIN_VALUE && n < MAX_VALUE);
		walker = n;
		while(walker > 0){
			tmp = walker % 10;
			if(tmp != 0 && (n % tmp) == 0)
				result++;
			walker /= 10;
		}
		cout << result << endl;
		result = 0;
	}
	return 0;
}
