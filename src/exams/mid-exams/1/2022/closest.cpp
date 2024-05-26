#include <iostream>
#include "vector.h"

int closerNum(int ans, int tmp) {
    if (tmp == -ans) {
        ans = ans < 0 ? ans : -ans;
    } else {
        if (tmp < 0) {
            if (ans < 0) ans = max(ans, tmp);
            else {
                ans = ans < -tmp ? ans : tmp;
            }
        } else {
            if (ans > 0) ans = min(ans, tmp);
            else {
                ans = ans > -tmp ? ans : tmp;
            }
        }
    }
    return ans;
}

int findClosestHelper(Vector<int> &list, int target, int sum, int index) {
    if (index >= list.size())return sum;

    int ans = target;

    int tmp = findClosestHelper(list, target, sum, index + 1) - target;
    ans = closerNum(ans, tmp);

    tmp = findClosestHelper(list, target, sum + list[index], index + 1) - target;
    ans = closerNum(ans, tmp);

    tmp = findClosestHelper(list, target, sum - list[index], index + 1) - target;
    ans = closerNum(ans, tmp);

    return ans + target;
}

int findClosest(Vector<int> &list, int target) {
    return findClosestHelper(list, target, 0, 0);
}
