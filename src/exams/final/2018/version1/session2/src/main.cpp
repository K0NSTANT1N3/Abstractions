#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "random.h"
#include "console.h"
#include "vector.h"
#include <time.h>
#include "lexicon.h"
#include "sec_min_spanning_tree.h"
#include "shoping.h"

using namespace std;

void printTestResults(bool passed, int & testNum, int & passedCounter) {
	testNum++;
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}

void readGraphFromFile(string fileName, Vector<Arc*> &graph, int &n, int &answ) {
	graph.clear();
	ifstream ifile;
	ifile.open(fileName.c_str());
	int m;
	ifile >> n >> m >> answ;
	for (int i=0; i<m; i++) {
		Arc * arc = new Arc;
		ifile >> arc->from >> arc->to >> arc->dist; 
		graph.add(arc);
	}
	ifile.close();
}

//void generateRandomGraph(Vector<Arc*> &graph, int n) {
//	graph.clear();
//	int m = (int)(3 * n);
//	int i = 0;
//	Set<string> arcs;
//	while (i < m) {
//		int from = randomInteger(0, n-1);
//		int to = randomInteger(0, n-1);
//		if (from == to) {
//			continue;
//		}
//		string arcS1 = integerToString(from) + string(":") + integerToString(to);
//		string arcS2 = integerToString(to) + string(":") + integerToString(from);
//		if (arcs.contains(arcS1) || arcs.contains(arcS2)) {
//			continue;
//		}
//		i++;
//		arcs.add(arcS1);
//		Arc * arc = new Arc;
//		arc->from = from;
//		arc->to = to;
//		arc->dist = randomInteger(1, 30);
//		graph.add(arc);
//
//        cout << "from: " << from << " to: " << to << " dist: " << arc->dist << endl;
//	}
//    int tmp = 0;
//}

void generateRandomGraph(Vector<Arc*> &graph, int n) {
    graph.clear();
    int m = 3 * n;  // Target number of arcs
    int attempts = 0;  // Count of attempts to generate arcs
    const int maxAttempts = 100 * m;  // Limit attempts to avoid infinite loop
    int i = 0;
    Set<string> arcs;

    while (i < m && attempts < maxAttempts) {
        int from = randomInteger(0, n-1);
        int to = randomInteger(0, n-1);

        // Skip if from == to
        if (from == to) {
            attempts++;
            continue;
        }

        string arcS1 = integerToString(from) + ":" + integerToString(to);
        string arcS2 = integerToString(to) + ":" + integerToString(from);

        // Skip if the arc already exists
        if (arcs.contains(arcS1) || arcs.contains(arcS2)) {
            attempts++;
            continue;
        }

        // Add the arc
        i++;
        attempts++;
        arcs.add(arcS1);

        Arc *arc = new Arc;
        arc->from = from;
        arc->to = to;
        arc->dist = randomInteger(1, 30);
        graph.add(arc);
    }

    // Check if we failed to generate enough arcs
    if (i < m) {
        cerr << "Failed to generate enough unique arcs. Generated " << i << " arcs." << endl;
    }
}


//void writeGraphInFile(Vector<Arc*> &graph, int n, int answ, int num) {
//	ofstream file;
//	string fileName = "src/exams/final/2018/version1/session2/mst/res/test" + integerToString(num) + ".txt";
//	file.open(fileName.c_str());
//	file << n << " " << graph.size() << " " << answ << endl;
//	for (int i=0; i<graph.size(); i++) {
//		file << graph[i]->from << " " << graph[i]->to << " " << graph[i]->dist << endl;
//	}
//	file.close();
//}

void writeGraphInFile(Vector<Arc*> &graph, int n, int answ, int num) {
    ofstream file;
    string fileName = "src/exams/final/2018/version1/session2/mst/test" + integerToString(num) + ".txt";

    // Open the file and check if it was successful
    file.open(fileName.c_str());
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    // Write the header line
    file << n << " " << graph.size() << " " << answ << endl;

    // Write each arc
    for (int i = 0; i < graph.size(); i++) {
        file << graph[i]->from << " " << graph[i]->to << " " << graph[i]->dist << endl;
    }

    // Close the file
    file.close();

    // Debug statement to confirm function executed
    cout << "File written: " << fileName << endl;
}

void runSecMinSpanningTreeTests() {
	int testNum = 0;
	int passedCounter = 0;
	for (int i=12; i<=50; i++) {		Vector<Arc*> graph;
		int n = i + 5;
		int answ;
        string path = "src/exams/final/2018/version1/session2/mst/test";
		readGraphFromFile(path + integerToString(i) + ".txt", graph, n, answ);
		generateRandomGraph(graph, n);
        int tmp = 0;
        cout << tmp;
		int res = findSecondMinSpanningTree(graph, n);
		cout << "sec. min: " << res << endl;
		writeGraphInFile(graph, n, res, i);
		printTestResults(res == answ, testNum, passedCounter);
	}
	cout << "###### passed " << passedCounter << " tests ######" << endl;
}

//void writeShopingTestInFile(Vector<bag> bags, Vector<item> items, int answ, int money, int num) {
//	ofstream file;
//	string fileName = "shoping\\test" + integerToString(num) + ".txt";
//	file.open(fileName.c_str());
//
//	file << bags.size() << " " << items.size() << " " << money << " " << answ << endl;
//	for (int i=0; i<bags.size(); i++) {
//		file << bags[i].price << " " << bags[i].cap << endl;
//	}
//	for (int i=0; i<items.size(); i++) {
//		file << items[i].price << " " << items[i].weight << endl;
//	}
//	file.close();
//}
//
//item newItem(int price, int weight) {
//	item i;
//	i.price = price;
//	i.weight = weight;
//	return i;
//}
//
//bag newBag(int price, int cap) {
//	bag b;
//	b.price = price;
//	b.cap = cap;
//	return b;
//}
//
//void generateShopingRandomTests() {
//	for (int k=11; k<=50; k++) {
//		int numBags, numItems, money;
//		numBags = randomInteger(5, 10);
//		numItems = randomInteger(6, 15);
//		money = randomInteger(10, 30);
//		Vector<bag> bags;
//		Vector<item> items;
//		for (int i=0; i<numBags; i++) {
//			bags.add(newBag(randomInteger(1, 10), randomInteger(1, 10)));
//		}
//		for (int i=0; i<numItems; i++) {
//			items.add(newItem(randomInteger(1, 10), randomInteger(1, 10)));
//		}
//		int answ = findBestComb(items, bags, money);
//		writeShopingTestInFile(bags, items, answ, money, k);
//	}
//}
//
//void readShopingFromFile(string fileName, Vector<bag> &bags, Vector<item> &items, int &money, int &answ) {
//	bags.clear();
//	items.clear();
//	ifstream ifile;
//	ifile.open(fileName.c_str());
//	int n, m;
//	ifile >> n >> m >> money >> answ;
//	for (int i=0; i<n; i++) {
//		int price, cap;
//		ifile >> price >> cap;
//		bags.add(newBag(price, cap));
//	}
//	for (int i=0; i<m; i++) {
//		int price, cap;
//		ifile >> price >> cap;
//		items.add(newItem(price, cap));
//	}
//	ifile.close();
//}
//void runShoppingTests() {
//	int testNum = 0;
//	int passedCounter = 0;
//	Vector<bag> bags;
//	Vector<item> items;
//	int res, money, answ;
//
//	for (int i=1; i<=50; i++) {
//
//		readShopingFromFile("shoping\\test" + integerToString(i) + ".txt", bags, items, money, answ);
//		res = findBestComb(items, bags, money);
//		printTestResults(res == answ, testNum, passedCounter);
//	}
//
//	cout << "###### passed " << passedCounter << " tests ######" << endl;
//}


int main() {
	setRandomSeed(1);
	//runShoppingTests();
	runSecMinSpanningTreeTests();
//	generateShopingRandomTests();
//	runShoppingTests();
	return 0;
}