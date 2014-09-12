#include <iostream>
#include <set>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::set;

#define MIN_TEST_CASES 1
#define MAX_TEST_CASES 10

#define MIN_VALUE 1
#define MAX_VALUE 1000

int main(int argc, char **argv)
{
	int testCases = 0;
	cin >> testCases;

	assert(testCases >= MIN_TEST_CASES && testCases <= MAX_TEST_CASES);

	int stones = 0, a = 0, b = 0;
	while(testCases--){
		cin >> stones;
		assert(stones >= MIN_VALUE && stones <= MAX_VALUE);
		cin >> a;
		assert(a >= MIN_VALUE && a <= MAX_VALUE);
		cin >> b;
		assert(b >= MIN_VALUE && b <= MAX_VALUE);

		if(a < b){
			int tmp = b;
			b = a;
			a = tmp;
		}

		set<int> possibleValues;
		for(int i = 0; i < stones; i++){
			possibleValues.insert( i*a + (stones-i-1)*b );
		}

		for(set<int>::iterator it = possibleValues.begin(); it != possibleValues.end(); it++){
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}