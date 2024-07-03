#include <string>
#include "vector.h"

using namespace std;

struct itemT {
	int price;
	int weight;
};

void recCar(Vector<int> &cars, itemT curItem, int budget, int itrCar, int &maxAns, int curAns, Vector<itemT> &items, int itrItem);
int transportMax(Vector<int> &cars, Vector<itemT> &items, int budget);
