//
// Created by konstantine on 7/1/24.
//

#include <iostream>
#include <vector>

using namespace std;

int distanceBetweenNumbers(int a, int b) {
    return abs(a - b);
}

void closestSum(int target, vector<int> &numbers, int itr, int curAns, int &ans) {
    /* Base Case */
    if (distanceBetweenNumbers(curAns, target) < distanceBetweenNumbers(ans, target)) {
        ans = curAns;
    }

    if (itr >= numbers.size())return;

    /* Recursive Step */

    int num = numbers[itr];
    closestSum(target, numbers, itr + 1, curAns, ans);
    closestSum(target, numbers, itr + 1, curAns + num, ans);
    closestSum(target, numbers, itr + 1, curAns - num, ans);
}

int closestSum(int target, vector<int> &numbers) {
    int ans = 0;
    closestSum(target, numbers, 0, 0, ans);
    return ans;
}

int main() {
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(2);
    numbers.push_back(17);
    numbers.push_back(19);

    cout << closestSum(10, numbers);
}