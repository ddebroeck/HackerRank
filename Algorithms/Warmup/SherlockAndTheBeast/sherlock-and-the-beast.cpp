#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

#define MIN_TEST_CASES 1
#define MAX_TEST_CASES 20

#define MIN_DIGITS 1
#define MAX_DIGITS 100000

int main(int argc, char **argv)
{
	int testCases = 0;
	cin >> testCases;
	assert(testCases >= MIN_TEST_CASES && testCases <= MAX_TEST_CASES);

	int digits = 0, remainingDigits = 0;
	while(testCases--){
		cin >> digits;
		assert(digits >= MIN_DIGITS && digits <= MAX_DIGITS);

		int setsOfFives = 0, setsOfThrees = 0;
		setsOfFives = digits / 3;
		remainingDigits = digits % 3;
		
		if(remainingDigits > 0){
			if(remainingDigits == 1 && setsOfFives >= 3){
				setsOfFives -= 3;
				setsOfThrees = 2;
			}
			else if(remainingDigits == 2 && setsOfFives >= 1){
				setsOfFives -= 1;
				setsOfThrees = 1;
			}
			else{
				setsOfFives = 0;
			}
		}

		if((setsOfFives + setsOfThrees) > 0){
			while(setsOfFives--){
				cout << "555";
			}
			while(setsOfThrees--){
				cout << "33333";
			}
		}
		else{
			cout << "-1";
		}
		cout << endl;
	}
	return 0;
}
