#include <string>
#include "set.h"
#include "map.h"

using namespace std;
struct nodeT {
	int v;
	int weight;//ignore this field!!
	nodeT * left;
	nodeT * right;
};

void pathSum(nodeT * root, int s, Set<nodeT *> &nodes);