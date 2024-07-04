#include "max_weight.h"
#include "set.h"

bool canWeight(Vector<int> &weight, int item, int itr) {
    if (item == 0)return true;
    if (itr >= weight.size())return false;

    int cur = weight[itr];
    if (canWeight(weight, item, itr + 1))return true;
    if (canWeight(weight, item - cur, itr + 1)) return true;
    if (canWeight(weight, item + cur, itr + 1)) return true;

    return false;
}

int maxWeight(Vector<int> &weights, Vector<int> &items) {
    int ans = 0;

    for (int i = 0; i < items.size(); i++) {
        int itm1 = items[i];
        bool possible1 = canWeight(weights, itm1, 0);

        if (possible1) {
            weights.push_back(itm1);
            items.remove(i);

            int itm2 = -1;
            for (int j = 0; j < items.size(); j++) {
                int tmp = items[j];
                bool possible2 = canWeight(weights, tmp, 0);
                if (possible2) {
                    itm2 = max(itm2, items[j]);
                }
            }
            if (itm2 != -1) ans = max(ans, itm1 + itm2);
            weights.remove(weights.size() - 1);
            items.insert(i, itm1);
        }
    }
    return ans;
}
