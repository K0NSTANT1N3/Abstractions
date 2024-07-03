#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "random.h"
#include "console.h"
#include "vector.h"
#include <time.h>
#include "lexicon.h"
#include "Ermalo.h"
#include "translate.h"


using namespace std;

void printTestResults(bool passed, int &testNum, int &passedCounter) {
    testNum++;
    if (passed) {
        cout << "test " << testNum << " passed" << endl;
        passedCounter++;
    } else {
        cout << "test " << testNum << " failed" << endl;
    }
}

void testTranslate() {
    translate *tra = new translate;

    cout << "### Testing Translate ###" << endl;
    int testNum = 0;
    int passed = 0;
    int res;
    Vector<int> v;
    //# Test 1
    v += 1, 2, 3, 1;
    res = tra->calcTranslTime(v);
    printTestResults(res == 3, testNum, passed);
    v.clear();

    //# Test 2
    v += 7, 3, 4, 6;
    res = tra->calcTranslTime(v);
    printTestResults(res == 7, testNum, passed);
    v.clear();

    //# Test 3
    v += 10, 11, 12;
    res = tra->calcTranslTime(v);
    printTestResults(res == 12, testNum, passed);
    v.clear();

    //# Test 4
    v += 7, 4, 5, 6, 10, 3, 8, 2;
    res = tra->calcTranslTime(v);
    printTestResults(res == 15, testNum, passed);
    v.clear();

    //# Test 5
    v += 22, 10, 11, 19, 4;
    res = tra->calcTranslTime(v);

    printTestResults(res == 23, testNum, passed);
    v.clear();

    //# Test 6
    v += 82, 28, 62, 92, 96, 43;
    res = tra->calcTranslTime(v);

    printTestResults(res == 144, testNum, passed);
    v.clear();

    //# Test 7
    v += 28, 37, 92, 5, 3, 54, 93;
    res = tra->calcTranslTime(v);

    printTestResults(res == 119, testNum, passed);
    v.clear();

    //# Test 8
    v += 83, 22, 17, 19, 96, 48, 27, 72;
    res = tra->calcTranslTime(v);

    printTestResults(res == 131, testNum, passed);
    v.clear();

    //# Test 9
    v += 39, 70, 13, 68, 100, 36, 95, 4, 12;
    res = tra->calcTranslTime(v);

    printTestResults(res == 148, testNum, passed);
    v.clear();

    //# Test 10
    v += 23, 34, 74, 65, 42, 12, 54, 69, 48, 45;
    res = tra->calcTranslTime(v);

    printTestResults(res == 156, testNum, passed);
    v.clear();

    //# Test 11
    v += 63, 58, 38, 60, 24, 42, 30, 79, 17, 36, 91;
    res = tra->calcTranslTime(v);

    printTestResults(res == 180, testNum, passed);
    v.clear();

    //# Test 12
    v += 43, 89, 7, 41, 43, 65, 49, 47, 6, 91, 30, 71;
    res = tra->calcTranslTime(v);

    printTestResults(res == 195, testNum, passed);
    v.clear();
    cout << "passed: " << passed << endl;
}

string pass;

bool isCorrectPass(string s) {
    return s == pass;
}

Map<char, int> stringToMap(string symbols) {
    Map<char, int> m;
    for (int i = 0; i < symbols.length(); i++) {
        m[symbols[i]]++;
    }
    return m;
}

//void testErmalo() {
//	cout << "### Testing Ermalo ###" << endl;
//	int testNum = 0;
//	int passed = 0;
//	string s;
//	Map<char, int> m;
//	//# Test 1
//	pass = "ababcc";
//	m = stringToMap("aabbcc");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 2
//	pass = "abcd";
//	m = stringToMap("abcd");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 3
//	pass = "aabcd";
//	m = stringToMap("abcda");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 4
//	pass = "aaaa";
//	m = stringToMap("aaaa");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 5
//	pass = "abcdefgh";
//	m = stringToMap("hgfabcde");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 6
//	pass = "ababaccc";
//	m = stringToMap("aaabbccc");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 7
//	pass = "a";
//	m = stringToMap("a");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 8
//	pass = "qwertyyy";
//	m = stringToMap("yqywerty");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 9
//	pass = "anbani";
//	m = stringToMap("inabna");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//	//# Test 10
//	pass = "madagaska";
//	m = stringToMap("madagaska");
//	s = recallPass(m, isCorrectPass);
//	printTestResults(s == pass, testNum, passed);
//
//	cout << "passed: " << passed << endl;
//}


int main() {
    setRandomSeed(0);
    testTranslate();
//	testErmalo();
    return 0;
}