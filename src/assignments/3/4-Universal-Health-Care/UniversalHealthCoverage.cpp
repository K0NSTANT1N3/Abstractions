/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: Konstantine Endeladze
 * This file is the starter project for the UniversalHealthCoverage problem
 * on Assignment #3.
 */

#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"

using namespace std;

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string> &cities,
                               Vector<Set<string> > &locations,
                               int numHospitals,
                               Vector<Set<string> > &result);

Set<string> combineSets(Vector<Set<string> > &result);

int main() {
    //test case
    Set<string> cities;
    cities += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J";
    Vector<Set<string> > locations;
    Set<string> hospital1;
    hospital1 += "A", "B", "C";
    Set<string> hospital2;
    hospital2 += "B", "C", "D", "E";
    Set<string> hospital3;
    hospital3 += "C", "D", "E", "F", "G";
    Set<string> hospital4;
    hospital4 += "D";
    Set<string> hospital5;
    hospital5 += "H", "I", "J";
    locations += hospital1, hospital2, hospital3, hospital4, hospital5;

    Vector<Set<string> > result;
    if (canOfferUniversalCoverage(cities, locations, 3, result)) {
        cout << "It is possible to offer universal coverage with 3 hospitals." << endl;
        for (Set<string> hospital : result) {
            cout << hospital << endl;
        }
    } else {
        cout << "It is not possible to offer universal coverage with 3 hospitals." << endl;
    }
    return 0;
}

bool canOfferUniversalCoverage(Set<string> &cities,
                               Vector<Set<string> > &locations,
                               int numHospitals,
                               Vector<Set<string> > &result) {

    /* Base Case */
    if (combineSets(result).size() == (cities).size()) {
        return true;
    }
    if (numHospitals == 0 || locations.isEmpty()) {
        return false;
    }

    /* Inductive Step */
    Set<string> hospital = locations[locations.size() - 1];
    locations.remove(locations.size() - 1);

    result.push_back(hospital); // hospital is included
    if (canOfferUniversalCoverage(cities, locations, numHospitals - 1, result)) {
        locations.push_back(hospital);
        return true;
    }

    result.remove(result.size() - 1); // hospital is excluded
    bool ans = canOfferUniversalCoverage(cities, locations, numHospitals, result);

    locations.push_back(hospital);
    return ans;
}

Set<string> combineSets(Vector<Set<string> > &result) {
    /* Base Case */
    Set<string> res;
    if (result.isEmpty()) return res;

    /* Inductive Step */
    Set<string> covered = result[result.size() - 1];
    result.remove(result.size() - 1);
    res += covered + combineSets(result);
    result.push_back(covered);
    return res;
}