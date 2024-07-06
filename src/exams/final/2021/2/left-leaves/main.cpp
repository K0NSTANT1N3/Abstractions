#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "SumOfLeftLeaves.h"

// Helper function to parse a line into integers
std::vector<int> parseLineToInts(const std::string& line) {
    std::vector<int> result;
    std::istringstream iss(line);
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
}
TreeNode* constructTreeFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return nullptr;
    }

//    std::cout << "Reading file: " << filePath << std::endl;

    // Read the first line to get number of nodes and expected answer
    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Failed to read metadata from file: " << filePath << std::endl;
        file.close();
        return nullptr;
    }

    std::vector<int> metadata = parseLineToInts(line);
    if (metadata.size() < 2) {
        std::cerr << "Invalid metadata format in file: " << filePath << std::endl;
        file.close();
        return nullptr;
    }

    int numNodes = metadata[0];  // Number of nodes
    int expectedAnswer = metadata[1];  // Expected answer

    // Read the nodes
    std::vector<TreeNode*> nodes(numNodes + 1, nullptr); // +1 because nodes are 1-indexed
    for (int i = 1; i <= numNodes; ++i) {
        if (!std::getline(file, line)) {
            std::cerr << "Failed to read node " << i << " from file: " << filePath << std::endl;
            file.close();
            // Clean up allocated memory for nodes
            for (TreeNode* node : nodes) {
                delete node;
            }
            return nullptr;
        }
        int nodeValue;
        std::istringstream iss(line);
        if (!(iss >> nodeValue)) {
            std::cerr << "Failed to parse node value from line " << i + 1 << " in file: " << filePath << std::endl;
            file.close();
            // Clean up allocated memory for nodes
            for (TreeNode* node : nodes) {
                delete node;
            }
            return nullptr;
        }
        nodes[i] = new TreeNode();
        nodes[i]->v = nodeValue;
    }

    // Read and ignore the tree drawing lines
    while (std::getline(file, line)) {
        if (line.find("Answ:") != std::string::npos) {
            break;
        }
    }

    // Read the expected answer
    int actualAnswer;
    if (line.size() > 6) {
        std::istringstream iss(line.substr(6));  // Skip "Answ: "
        iss >> actualAnswer;
    } else {
        std::cerr << "Invalid answer format in file: " << filePath << std::endl;
        file.close();
        // Clean up allocated memory for nodes
        for (TreeNode* node : nodes) {
            delete node;
        }
        return nullptr;
    }

    // Check if the expected and actual answers match
    if (expectedAnswer != actualAnswer) {
        std::cerr << "Expected answer (" << expectedAnswer << ") does not match actual answer (" << actualAnswer << ") in file: " << filePath << std::endl;
        // Clean up allocated memory for nodes
        for (TreeNode* node : nodes) {
            delete node;
        }
        return nullptr;
    }

    // Close the file
    file.close();

    // Build the tree structure using nodes
    TreeNode* root = nodes[1]; // Assuming root node is always at index 1
    for (int i = 1; i <= numNodes; ++i) {
        if (2 * i <= numNodes) { // left child exists
            nodes[i]->left = nodes[2 * i];
        }
        if (2 * i + 1 <= numNodes) { // right child exists
            nodes[i]->right = nodes[2 * i + 1];
        }
    }

    return root;
}

// Function to print the tree (in-order traversal)
// Function to print the tree (in-order traversal)
void printTree(TreeNode* root, int indent = 0) {
    if (root == nullptr) {
        return;
    }

    // Print right subtree
    printTree(root->left, indent + 0);

    // Print current node with indentation
    for (int i = 0; i < indent; ++i) {
        std::cout << " ";
    }
    std::cout << root->v << std::endl;

    // Print left subtree
    printTree(root->right, indent + 0);
}

int main() {
    // List of file paths for all 13 test cases
    std::vector<std::string> filepaths = {
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test1.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test2.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test3.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test4.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test5.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test6.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test7.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test8.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test9.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test10.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test11.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test12.txt",
            "/home/konstantine/CLionProjects/Abstractions/src/exams/final/2021/2/left-leaves/tests/test13.txt"
    };

    // Process each file
    int i = 0;
    for (const auto& filepath : filepaths) {
        i++;
        TreeNode* root = constructTreeFromFile(filepath);
        if (root) {
            // Print the tree
            std::cout << "Tree from file: " << filepath << std::endl;

            if(i == 3){
                printTree(root);
                int sm = sumOfLeftLeaves(root);
                std::cout << "Sum of left leaves: " << sm << std::endl;
            }

            std::cout << std::endl;

            // Clean up allocated memory for nodes (assuming no reuse of nodes across files)
            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
                delete current;
            }
        }
    }

    return 0;
}
