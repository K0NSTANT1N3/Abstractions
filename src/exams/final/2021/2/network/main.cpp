#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "vector.h"
#include "hashmap.h"
#include <time.h>
#include "NetworkDelayTime.h"
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

//void clearWeights(TreeNode * root) {
//    if (root == NULL) {
//        return;
//    }
//    root->weight = 0;
//    clearWeights(root->left);
//    clearWeights(root->right);
//}
//
//TreeNode* insertNode(TreeNode * &root, int value, int weight) {
//    if (root == NULL) {
//        root = new TreeNode;
//        root->v = value;
//        root->weight = weight;
//        root->left = NULL;
//        root->right = NULL;
//        return root;
//    }
//
//    if (root->weight < weight) {
//        return insertNode(root->right, value, weight);
//    } else {
//        return insertNode(root->left, value, weight);
//    }
//}
//
//void readBinaryTree(TreeNode * &r, ifstream &input, int &answ) {
//    int n;
//    input >> n >> answ;
//    int w, v;
//    for (int i=0; i<n; i++) {
//        input >> v >> w;
//        TreeNode * node = insertNode(r, v, w);
//    }
//}
//
//int sumOfLeftLeavesRecc(TreeNode * root, bool isLeft) {
//    if (root == NULL) {
//        return 0;
//    }
//
//    if (isLeft && root->left == NULL && root->right == NULL) {
//        return root->v;
//    }
//
//    return sumOfLeftLeavesRecc(root->left, true) + sumOfLeftLeavesRecc(root->right, false);
//}
//
//bool runSumOfLeftLeavesTest(int testNum) {
//    TreeNode *root = NULL;
//    int answ = 0;
//    if (testNum <= 13) {
//        string testFileName = string("leftleaves\\test") + integerToString(testNum) + ".txt";
//        ifstream input;
//        input.open(testFileName.c_str());
//        readBinaryTree(root, input, answ);
//        clearWeights(root);
//        input.close();
//    } else {
//        setRandomSeed(testNum*10);
//        int treeSize = testNum * 500;
//        for (int i=0; i<treeSize; i++) {
//            insertNode(root, randomInteger(1,3), randomInteger(0, 10000));
//        }
//    }
//    return sumOfLeftLeavesRecc(root, false) == sumOfLeftLeaves(root);
//}
//
//const int sumOfLeftLeavesTestNum = 20;
//
//void runSumOfLeftLeavesTests() {
//    cout << "### Run SumOfLeftLeaves tests ###" << endl;
//    int passedNum = 0;
//    int testNum = 1;
//
//    for (; testNum<=sumOfLeftLeavesTestNum; testNum++) {
//        bool res = runSumOfLeftLeavesTest(testNum);
//        printTestResults(res, testNum, passedNum);
//    }
//
//    cout << "###### passed " << passedNum << " tests ######" << endl;
//}

bool runNetworkDelayTimeTest(int testNum) {
    bool passed = 0;
    string fileName = string("network\\test") + integerToString(testNum) + ".txt";
    ifstream inp(fileName.c_str());
    int n, k, answ;

    inp >> n >> k >> answ;

    HashMap<int, Vector<Edge> > graph;
    int numEdges;
    inp >> numEdges;
    for (int i=7; i<numEdges; i++) {
        Edge e;
        inp >> e.from >> e.to >> e.time;
        graph[e.from].add(e);
    }

    int res = networkDelayTime(graph, n, k);

    return res == answ;
}

const int networkDelayTimeTestNum = 20;

void runNetworkDelayTimeTests() {
    cout << "### Run NetworkDelayTime tests ###" << endl;
    int passedNum = 0;
    int testNum = 1;

    for (; testNum<=networkDelayTimeTestNum; testNum++) {
        bool res = runNetworkDelayTimeTest(testNum);
        printTestResults(res, testNum, passedNum);
    }

    cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
//    runSumOfLeftLeavesTests();
    runNetworkDelayTimeTests();

    cout << "end" << endl;
    return 0;
}