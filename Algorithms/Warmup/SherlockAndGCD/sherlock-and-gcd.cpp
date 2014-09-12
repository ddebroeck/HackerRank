#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

#define MIN_TEST_CASES 1
#define MAX_TEST_CASES 10

#define MIN_ELEMENTS 1
#define MAX_ELEMENTS 100

#define MIN_VALUE 1
#define MAX_VALUE 100000

int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

int main(int argc, char **argv)
{
	int testCases = 0;
	cin >> testCases;
	assert(testCases >= MIN_TEST_CASES && testCases <= MAX_TEST_CASES);

	int elements = 0;
	while(testCases--){
		cin >> elements;
		assert(elements >= MIN_ELEMENTS && elements <= MAX_ELEMENTS);
		
		int value = 0, common = 0;
		while(elements--){
			cin >> value;
			assert(value >= MIN_VALUE && value <= MAX_VALUE);
			common = gcd(common, value);
		}

		cout << ((common == 1) ? "YES" : "NO") << endl;
	}
	return 0;
}
