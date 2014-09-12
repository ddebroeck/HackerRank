#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

#define MIN_VALUE 1
#define MAX_VALUE 1000

uint maxXor(uint l, uint r)
{
    uint max = 0, tmpL = l;
    while(tmpL <= r){
        uint tmp = l, res = 0;
        while(tmp <= r){
            res = tmpL ^ tmp;
            max = (res > max) ? res : max;
            ++tmp;
        }
        ++tmpL;
    }
    return max;
}

int main() {
    uint l = 0, r = 0;
    cin >> l;
    cin >> r;

    assert(l >= MIN_VALUE && l <= MAX_VALUE);
    assert(r >= MIN_VALUE && r <= MAX_VALUE);
    assert(l <= r);

    cout << maxXor(l, r) << endl;
    return 0;
}