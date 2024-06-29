#include "vitamins.h"

using namespace std;

void fruitListRec(Set<string> &vitamins, Vector<Set<string>> &fruits, int itr, Vector<int> curAns, Vector<int> &ans,
                  Set<string> used) {


    /* Base Case */
    if (used.size() == vitamins.size()) {
        if(curAns.size() < ans.size() || ans.isEmpty()){
            ans = curAns;
        }
        return;
    }

    if(itr >= fruits.size())return;

    /* Inductive Step */
    fruitListRec(vitamins, fruits, itr + 1, curAns, ans, used);

    Set<string> curFruit = fruits[itr];
    Set<string> newVitamins;

    for(string vt : curFruit){
        if(vitamins.contains(vt) && !used.contains(vt)){
            newVitamins.insert(vt);
        }
    }

    if(newVitamins.isEmpty())return;

    curAns.push_back(itr);
    used += newVitamins;

    fruitListRec(vitamins, fruits, itr + 1, curAns, ans, used);
}

Vector<int> fruitList(Set<string> vitamins, Vector<Set<string> > fruits) {
    Vector<int> curAns, ans;
    Set<string> used;
    fruitListRec(vitamins, fruits, 0, curAns, ans, used);
    return ans;
}
