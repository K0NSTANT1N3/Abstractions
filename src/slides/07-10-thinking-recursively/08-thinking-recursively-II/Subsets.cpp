//
// Created by konstantine on 5/11/24.
//

#include "Subsets.h"

Set<string> Subsets::generateAllSubsets(Set<string> base) {
    Set<string> ans;

    // Base case: if base is empty, add an empty string to ans and return
    if (base.isEmpty()) {
        ans.add("");
        return ans;
    }

    // Recursive step
    string option = base.first();
    Set<string> subsetsWithoutOption = generateAllSubsets(base - option);
    ans += subsetsWithoutOption; // Add subsets without the option

    // Add subsets with the option by concatenating it to each subset
    for (string s : subsetsWithoutOption) {
        ans.add(option + s);
    }

    return ans;
}

