#include <iostream>
#include <string>
#include "simpio.h"
#include "foreach.h"
#include "console.h"
#include <time.h>
#include "transport.h"
#include "random.h"
#include "vitamins.h"
#include "vector.h"
#include "set.h"


using namespace std;

void printTestResults(bool passed, int testNum, int& passedCounter) {
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	}
	else {
		cout << "test " << testNum << " failed" << endl;
	}
}

void fillItemsVec(Vector<itemT>& items, itemT* arr, int len) {
	for (int i = 0; i < len; i++) {
		items += arr[i];
	}
}

const int TransportTestsNum = 15;
const int VitaminsTestsNum = 15;

bool runTransportSingleTest(int testNum) {
	Vector<itemT> items;
	Vector<int> cars;
	itemT* arr;
	bool passed = false;
	switch (testNum) {
	case 1:
		cars += 20, 40, 60;
		arr = new itemT[4]{ {10, 20}, {11, 20}, {5, 10}, {30, 55} };
		fillItemsVec(items, arr, 4);
		passed = transportMax(cars, items, 60) == 105;
		break;
	case 2:
		cars += 20, 40, 60;
		arr = new itemT[4]{ {5, 10}, {30, 55}, {10, 20}, {11, 20} };
		fillItemsVec(items, arr, 4);
		passed = transportMax(cars, items, 60) == 105;
		break;
	case 3:
		cars += 20, 40, 60;
		arr = new itemT[4]{ {5, 10}, {10, 20}, {30, 55}, {11, 20} };
		fillItemsVec(items, arr, 4);
		passed = transportMax(cars, items, 30) == 55;
		break;
	case 4:
		cars += 10, 40, 70;
		arr = new itemT[4]{ {10, 25}, {30, 65}, {5, 15}, {10, 30} };
		fillItemsVec(items, arr, 4);
		passed = transportMax(cars, items, 60) == 105;
		break;
	case 5:
		cars += 20, 80, 19, 45, 75;
		arr = new itemT[6]{ {56, 70}, {10, 30}, {30, 65}, {26, 20}, {5, 15}, {25, 15} };
		fillItemsVec(items, arr, 6);
		passed = transportMax(cars, items, 70) == 125;
		break;
	case 6:
		cars += 1, 40, 96, 4, 3, 2;
		arr = new itemT[7]{ {10, 90}, {10, 65}, {10, 32}, {10, 11}, {10, 30}, {10, 11}, {10, 11} };
		fillItemsVec(items, arr, 7);
		passed = transportMax(cars, items, 70) == 128;
		break;
	case 7:
		cars += 4, 5, 8, 14, 20, 30, 20, 20, 12, 9;
		arr = new itemT[9]{ {10, 20}, {10, 20}, {10, 20}, {10, 20}, {10, 15}, {10, 20}, {10, 20}, {10, 20}, {10, 15} };
		fillItemsVec(items, arr, 9);
		passed = transportMax(cars, items, 100) == 90;
		break;
	case 8:
		cars += 1, 1, 1, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5;
		arr = new itemT[15]{ {2, 2}, {2, 2}, {2, 20}, {2, 20}, {4, 1}, {6, 20}, {10, 20}, {10, 20}, {10, 20}, {10, 15}, {10, 1}, {10, 5}, {10, 15}, {10, 15}, {10, 1} };
		fillItemsVec(items, arr, 15);
		passed = transportMax(cars, items, 100) == 12;
		break;
	case 9:
		cars += 1, 1, 1, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5;
		arr = new itemT[15]{ {21, 2}, {12, 2}, {2, 20}, {20, 1}, {14, 1}, {6, 20}, {10, 20}, {10, 20}, {1, 2}, {10, 15}, {10, 1}, {10, 5}, {10, 15}, {10, 15}, {10, 1} };
		fillItemsVec(items, arr, 15);
		passed = transportMax(cars, items, 2) == 2;
		break;
	case 10:
		cars += 1, 1, 1, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5;
		arr = new itemT[15]{ {21, 22}, {12, 12}, {2, 20}, {20, 11}, {14, 21}, {6, 20}, {10, 20}, {10, 20}, {1, 32}, {10, 15}, {10, 21}, {10, 15}, {10, 15}, {10, 15}, {10, 16} };
		fillItemsVec(items, arr, 15);
		passed = transportMax(cars, items, 200) == 0;
		break;
	case 11:
		cars += 1, 10, 10, 30, 31, 34, 23, 13, 40, 4;
		arr = new itemT[10]{ {6, 25}, {7, 24}, {8, 23}, {9, 22}, {10, 21}, {11, 20}, {12, 19}, {13, 18}, {14, 17}, {15, 16} };
		fillItemsVec(items, arr, 10);
		passed = transportMax(cars, items, 30) == 94;
		break;
	case 12:
		cars += 17, 11, 10, 33, 23, 13, 24, 14, 15, 50;
		arr = new itemT[9]{ {24, 8}, {23, 9}, {22, 10}, {21, 11}, {20, 12}, {19, 13}, {18, 14}, {17, 15}, {16, 4} };
		fillItemsVec(items, arr, 9);
		passed = transportMax(cars, items, 20) == 15;
		break;
	case 13:
		cars += 11, 17, 30, 23, 13, 33, 3, 14, 41, 15, 50;
		arr = new itemT[10]{ {30, 30}, {1, 1}, {6, 6}, {11, 11}, {16, 16}, {21, 21}, {26, 26}, {3, 3}, {8, 8}, {13, 13} };
		fillItemsVec(items, arr, 10);
		passed = transportMax(cars, items, 24) == 24;
		break;
	case 14:
		cars += 10, 35, 31, 23, 24, 14, 45, 52, 51;
		arr = new itemT[10]{ {12, 28}, {14, 30}, {1, 5}, {3, 9}, {5, 15}, {7, 21}, {9, 27}, {11, 29}, {13, 2}, {15, 7} };
		fillItemsVec(items, arr, 10);
		passed = transportMax(cars, items, 20) == 62;
		break;
	case 15:
		cars += 21, 23, 30, 13, 37, 40, 41, 15, 25, 35;
		arr = new itemT[9]{ {16, 2}, {21, 7}, {26, 12}, {2, 17}, {7, 22}, {12, 27}, {17, 3}, {22, 8}, {27, 13} };
		fillItemsVec(items, arr, 9);
		passed = transportMax(cars, items, 23) == 66;
		break;
	}
	return passed;
}


Set<string> stringToSet(string vitamins) {
	Set<string> s;
	for (int i = 0; i < vitamins.length(); i++) {
		s += vitamins.substr(i, 1);
	}
	return s;
}

// vitamins 	- set of vitamins
// res 			- indexes of fruits
// fruits 		- vitamins in fruits
// checks if fruits from res vector cover all vitamins
bool coversAllVit(Set<string>& vitamins, Vector<int>& res, Vector< Set<string> >& fruits) {
	Set<string> tmp;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] < 0 || res[i] >= fruits.size()) {
			cout << "returned index " << res[i] << "out of range,";
			cout << " fruits vector size is " << fruits.size() << endl;
			return false;
		}
		tmp += fruits[res[i]];
	}

	bool result = vitamins.isSubsetOf(tmp);
	if (!result) {
		cout << "given fruits do not cover all vitamins!" << endl;
	}
	return result;
}

bool runVitaminsSingleTest(int testNum) {
	Set<string> vitamins;
	Vector<int> res;
	Vector< Set<string> > fruits;
	int answerSize;
	bool passed;
	switch (testNum) {
	case 1:
		answerSize = 1; // answer
		vitamins += "A", "B";
		fruits.push_back(stringToSet("A"));
		fruits.push_back(stringToSet("AB"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 2:
		answerSize = 2; // answer
		vitamins += "A", "B", "C";
		fruits.push_back(stringToSet("AB"));
		fruits.push_back(stringToSet("C"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 3:
		answerSize = 2; // answer
		vitamins += "A", "B", "C", "D";
		fruits.push_back(stringToSet("AD"));
		fruits.push_back(stringToSet("ABC"));
		fruits.push_back(stringToSet("BC"));


		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 4:
		answerSize = 3; // answer
		vitamins += "A", "B", "C", "D";
		fruits.push_back(stringToSet("AC"));
		fruits.push_back(stringToSet("BC"));
		fruits.push_back(stringToSet("D"));
		fruits.push_back(stringToSet("CD"));


		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 5:
		answerSize = 2; // answer
		vitamins += "A", "B", "C", "D", "E";
		fruits.push_back(stringToSet("CD"));
		fruits.push_back(stringToSet("ABD"));
		fruits.push_back(stringToSet("AB"));
		fruits.push_back(stringToSet("AD"));
		fruits.push_back(stringToSet("BCE"));


		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 6:
		answerSize = 3; // answer
		vitamins += "A", "B", "C", "D", "E", "F";
		fruits.push_back(stringToSet("BC"));
		fruits.push_back(stringToSet("ADE"));
		fruits.push_back(stringToSet("CE"));
		fruits.push_back(stringToSet("BD"));
		fruits.push_back(stringToSet("C"));
		fruits.push_back(stringToSet("AF"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 7:
		answerSize = 4; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G";
		fruits.push_back(stringToSet("AE"));
		fruits.push_back(stringToSet("E"));
		fruits.push_back(stringToSet("C"));
		fruits.push_back(stringToSet("BDF"));
		fruits.push_back(stringToSet("AF"));
		fruits.push_back(stringToSet("AC"));
		fruits.push_back(stringToSet("G"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 8:
		answerSize = 3; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H";
		fruits.push_back(stringToSet("CEFGH"));
		fruits.push_back(stringToSet("ADH"));
		fruits.push_back(stringToSet("BDFGH"));
		fruits.push_back(stringToSet("EH"));
		fruits.push_back(stringToSet("AG"));
		fruits.push_back(stringToSet("ADGH"));
		fruits.push_back(stringToSet("DH"));
		fruits.push_back(stringToSet("BFGH"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 9:
		answerSize = 2; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I";
		fruits.push_back(stringToSet("BEI"));
		fruits.push_back(stringToSet("ACEG"));
		fruits.push_back(stringToSet("ABGH"));
		fruits.push_back(stringToSet("DG"));
		fruits.push_back(stringToSet("BEH"));
		fruits.push_back(stringToSet("BDFHI"));
		fruits.push_back(stringToSet("BGH"));
		fruits.push_back(stringToSet("DFH"));
		fruits.push_back(stringToSet("DF"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;

	case 10:
		answerSize = 2; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J";
		fruits.push_back(stringToSet("AGH"));
		fruits.push_back(stringToSet("CFI"));
		fruits.push_back(stringToSet("CG"));
		fruits.push_back(stringToSet("EF"));
		fruits.push_back(stringToSet("ADGH"));
		fruits.push_back(stringToSet("ABEH"));
		fruits.push_back(stringToSet("AGH"));
		fruits.push_back(stringToSet("I"));
		fruits.push_back(stringToSet("ABCFGJI"));
		fruits.push_back(stringToSet("DEJH"));


		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	case 11:
		answerSize = 4; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O";
		fruits.push_back(stringToSet("CFHN"));
		fruits.push_back(stringToSet("ADEGHKLM"));
		fruits.push_back(stringToSet("BEHIKMN"));
		fruits.push_back(stringToSet("CDFGKMO"));
		fruits.push_back(stringToSet("ABCFHL"));
		fruits.push_back(stringToSet("BCEFGN"));
		fruits.push_back(stringToSet("DJLMN"));
		fruits.push_back(stringToSet("AFHJ"));
		fruits.push_back(stringToSet("BDFILMNO"));
		fruits.push_back(stringToSet("CGIKMNO"));
		fruits.push_back(stringToSet("EHIO"));
		fruits.push_back(stringToSet("BEHIM"));
		fruits.push_back(stringToSet("BDHILO"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;

	case 12:
		answerSize = 6; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O";
		fruits.push_back(stringToSet("CEH"));
		fruits.push_back(stringToSet("CFGLO"));
		fruits.push_back(stringToSet("ADHIR"));
		fruits.push_back(stringToSet("ABT"));
		fruits.push_back(stringToSet("CKO"));
		fruits.push_back(stringToSet("FILMOR"));
		fruits.push_back(stringToSet("BDFHIOR"));
		fruits.push_back(stringToSet("JMR"));
		fruits.push_back(stringToSet("BDILOS"));
		fruits.push_back(stringToSet("IJOP"));
		fruits.push_back(stringToSet("DKN"));
		fruits.push_back(stringToSet("CF"));
		fruits.push_back(stringToSet("ABFR"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;

	case 13:
		answerSize = 7; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O";
		fruits.push_back(stringToSet("EH"));
		fruits.push_back(stringToSet("FGLO"));
		fruits.push_back(stringToSet("DIR"));
		fruits.push_back(stringToSet("ABT"));
		fruits.push_back(stringToSet("KO"));
		fruits.push_back(stringToSet("MOR"));
		fruits.push_back(stringToSet("R"));
		fruits.push_back(stringToSet("JMR"));
		fruits.push_back(stringToSet("OS"));
		fruits.push_back(stringToSet("IJOP"));
		fruits.push_back(stringToSet("KN"));
		fruits.push_back(stringToSet("CF"));
		fruits.push_back(stringToSet("AFR"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;

	case 14:
		answerSize = 13; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M";
		fruits.push_back(stringToSet("A"));
		fruits.push_back(stringToSet("B"));
		fruits.push_back(stringToSet("C"));
		fruits.push_back(stringToSet("D"));
		fruits.push_back(stringToSet("E"));
		fruits.push_back(stringToSet("F"));
		fruits.push_back(stringToSet("G"));
		fruits.push_back(stringToSet("H"));
		fruits.push_back(stringToSet("I"));
		fruits.push_back(stringToSet("J"));
		fruits.push_back(stringToSet("K"));
		fruits.push_back(stringToSet("L"));
		fruits.push_back(stringToSet("M"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;

	case 15:
		answerSize = 8; // answer
		vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O";
		fruits.push_back(stringToSet("CEH"));
		fruits.push_back(stringToSet("CG"));
		fruits.push_back(stringToSet("AIR"));
		fruits.push_back(stringToSet("BT"));
		fruits.push_back(stringToSet("CKO"));
		fruits.push_back(stringToSet("OR"));
		fruits.push_back(stringToSet("TOR"));
		fruits.push_back(stringToSet("JMR"));
		fruits.push_back(stringToSet("LOS"));
		fruits.push_back(stringToSet("IOP"));
		fruits.push_back(stringToSet("DKN"));
		fruits.push_back(stringToSet("CF"));
		fruits.push_back(stringToSet("FR"));

		res = fruitList(vitamins, fruits);
		passed = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
		break;
	}
	return passed;
}

void runTransportAllTests() {
	cout << "### Run Transport tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum <= TransportTestsNum; testNum++) {
		bool passed = runTransportSingleTest(testNum);
		printTestResults(passed, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

void runVitaminsAllTests() {
	cout << "### Run Vitamins tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum <= VitaminsTestsNum; testNum++) {
		bool passed = runVitaminsSingleTest(testNum);
		printTestResults(passed, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
	runTransportAllTests();
	runVitaminsAllTests();
	cout << "end" << endl;
	return 0;
}
