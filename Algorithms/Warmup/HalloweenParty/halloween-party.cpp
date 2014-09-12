#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define MIN_TEST_CASES 1
#define MAX_TEST_CASES 10
#define MIN_CUTS 2
#define MAX_CUTS 10000000

int main() {
    int testCases = 0;
    cin >> testCases;
    
    assert(testCases >= MIN_TEST_CASES && testCases <= MAX_TEST_CASES);

    long long allowedCuts = 0, hCuts = 0, vCuts = 0;
    while(testCases--){
        cin >> allowedCuts;
        assert(allowedCuts >= MIN_CUTS && allowedCuts <= MAX_CUTS);
        hCuts = allowedCuts / 2;
        vCuts = hCuts + (allowedCuts % 2);
        cout << hCuts * vCuts << endl;
    }

    return 0;
}