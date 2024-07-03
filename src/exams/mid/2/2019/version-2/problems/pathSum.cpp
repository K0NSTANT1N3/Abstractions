#include "pathSum.h"

using namespace std;

void pathSum(nodeT * root, int s, Set<nodeT *> &nodes) {
    if(root == NULL)return;
    if(s < 0)return;
    if(s == 0)nodes.insert(root);

    
}