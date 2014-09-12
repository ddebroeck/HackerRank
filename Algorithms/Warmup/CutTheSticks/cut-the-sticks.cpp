#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::distance;

#define MIN_VALUE 1
#define MAX_VALUE 1000

int main() {
    int sticks = 0;
    cin >> sticks;
    assert(sticks >= MIN_VALUE && sticks <= MAX_VALUE);

    vector<int> lengths;
    int length = 0;
    while(sticks--){
        cin >> length;
        lengths.push_back(length);
    }

    sort(lengths.begin(), lengths.end());

    int sumCutLengths = 0;
    for(vector<int>::iterator it = lengths.begin(); it < lengths.end(); ++it){
        assert(*it >= MIN_VALUE && *it <= MAX_VALUE);

        if( (*it - sumCutLengths) > 0 ){
            sumCutLengths += (*it - sumCutLengths);
            cout << distance(it, lengths.end()) << endl;
        }
    }
    return 0;
}