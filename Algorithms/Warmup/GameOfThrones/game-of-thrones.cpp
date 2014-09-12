#include <iostream>
#include <cassert>
#include <string>
#include <bitset>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::bitset;

#define MIN_LENGTH 1
#define MAX_LENGTH 100000
#define ALPHABET_SIZE 26

int main() {
    string str = "";
    cin >> str;
    size_t strLength = str.length();
    assert(strLength >= MIN_LENGTH && strLength <= MAX_LENGTH);

    bitset<ALPHABET_SIZE> characters = 0;
    for(string::iterator it = str.begin(); it != str.end(); ++it){
        assert(*it >= 'a' && *it <= 'z');
        characters.flip(*it - 'a');
    }

    cout << ((strLength % 2 == characters.count()) ? "YES" : "NO") << endl;
    return 0;
}