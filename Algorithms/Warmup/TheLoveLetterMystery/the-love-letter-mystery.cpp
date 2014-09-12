#include <stdlib.h> 
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::distance;

int main() {
    int testCases = 0;
    cin >> testCases;
    
    assert(testCases >= 1 && testCases <= 10);

    vector<int> results;
    string str = "";
    while(testCases--){
    	cin >> str;
    	assert(str.length() >= 1 && str.length() <= 10000);

    	string::iterator front = str.begin(), back = --str.end();
    	int modCount = 0;
    	while(front <= back){
    		assert(*front >= 'a' && *front <= 'z');
    		assert(*back >= 'a' && *back <= 'z');
			modCount += abs(*front - *back);
    		++front;
    		--back;
    	}
    	results.push_back(modCount);
    }

   for (vector<int>::iterator it = results.begin(); it != results.end(); ++it){
		cout << *it << endl;
	}
    
    return 0;
}