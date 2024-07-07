#include "gifts.h"

bool canBill(Vector<int>& bills, int priceSum, int itr) {
	if (0 == priceSum) {
		return true;
	}
	if (priceSum < 0)return false;

	if (itr >= bills.size())return false;

	bool ansWith = canBill(bills, priceSum, itr + 1);
	bool ansWithout = false;

	int curBill = bills[itr];

	if (curBill <= priceSum) {
		 ansWithout = canBill(bills, priceSum - curBill, itr + 1);
	}

	return ansWith || ansWithout;
}

void substs(Vector<int>& prices, Vector<int>& bills, Vector<int>&indexSet, int itr, int curAns, int &ans) {
	if (itr >= prices.size()) {
		if (curAns > ans) {
			int priceSum = 0;
			for (int i = 0; i < indexSet.size(); i++) {
				priceSum += prices[indexSet[i]];
			}

			if (canBill(bills, priceSum, 0)) {
				ans = curAns;
			}

		}

		return;
	}

	substs(prices, bills, indexSet, itr + 1, curAns, ans);

	indexSet.push_back(itr);
	substs(prices, bills, indexSet, itr + 1, curAns + 1, ans);

	indexSet.remove(indexSet.size() - 1);
}

int maxGifts(Vector<int> &prices, Vector<int> &bills) {
	int ans = 0;
	Vector<int> indexSet;
	substs(prices, bills, indexSet, 0, 0, ans);
	return ans;
}
