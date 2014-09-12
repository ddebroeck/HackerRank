#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define BITS_PER_BYTE 8

static const short kNumberOfElements = ('z'-'a') + 1;

void setBit(const short bit, unsigned int &bitArray){
	int bitmask = 0 | (1 << bit);
	bitArray |= bitmask;
}

bool analyzeComposition(const string &completeComposition, unsigned int &comprisedOf){
	size_t compositionLength = completeComposition.length();
	if(compositionLength < 1 || compositionLength > 100)
		return false;

	for(int i = 0; i < compositionLength; i++){
		short element = (completeComposition[i] - 'a');
		if(element < 0 || element > kNumberOfElements)
			return false;

		setBit(element, comprisedOf);
	}
	return true;
}

int main(int argc, char **argv){

	if(kNumberOfElements > (sizeof(unsigned int) * BITS_PER_BYTE)){
		cout << "Unexpected number of possible elements, cannot perform analysis.";
		return 1;
	}

	int numberOfRocks = 0;
    cin >> numberOfRocks;
    if(numberOfRocks < 1 || numberOfRocks > 100){
    	cout << "Invalid number of rocks provided (1 >= valid <= 100)." << endl;
    	return 1;
    }

	unsigned int gemElements = ~0; 
    string completeComposition = "";
    unsigned int comprisedOf = 0;
    for(int i = 0; i < numberOfRocks; i++){
    	cin >> completeComposition;
    	if(!analyzeComposition(completeComposition, comprisedOf)){
    		cout << "Invalid composition detected (" << completeComposition << "), gem-element analysis inconclusive." << endl;
    		return 1;
    	}

    	gemElements &= comprisedOf;
    	comprisedOf = 0;
    }

    unsigned int gemElementCount = 0;
    for (int j = 0; j < kNumberOfElements; ++j){
    	gemElementCount += ((gemElements >> j) & 1);
    }

    cout << gemElementCount << endl;
    return 0;
}