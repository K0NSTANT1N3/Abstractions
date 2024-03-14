//
// Created by konstantine on 3/14/24.
//

#include "MinMaxMid.h"

const int sentinel = -1;

struct container {
    int min;
    int max;
    double mid;
};

container calculate(int sentinel);

int main() {
    container sample = calculate(sentinel);
    cout << sample.max << endl;
    cout << sample.min << endl;
    cout << sample.mid << endl;

    return 0;
}

container calculate(int sentinel) {
    int min, max, sum, count;
    double mid;

    int a;
    cin >> a;

    min = max = mid = sum = a;
    count = 1;

    while (a != sentinel) {
        cin >> a;
        min = a < min ? a : min;
        max = a > max ? a : max;
        count++;
        sum += a;
    }
    mid = double(sum) / count;

    container ans;
    ans.max = max;
    ans.min = min;
    ans.mid = mid;

    return ans;
}
