#include "shoping.h"

//
//int getMaxWeight(Vector<item> &items, int cap1, int cap2, int money, int weight){
//	if( money < 0 || cap1 < 0 || cap2 < 0) return 0;
//	if(items.isEmpty()) return weight;
//
//	item it = items[items.size() - 1];
//	items.remove(items.size() - 1);
//	int res1 = getMaxWeight(items, cap1 - it.weight, cap2, money - it.price, weight+it.weight);
//	int res2 = getMaxWeight(items, cap1, cap2-it.weight, money - it.price, weight + it.weight);
//	int res3 = getMaxWeight(items, cap1, cap2, money, weight);
//	items.add(it);
//	return max(res1,max(res3,res2));
//}
//
//
//
//int findBestComb(Vector<item> &items, Vector<bag> &bags, int money) {
//	int ans  = 0;
//	for(int i = 0; i < bags.size()-1; i++){
//		for(int j = 0 ; j < bags.size(); j++){
//			int moneyLeft = money - bags[i].price - bags[j].price;
//			if( moneyLeft > 0)
//				ans = max(ans, getMaxWeight(items, bags[i].cap, bags[j].cap, moneyLeft, 0));
//		}
//	}
//	return ans;
//}

int putItems(Vector<item> &items, int bag1, int bag2, int money, int itr) {
    if (itr >= items.size() || money == 0 ||
        (bag1 == 0 && bag2 == 0))
        return 0;

    int ans1 = putItems(items, bag1, bag2, money, itr+1);
    item it = items[itr];
    if(it.price > money)return ans1;

    int ans2 = 0;
    if(it.weight <= bag1){
        ans2 = putItems(items, bag1 - it.weight, bag2, money - it.price, itr+1) + it.weight;
    }

    int ans3 = 0;
    if(it.weight <= bag2){
        ans3 = putItems(items, bag1, bag2 - it.weight, money - it.price, itr+1) + it.weight;
    }

    return max(ans1, max(ans2, ans3));
}

int findBestComb(Vector<item> &items, Vector<bag> &bags, int money) {
    int ans = 0;
    for (int i = 0; i < bags.size() - 1; i++) {
        for (int j = i + 1; j < bags.size(); j++) {
            bag bag1 = bags[i];
            bag bag2 = bags[j];

            if(bag1.price+bag2.price >= money)continue;

            int curAns = putItems(items, bag1.cap, bag2.cap, money - bag1.price - bag2.price, 0);
            ans = max(ans, curAns);
        }
    }
    return ans;
}