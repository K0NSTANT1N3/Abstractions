#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "vector.h"
#include <time.h>
#include "split.h"
#include "listvector.h"
#include "random.h"

using namespace std;

void printTestResults(bool passed, int testNum, int & passedCounter) {
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}

const int splitTestsNum = 27;

string splitTests[splitTestsNum] = {
	"050043",
	"10009998",
	"1098765432",
	"4771447713",
	"0568805687",
	"0420419418",
	"0095749573",
	"7442774426",
	"1110987605",
	"6088006087",
	"4994980497",
	"2423222120",
	"1847918478",
	"1589515894",
	"1817161514",
	"4107841077",
	"0638406383",
	"53520515049",
	"05265250524",
	"05955940593",
	"02605826057",
	"001",
	"1234",
	"9080701",
	"3202872336",
	"0166537080",
	"1051546050"
};

bool splitTestAnswers[splitTestsNum] = {
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	false,
	false,
	false,
	false,
	false,
	false
};

bool runSplitTest(int testNum) {
	return splitString(splitTests[testNum-1]) == splitTestAnswers[testNum-1];
}

void runSplitTests() {
	cout << "### Run Split tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=splitTestsNum; testNum++) {
		bool res = runSplitTest(testNum);
		printTestResults(res && splitString("050043") && !splitString("9080701"), 
						testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

bool isEqual(Vector<int> &expected, ListVector &actual) {
	if (expected.size() != actual.size()) {
		return false;
	}
	for (int i=0; i<expected.size(); i++) {
		if (expected[i] != actual.get(i)) {
			return false;
		}
	}
	return true;
}

void addNumbers(int num, Vector<int> &expected, ListVector &actual) {
	for (int i=0; i<num; i++) {
		int v = randomInteger(0, 1000);
		expected.add(v);
		actual.add(v);
	}
}

void insert(int index, int v, Vector<int> &expected, ListVector &actual) {
	expected.insert(index, v);
	actual.insert(index, v);
}

void insertNumbers(int num, Vector<int> &expected, ListVector &actual) {
	for (int i=0; i<num; i++) {
		int v = randomInteger(0, 1000);
		int index = randomInteger(0, expected.size()) ;
		insert(index, v, expected, actual);
	}
}

void removeNumbers(int num, Vector<int> &expected, ListVector &actual) {
	for (int i=0; i<num; i++) {
		if (expected.size() == 0) {
			break;
		}
		int index = randomInteger(0, expected.size()-1) ;
		expected.remove(index);
		actual.remove(index);
	}
}

bool runListVectorTest(int testNum) {
	setRandomSeed(testNum);
	Vector<int> expected;
	ListVector actual;
	switch (testNum) {
		case 1:
			addNumbers(1, expected, actual);
			break;
		case 2:
			addNumbers(5, expected, actual);
			break;
		case 3:
			addNumbers(10, expected, actual);
			break;
		case 4:
			insertNumbers(1, expected, actual);
			break;
		case 5:
			insertNumbers(2, expected, actual);
			break;
		case 6:
			insertNumbers(3, expected, actual);
			break;
		case 7:
			insertNumbers(3, expected, actual);
			break;
		case 8:
			insertNumbers(3, expected, actual);
			break;
		case 9:
			insertNumbers(4, expected, actual);
			break;
		case 10:
			insertNumbers(5, expected, actual);
			break;
		case 11:
			insertNumbers(3, expected, actual);
			addNumbers(2, expected, actual);
			break;
		case 12:
			insertNumbers(1, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(1, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 13:
			insertNumbers(3, expected, actual);
			addNumbers(2, expected, actual);
			insertNumbers(4, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 14:
			insertNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(4, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 15:
			insertNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(5, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 16:
			insertNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(6, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 17:
			insertNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(10, expected, actual);
			addNumbers(2, expected, actual);
			break;
		case 18:
			insertNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(13, expected, actual);
			addNumbers(2, expected, actual);
			break;
		case 19:
			insertNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(10, expected, actual);
			addNumbers(2, expected, actual);
			break;
		case 20:
			insertNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			insertNumbers(15, expected, actual);
			addNumbers(2, expected, actual);
			break;
		case 21:
			addNumbers(2, expected, actual);
			removeNumbers(1, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 23:
			addNumbers(2, expected, actual);
			removeNumbers(1, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 24:
			addNumbers(3, expected, actual);
			removeNumbers(2, expected, actual);
			addNumbers(3, expected, actual);
			removeNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 25:
			addNumbers(3, expected, actual);
			removeNumbers(2, expected, actual);
			insertNumbers(3, expected, actual);
			removeNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 26:
			insertNumbers(3, expected, actual);
			removeNumbers(2, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 27:
			insertNumbers(3, expected, actual);
			removeNumbers(2, expected, actual);
			addNumbers(2, expected, actual);
			removeNumbers(1, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 28:
			addNumbers(4, expected, actual);
			removeNumbers(3, expected, actual);
			insertNumbers(3, expected, actual);
			removeNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 29:
			insertNumbers(5, expected, actual);
			removeNumbers(4, expected, actual);
			addNumbers(3, expected, actual);
			removeNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 30:
			insertNumbers(7, expected, actual);
			removeNumbers(5, expected, actual);
			addNumbers(3, expected, actual);
			removeNumbers(3, expected, actual);
			addNumbers(1, expected, actual);
			break;
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
			addNumbers(15000, expected, actual);
	}
	return isEqual(expected, actual);
}
const int vectorTestsNum = 35;
void runListVectorTests() {
	cout << "### Run Vector tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=vectorTestsNum; testNum++) {
		bool res = runListVectorTest(testNum);
		printTestResults(res, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

#define TEST_RESULTS_FOLDER_PATH "D:\\freeuni\\courses\\cs106b\\exams repo\\cs106b\\testing\\"
void runTestFromTesterFile() {
	string testFile = string(TEST_RESULTS_FOLDER_PATH) + "test.txt";
	ifstream inp(testFile.c_str());
	string problemName;
	int testNum;
	inp >> problemName >> testNum;

	string outputFile = string(TEST_RESULTS_FOLDER_PATH) + "result.txt";

	bool passed = runListVectorTest(testNum);
	ofstream out(outputFile.c_str());
	if (passed) {
		out << testNum << endl;
	}
	out.close();
}

int main() {
	runTestFromTesterFile();
	//runListVectorTests();
	cout << "end" << endl;
	return 0;
}
