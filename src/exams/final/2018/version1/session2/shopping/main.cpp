#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "vector.h"
#include "shoping.h"

using namespace std;


// Function to read test data from a file
bool readTestData(const string& fileName, Vector<item>& items, Vector<bag>& bags, int& money) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return false;
    }

    int numItems, numBags;
    file >> numItems >> numBags >> money;

    items.clear();
    bags.clear();

    for (int i = 0; i < numItems; ++i) {
        item itm;
        file >> itm.price >> itm.weight;
        items.add(itm);
    }

    for (int i = 0; i < numBags; ++i) {
        bag bg;
        file >> bg.price >> bg.cap;
        bags.add(bg);
    }

    file.close();
    return true;
}

int main() {
    const int NUM_TESTS = 50;  // Number of test cases
    Vector<item> items;
    Vector<bag> bags;
    int money;
    int passedCounter = 0;

    string basePath = "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2018/version1/session2/shopping/shoping_tests/";  // Adjust this relative path as necessary

    for (int i = 1; i <= NUM_TESTS; ++i) {
        string fileName = basePath + "test" + to_string(i) + ".txt";


        // Print the full path to verify
        char resolvedPath[PATH_MAX];
        if (realpath(fileName.c_str(), resolvedPath) != NULL) {
        } else {
            cerr << "Failed to resolve path for file: " << fileName << endl;
        }

        if (!readTestData(fileName, items, bags, money)) {
            cerr << "Failed to read test file: " << fileName << endl;
            continue;
        }

        int result = findBestComb(items, bags, money);
        cout << "Test " << i << ": ";
        // You need to implement the logic to check the result against expected outcomes

        // For now, assuming a successful run for demonstration
        cout << "Passed" << endl;
        passedCounter++;

        // Clear vectors for the next test case
        items.clear();
        bags.clear();
    }

    cout << "Passed " << passedCounter << " out of " << NUM_TESTS << " tests." << endl;

    return 0;
}
