#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "random.h"
#include "console.h"
#include <time.h>
#include "pathSum.h"
#include "prQueue.h"
#include "pqueue.h"
#include "vector.h"
#include <sys/types.h>
#include <sys/timeb.h>
#include <ctime>

using namespace std;

long long currTimeMs() {
	struct _timeb timebuffer;
	_ftime64_s( &timebuffer );
	time_t time;
	unsigned short millitm;
    time = timebuffer.time;
    millitm = timebuffer.millitm;

	long long timeInMs = time*1000 + millitm;
	return timeInMs;
}

void printTestResults(bool passed, int & testNum, int & passedCounter) {
	testNum++;
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}

void clearWeights(nodeT * root) {
	if (root == NULL) {
		return;
	}
	root->weight = 0;
	clearWeights(root->left);
	clearWeights(root->right);
}

nodeT* insertNode(nodeT * &root, int value, int weight) {
	if (root == NULL) {
		root = new nodeT;
		root->v = value;
		root->weight = weight;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (root->weight < weight) {
		return insertNode(root->right, value, weight);
	} else {
		return insertNode(root->left, value, weight);
	}
}


void generateRandomTree(nodeT * &r, int size) {
	r = NULL;
	for (int i=0; i<size; i++) {
		int v = randomInteger(0, 10000);
		int w = randomInteger(0, 1000000000);
		nodeT * node = insertNode(r, v, w);
	}
}

void readBinaryTree(nodeT * &r, ifstream &input, int &s, Set<nodeT*> &answers) {
	int n;
	input >> n >> s;
	int w, v;
	for (int i=0; i<n; i++) {
		input >> v >> w;
		nodeT * node = insertNode(r, v, w);
		if (w % 10 == 1) {
			answers.add(node);
		}
	}
}

void readTreeTest(nodeT * &root, int &s, Set<nodeT*> &answers, int testNum) {
	answers.clear();
	string testFileName = string("pathsum\\test") + integerToString(testNum) + ".txt";
	root = NULL;
	ifstream input;
	input.open(testFileName.c_str());
	readBinaryTree(root, input, s, answers);
	clearWeights(root);
	input.close();
}

void testPathSum() {
	cout << "### Testing Path Sum###" << endl;
	int testNum = 0;
	int passed = 0;
	nodeT * root;
	Set<nodeT *> answers, res;
	int s;
	for (int i=1; i<=10; i++) {
		answers.clear();
		res.clear();
		readTreeTest(root, s, answers, i);
		pathSum(root, s, res);
		bool isCorrect = res == answers;
		printTestResults(isCorrect, testNum, passed);
	}	
	cout << "passed: " << passed << endl;

	//Test O(n)
	int initialSize = 1000;
	int mult = 20;
	long long startTime, timeElapsed1, timeElapsed2;
	generateRandomTree(root, initialSize);
	res.clear();
	startTime = currTimeMs();
	pathSum(root, 500, res);
	timeElapsed1 = currTimeMs() - startTime + 2;
	generateRandomTree(root, mult*initialSize);
	res.clear();
	startTime = currTimeMs();
	pathSum(root, 500, res);
	timeElapsed2 = currTimeMs() - startTime;

	if (timeElapsed1 <= timeElapsed2 / (mult+5)) {
		cout << "#### NOT O(n)! ####" << endl;
	}
}

void createRandomQueue(int size, PrQueue &q1, PriorityQueue<int> &q2) {
	for (int i=0; i<size; i++) {
		int v = randomInteger(0, 1000);
		int pr = randomInteger(0, size*2);
		q1.enqueue(v, pr);
		q2.enqueue(v, pr);
	}
}

bool testEnqueueDequeuePeek(int size) {
	PrQueue q1;
	PriorityQueue<int> q2;

	createRandomQueue(size, q1, q2);
	//compare sizes
	if (q1.size() != q2.size()) {
		cout << "Error1: sizes not equal!!" << endl;
		return false;
	}
	//compare elements
	while (!q2.isEmpty()) {
		q1.peek();
		q1.peek();
		if (q1.peek() != q2.peek()) {
			cout << "Error2: peek values not equal! " << q1.peek() << "!=" << q2.peek() << endl;
			return false;
		}
		if (q1.dequeue() != q2.dequeue()) {
			cout << "Error3: dequeue values not equal!!" << endl;
			return false;
		}
	}
	for (int i=0; i<size; i++) {
		int v = randomInteger(0, 10000);
		int pr = randomInteger(0, size*2);
		q1.enqueue(v, pr);
		q2.enqueue(v, pr);
		q1.peek();
		q1.peek();
		if (q1.peek() != q2.peek()) {
			cout << "Error4: peek values not equal!!" << endl;
			return false;
		}
		if (q1.dequeue() != q2.dequeue()) {
			cout << "Error5: dequeue values not equal!!" << endl;
			return false;
		}		
	}
	if (q1.size() != 0) {
		cout << "Error6: size is not 0!!" << endl;
		return false;
	}
	
	return true;
}


bool testIterator(int size) {
	PrQueue q1;
	PriorityQueue<int> q2;
	createRandomQueue(size, q1, q2);
	Vector<int> v;
	while (!q2.isEmpty()) {
		v.add(q2.dequeue());
	}

	int k, pr;
	q1.resetIterator();
	for (int i=0; i<v.size(); i++) {
		if (!q1.hasNext()) {
			cout << "Error7: hasNext value must be true!!" << endl;
			return false;
		}
		q1.next(k, pr);
		if (v[i] != k) {
			cout << "Error8: next value is not equal!!" << endl;
			return false;
		}
	}
	if (q1.hasNext()) {
		cout << "Error9: hasNext value must be false!!" << endl;
		return false;
	}

	//iterator til half
	q1.resetIterator();
	for (int i=0; i<v.size()/2; i++) {
		if (!q1.hasNext()) {
			cout << "Error10: hasNext value must be true!!" << endl;
			return false;
		}
		q1.next(k, pr);
		if (v[i] != k) {
			cout << "Error11: next value is not equal!!" << endl;
			return false;
		}
	}
	
	//iterate one more time
	q1.resetIterator();
	for (int i=0; i<v.size(); i++) {
		if (!q1.hasNext()) {
			cout << "Error13: hasNext value must be true!!" << endl;
			return false;
		}
		q1.next(k, pr);
		if (v[i] != k) {
			cout << "Error14: next value is not equal!!" << endl;
			return false;
		}
	}
	if (q1.hasNext()) {
		cout << "Error15: hasNext value must be false!!" << endl;
		return false;
	}
	return true;
}

void testPrQueue() {
	cout << "### Testing Path Sum###" << endl;
	int testNum = 0;
	int passed = 0;
	//test enqueue, dequeue, peek, size
	for (int i=1; i<=12; i++) {
		bool isCorrect = testEnqueueDequeuePeek(i*10);
		printTestResults(isCorrect, testNum, passed);		
	}
	//test iterator
	for (int i=1; i<=8; i++) {
		bool isCorrect = testIterator(i*10);
		printTestResults(isCorrect, testNum, passed);		
	}
	
	//##### test O(1) ####v
	bool testResetIterator = false;
	bool testNext = false;
	bool testHasNext = false;
	bool testDequeue;
	int next, pr;
	PrQueue q1;
	PrQueue q2;
	for (int i=0; i<10; i++) {
		q1.enqueue(i, i);
	}
	for (int i=0; i<1000; i++) {
		q2.enqueue(i, i);
	}
	long long startTime;
	long long timeElapsed1, timeElapsed2;
	startTime = currTimeMs();
	q1.resetIterator();
	timeElapsed1 = currTimeMs() - startTime + 2;
	startTime = currTimeMs();
	q2.resetIterator();
	timeElapsed2 = currTimeMs() - startTime;
	testResetIterator = (timeElapsed1*2 >= timeElapsed2);
	//next
	startTime = currTimeMs();
	q1.next(next, pr);
	timeElapsed1 = currTimeMs() - startTime + 2;
	startTime = currTimeMs();
	q2.next(next, pr);
	timeElapsed2 = currTimeMs() - startTime;
	testNext = (timeElapsed1*2 >= timeElapsed2);
	// has next
	startTime = currTimeMs();
	q1.hasNext();
	timeElapsed1 = currTimeMs() - startTime + 2;
	startTime = currTimeMs();
	q2.hasNext();
	timeElapsed2 = currTimeMs() - startTime;
	testHasNext = (timeElapsed1*2 >= timeElapsed2);
	// has next
	startTime = currTimeMs();
	q1.dequeue();
	timeElapsed1 = currTimeMs() - startTime + 2;
	startTime = currTimeMs();
	q2.dequeue();
	timeElapsed2 = currTimeMs() - startTime;
	testDequeue = (timeElapsed1*2 >= timeElapsed2);

	if (!testResetIterator) {
		cout << "### resetIterator NOT O(1) ### " << endl;
	}
	if (!testNext) {
		cout << "### next NOT O(1) ### " << endl;
	}
	if (!testHasNext) {
		cout << "### hasNext NOT O(1) ### " << endl;
	}
	if (!testDequeue) {
		cout << "### dequeue NOT O(1) ### " << endl;
	}

	cout << "passed: " << passed << endl;
}

int main() {
	setRandomSeed(1);
	testPathSum();
	testPrQueue();
	return 0;
}