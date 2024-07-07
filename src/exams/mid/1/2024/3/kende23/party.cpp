#include "party.h"
#include "set.h"
#include "strlib.h"

bool hapyEnd(Vector<Set < int>> &friends, Vector<int>& numpp) {
	for (int i = 0; i < numpp.size(); i++) {
		int friendOfI = numpp[i];
		if (friendOfI == -1)return false;

		if (friends[friendOfI].contains(i)) {
			return false;
		}
		
		if (friends[i].contains(friendOfI))return false;
	}

	return true;
}

bool possible(Vector<Set<int>>& conflicts, Vector<int>& numpp, int itr) {
	if (itr >= conflicts.size() - 1) {
		return hapyEnd(conflicts, numpp);
	}

	if (numpp[itr] != -1) {
		return possible(conflicts, numpp, itr + 1);
	}

	bool ans = false;
	for (int i = itr + 1; i < conflicts.size(); i++) {
		if (numpp[i] != -1)continue;

		numpp[i] = itr;
		numpp[itr] = i;

		if (possible(conflicts, numpp, itr + 1))return true;

		numpp[i] = -1;
		numpp[itr] = -1;
	}
	return false;
}

bool isPartyPossible(Vector<Set<int> > &conflicts) {
	Vector<int> numpp;
	for (int i = 0; i < conflicts.size(); i++) {
		numpp.add(-1);
	}

	return possible(conflicts, numpp, 0);

	return false;
}
