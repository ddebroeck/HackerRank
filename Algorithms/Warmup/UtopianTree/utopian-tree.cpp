#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int height(int n) 
{
    if(n == 0)
        return 1;
    else
        return (n % 2 == 0) ? (1 + height(n - 1)) : (2 * height(n - 1));
}

int main(int argc, char **argv) 
{
    int testCases = 0;
    cin >> testCases;

    if(testCases >= 1 && testCases <= 10){
        vector<int> results;
        int growthCycles = 0;
        while(testCases--){
            cin >> growthCycles;
            if(growthCycles >= 0 && growthCycles <= 60)
                results.push_back(height(growthCycles));
            else
                cout << "Invalid number of growth cycles requested, skipping test case." << endl;
        }

        for(int i = 0; i < results.size(); i++){
            cout << results[i] << endl;
        }

    }
    else{
        cout << "Invalid number of test cases requested, cannot proceed with testing." << endl;
        return 1;
    }

    return 0;
}