#include <iostream>
#include <cassert>
#include <climits>
#include "grid.h"
#include "vector.h"
#include "set.h"

void reverseVector(Vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n / 2; ++i) {
        int temp = vec[i];
        vec[i] = vec[n - 1 - i];
        vec[n - 1 - i] = temp;
    }
}

void minValueTravel(Grid<int> &costs, Vector<int> &cities, Set<int> &visited, Vector<int>& bestRoute, int &answer) {
    if (cities.size() == costs.numCols()) {
        int ans = 0;
        for (int i = 0; i < cities.size(); i++) {
            ans += costs[cities[i]][cities[(i + 1) % cities.size()]];
        }
        if (ans < answer){
            answer = ans;
            bestRoute = cities;
        }
        return;
    }

    for (int city = 0; city < costs.numCols(); city++) {
        if (!visited.contains(city)) {
            visited.insert(city);
            cities.push_back(city);

            minValueTravel(costs, cities, visited, bestRoute, answer);

            cities.remove(cities.size() - 1);
            visited.remove(city);
        }
    }

//    reverseVector(bestRoute);
}

bool isCircularPermutation(const Vector<int>& a, const Vector<int>& b) {
    if (a.size() != b.size()) return false;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        bool match = true;
        for (int j = 0; j < n; ++j) {
            if (a[j] != b[(i + j) % n]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

// Helper function to run a single test case
void runTest(Grid<int>& costs, int expectedCost, const Vector<int>& expectedRoute) {
    Vector<int> cities;
    Set<int> visited;
    Vector<int> bestRoute;
    int result = INT_MAX;

    minValueTravel(costs, cities, visited, bestRoute, result);

    // Debug output
    std::cout << "Expected Cost: " << expectedCost << ", Computed Cost: " << result << std::endl;
    std::cout << "Expected Route: ";
    for (int city : expectedRoute) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    std::cout << "Computed Route: ";
    for (int city : bestRoute) {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    // Check if result matches expectedCost
    assert(result == expectedCost);

    // Check if bestRoute is a circular permutation of expectedRoute
    assert(isCircularPermutation(bestRoute, expectedRoute));

    std::cout << "Test passed! Minimum cost: " << result << ", Best route: ";
    for (int city : bestRoute) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1
    Grid<int> costs1(3, 3);
    costs1[0][0] = 0; costs1[0][1] = 1; costs1[0][2] = 15;
    costs1[1][0] = 10; costs1[1][1] = 0; costs1[1][2] = 20;
    costs1[2][0] = 5; costs1[2][1] = 2; costs1[2][2] = 0;

     // Expected to complete the cycle
    Vector<int> expectedRoute1;
    expectedRoute1.push_back(0);
    expectedRoute1.push_back(1);
    expectedRoute1.push_back(2);
    int expectedCost1 = 1 + 20 + 5; // Cost from 0->1, 1->2, 2->0
    runTest(costs1, expectedCost1, expectedRoute1);

    // Test case 2
    Grid<int> costs2(4, 4);
    costs2[0][0] = 0; costs2[0][1] = 3; costs2[0][2] = 1; costs2[0][3] = 5;
    costs2[1][0] = 3; costs2[1][1] = 0; costs2[1][2] = 6; costs2[1][3] = 7;
    costs2[2][0] = 7; costs2[2][1] = 6; costs2[2][2] = 0; costs2[2][3] = 2;
    costs2[3][0] = 5; costs2[3][1] = 7; costs2[3][2] = 2; costs2[3][3] = 0;

    // Expected to complete the cycle
    Vector<int> expectedRoute2;
    expectedRoute2.push_back(0);
    expectedRoute2.push_back(2);
    expectedRoute2.push_back(3);
    expectedRoute2.push_back(1);

    int expectedCost2 = 1 + 2 + 7 + 3; // Cost from 0->2, 2->3, 3->1, 1->0
    runTest(costs2, expectedCost2, expectedRoute2);

    std::cout << "All test cases passed!" << std::endl;
    return 0;
}


//    // Expected to complete the cycle

