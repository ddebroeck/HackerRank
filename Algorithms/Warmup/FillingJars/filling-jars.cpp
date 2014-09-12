#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

#define MIN_JARS 3
#define MAX_JARS 10000000

#define MIN_OPERATIONS 1
#define MAX_OPERATIONS 100000

#define MIN_CANDIES 0
#define MAX_CANDIES 1000000

#define MIN_INDEX 1

int main(int argc, char **argv)
{
	long long jars = 0, operations = 0;
	cin >> jars >> operations;
	assert(jars >= MIN_JARS && jars <= MAX_JARS);
	assert(operations >= MIN_OPERATIONS && operations <= MAX_OPERATIONS);

	long long sumOfCandies = 0, a = 0, b = 0, candiesToAdd = 0;
	while(operations--){
		cin >> a >> b >> candiesToAdd;
		assert(a >= MIN_INDEX && a <= jars && a <= b);
		assert(b <= jars);
		assert(candiesToAdd >= MIN_CANDIES && candiesToAdd <= MAX_CANDIES);
		sumOfCandies += ((b-a)+1)*candiesToAdd;
	}
	cout << sumOfCandies / jars << endl;
	return 0;
}
