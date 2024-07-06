#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "vector.h"
#include "sec_min_spanning_tree.h"  // Assuming this header defines Vector and Arc*

using namespace std;

// Function to read graph data from a file
bool readGraphFromFile(const string& fileName, Vector<Arc*>& graph, int& n, int& expectedAnswer) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return false;
    }

    file >> n;  // Number of nodes
    int m;      // Number of edges
    file >> m >> expectedAnswer;  // Number of edges and expected answer

    graph.clear();
    for (int i = 0; i < m; ++i) {
        int from, to, dist;
        file >> from >> to >> dist;
        Arc* arc = new Arc(from, to, dist);  // Assuming Arc has constructor Arc(int from, int to, int dist)
        graph.add(arc);
    }

    file.close();
    return true;
}

// Function to free memory allocated to Arc objects
void freeGraph(Vector<Arc*>& graph) {
    for (Arc* arc : graph) {
        delete arc;
    }
    graph.clear();
}

int main() {
    const int NUM_TESTS = 50;  // Number of test cases
    Vector<Arc*> graph;
    int n, expectedAnswer;
    int passedCounter = 0;

    string basePath = "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2018/version1/session2/mst_tests/";  // Adjust this relative path as necessary

    for (int i = 1; i <= NUM_TESTS; ++i) {
        string fileName = basePath + "test" + to_string(i) + ".txt";


        // Print the full path to verify
        char resolvedPath[PATH_MAX];
        if (realpath(fileName.c_str(), resolvedPath) != NULL) {
        } else {
            cerr << "Failed to resolve path for file: " << fileName << endl;
        }

        if (!readGraphFromFile(fileName, graph, n, expectedAnswer)) {
            cerr << "Failed to read test file: " << fileName << endl;
            continue;
        }

        int result = findSecondMinSpanningTree(graph, n);
        cout << "Test " << i << ": ";
        if (result == expectedAnswer) {
            cout << "Passed" << endl;
            passedCounter++;
        } else {
            cout << "Failed. Expected: " << expectedAnswer << ", Got: " << result << endl;
        }

        // Free memory allocated to Arc objects in the graph
        freeGraph(graph);
    }

    cout << "Passed " << passedCounter << " out of " << NUM_TESTS << " tests." << endl;

    return 0;
}
