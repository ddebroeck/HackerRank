#include <cstdio>
#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

#define MIN_TEST_CASES 1
#define MAX_TEST_CASES 1000

#define MIN_FUNDS 2
#define MAX_FUNDS 100000

#define MIN_PRICE 1

#define MIN_WRAPPERS_REQUIRED 2

int consumedUsingDiscount(int wrappers, int wrappersRequiredForDiscount)
{
    if(wrappers < wrappersRequiredForDiscount){
        return 0;
    }
    else{
        int consumed = wrappers / wrappersRequiredForDiscount;
        wrappers = consumed + (wrappers % wrappersRequiredForDiscount);
        return consumed + consumedUsingDiscount(wrappers, wrappersRequiredForDiscount);
    }
}   

int main() {  
    int testCases = 0, availableFunds = 0, priceOfChocolate = 0, 
        wrappersRequiredForDiscount = 0, consumed = 0;
    cin >> testCases;
    assert(testCases >= MIN_TEST_CASES && testCases <= MAX_TEST_CASES);

    while(testCases--){
        cin >> availableFunds;
        assert(availableFunds >= MIN_FUNDS && availableFunds <= MAX_FUNDS);

        cin >> priceOfChocolate; 
        assert(priceOfChocolate >= MIN_PRICE && priceOfChocolate <= availableFunds);

        cin >> wrappersRequiredForDiscount;
        assert(wrappersRequiredForDiscount >= MIN_WRAPPERS_REQUIRED && wrappersRequiredForDiscount <= availableFunds);

        consumed = (availableFunds / priceOfChocolate);
        cout << consumed + consumedUsingDiscount(consumed, wrappersRequiredForDiscount) << endl;
    }
    return 0;
}