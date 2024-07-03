#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "vector.h"
#include "my_string.h"
#include <time.h>
#include "lexicon.h"
#include "longest_path.h"


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

bool equalsMyString(string str, MyString *s) {
    if (str.length() != s->length()) {
        return false;
    }

    for (int i = 0; i < s->length(); i++) {
        if (str[i] != s->get(i)) {
            return false;
        }
    }
    return true;
}

MyString *initMyString(string str) {
    MyString *s = new MyString;
    for (int i = 0; i < str.length(); i++) {
        s->insert(i, str[i]);
    }
    return s;
}

void runStringTests() {
    cout << "### Run String tests ###" << endl;
    int testNum = 0;
    int passedCounter = 0;
    MyString *s;
    bool passed;
    //#1
    passed = false;
    s = new MyString;
    printTestResults(s->length() == 0, testNum, passedCounter);
    //#2
    s = new MyString;
    s->insert(0, 'a');
    passed = s->length() == 1 && s->get(0) == 'a';
    printTestResults(passed, testNum, passedCounter);
    //#3
    s = new MyString;
    s->insert(0, 'b');
    s->insert(0, 'a');
    s->insert(2, 'c');
    passed = s->length() == 3 && equalsMyString("abc", s);
    printTestResults(passed, testNum, passedCounter);
    //#4
    s = new MyString;
    s->insert(0, 'b');
    s->insert(0, 'a');
    s->insert(2, 'c');
    s->insert(1, 'c');
    s->insert(2, 'd');
    passed = s->length() == 5 && equalsMyString("acdbc", s);
    printTestResults(passed, testNum, passedCounter);
    //#5
    s = new MyString;
    s->insert(0, 'b');
    s->insert(0, 'a');
    s->insert(2, 'c');
    s->insert(1, 'c');
    s->insert(2, 'd');
    s->set(0, 't');
    passed = s->length() == 5 && equalsMyString("tcdbc", s);
    printTestResults(passed, testNum, passedCounter);
    //#6
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'c');
    s->insert(1, 'c');
    s->insert(2, 'd');
    s->set(0, 't');
    s->set(s->length() - 1, 't');
    passed = s->length() == 4 && equalsMyString("tcdt", s);
    printTestResults(passed, testNum, passedCounter);
    //#7
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'c');
    s->insert(1, 'c');
    s->insert(2, 'd');
    s->set(0, 't');
    s->insert(0, 'a');
    s->set(s->length() - 1, 't');
    s->insert(s->length(), 'k');
    passed = s->length() == 6 && equalsMyString("atcdtk", s);
    printTestResults(passed, testNum, passedCounter);
    //#8
    s = new MyString;
    s->insert(0, 'a');
    s = s->substr(0, 1);
    passed = equalsMyString("a", s);
    printTestResults(passed, testNum, passedCounter);
    //#9
    s = new MyString;
    s->insert(0, 'a');
    s = s->substr(0, 0);
    passed = equalsMyString("", s);
    printTestResults(passed, testNum, passedCounter);
    //#10
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'b');
    s->insert(2, 'c');
    s->insert(3, 'd');
    s->insert(4, 'e');
    s = s->substr(3, 2);
    passed = equalsMyString("de", s);
    printTestResults(passed, testNum, passedCounter);
    //#11
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'b');
    s->insert(2, 'c');
    s->insert(3, 'd');
    s->insert(4, 'e');
    s = s->substr(0, s->length());
    passed = equalsMyString("abcde", s);
    printTestResults(passed, testNum, passedCounter);
    //#12
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'b');
    s->insert(2, 'c');
    s->insert(3, 'd');
    s->insert(4, 'e');
    s = s->substr(0, s->length());
    passed = equalsMyString("abcde", s);
    printTestResults(passed, testNum, passedCounter);
    //#13
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'b');
    s->insert(2, 'c');
    s->insert(3, 'd');
    s->insert(4, 'e');
    passed = s->find(initMyString("abcdef")) == -1;
    printTestResults(passed, testNum, passedCounter);
    //#14
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'b');
    s->insert(2, 'c');
    s->insert(3, 'd');
    s->insert(4, 'e');
    passed = s->find(initMyString("abcde")) == 0;
    printTestResults(passed, testNum, passedCounter);
    //#15
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'b');
    s->insert(2, 'c');
    s->insert(3, 'd');
    s->insert(4, 'e');
    passed = s->find(initMyString("de")) == 3;
    printTestResults(passed, testNum, passedCounter);
    //#16
    s = new MyString;
    s->insert(0, 'a');
    s->insert(1, 'b');
    s->insert(2, 'c');
    s->insert(3, 'd');
    s->insert(4, 'e');
    passed = s->find(initMyString("abcc")) == -1;
    printTestResults(passed, testNum, passedCounter);


    cout << "###### passed " << passedCounter << " tests ######" << endl;
}

void insertIntoTree(Node * &root, int v) {
	if (root == NULL) {
		root = new Node;
		root->left = NULL;
		root->right = NULL;
		root->v = v;
		return;
	}
	if (root->v < v) {
		insertIntoTree(root->right, v);
	} else {
		insertIntoTree(root->left, v);
	}
}

Node* buildTree(Vector<int> &v) {
	Node * root = NULL;
	for (int i=0; i<v.size(); i++) {
		insertIntoTree(root, v[i]);
	}
	return root;
}

void runLongestPathTests() {
	cout << "### Run Longest Path tests ###" << endl;
	int testNum = 0;
	int passedCounter = 0;
	int res;
	Node * root = NULL;
	Vector<int> v;
	//#1
	res = getLongestPath(root);
	printTestResults(res == 0, testNum, passedCounter);
	//#2
	v.clear();
	v += 1;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 1, testNum, passedCounter);
	//#3
	v.clear();
	v += 1, 2, 3, 4, 5;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 5, testNum, passedCounter);
	//#4
	v.clear();
	v += 10, 1, 2, 9, 14, 15;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 6, testNum, passedCounter);
	//#5
	v.clear();
	v += 10, 5, 18, 16, 15, 12, 20, 19;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 6, testNum, passedCounter);
	//#6
	v.clear();
	v += 20, 5, 1, 10, 30, 25, 40, 36, 35, 34, 33, 41, 42, 43;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 9, testNum, passedCounter);
	//#7
	v.clear();
	v += 30, 50, 1, 25, 27, 29, 4, 14, 15, 16, 17, 18, 19, 20, 13, 12, 11, 10, 9, 8;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 13, testNum, passedCounter);
	//#8
	v.clear();
	v += 30, 50, 1, 25, 27, 29, 4, 14, 15, 16, 17, 18, 19, 20, 10, 12, 11, 9, 8, 7, 6, 5;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 13, testNum, passedCounter);
	//#9
	v.clear();
	v += 30, 50, 1, 25, 27, 29, 4, 14, 15, 16, 17, 18, 19, 20, 10, 12, 11, 9, 8, 7, 6, 5, 55, 60, 57;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 15, testNum, passedCounter);
	//#10
	v.clear();
	v += 34, 50, 1, 25, 27, 29, 4, 14, 15, 16, 17, 18, 19, 20, 10, 12, 11, 9, 8, 7, 6, 5, 30, 31, 32, 33;
	root = buildTree(v);
	res = getLongestPath(root);
	printTestResults(res == 15, testNum, passedCounter);

	cout << "###### passed " << passedCounter << " tests ######" << endl;
}

int main() {
	runStringTests();
	runLongestPathTests();

    return 0;
}