
#include <string>
#include <iostream>
#include <vector>

using namespace std;

long stringToLong(string s) {
    char *remaining;
    long answer;

    answer = strtol(s.c_str(), &remaining, 10);
    return answer;
}

bool splitStringHelper(string s, vector<bool> &dots, int index) {
    /* base case */
    if (index >= s.size()) {
        vector<int> indexes;
        for (int i = 0; i < dots.size(); i++) {
            if (dots[i]) {
                indexes.push_back(i);
            }
        }
        string str1 = "";
        if(indexes.size() <= 2)return false;
        for (int i = 1; i < indexes.size(); i++) {

            string str2 = s.substr(indexes[i - 1], indexes[i] - indexes[i - 1]);
            if (str1.size() == 0) {
                str1 = str2;
                continue;
            }
            long int1 = stringToLong(str1);
            long int2 = stringToLong(str2);

            if (int1 != int2 + 1) {
                return false;
            }
            str1 = str2;
        }
        return true;
    }
    /* inductive step */
    if (splitStringHelper(s, dots, index + 1)) {
        return true;
    }

    dots[index] = true;
    if (splitStringHelper(s, dots, index + 1)) {
        dots[index] = false;
        return true;
    }

    dots[index] = false;

    return false;
}

bool splitString(string s) {
    // long num = stringToLong(s);
    vector<bool> dots(s.size() + 1, false);
    dots[0] = dots[dots.size() - 1] = true;

    return splitStringHelper(s, dots, 0);
}


/** Test */

void printTestResults(bool passed, int testNum, int & passedCounter) {
    if (passed) {
        cout << "test " << testNum << " passed" << endl;
        passedCounter++;
    } else {
        cout << "test " << testNum << " failed" << endl;
    }
}


const int splitTestsNum = 27;

string splitTests[splitTestsNum] = {
        "0500403",
        "10099098",
        "1098765403",
        "000000100",
        "0568805687",
        "0420419418",
        "0095749573",
        "074277426",
        "1110980765",
        "608806087",
        "4990498497",
        "2423222120",
        "084798478",
        "589505894",
        "18171615",
        "4107841077",
        "638406383",
        "5352515049",
        "5265250524",
        "5955940593",
        "2605826057",
        "1",
        "01234",
        "09080701",
        "3202872336",
        "166537080",
        "105154605"
};

bool splitTestAnswers[splitTestsNum] = {
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false
};

bool runSplitTest(int testNum) {
    return splitString(splitTests[testNum-1]) == splitTestAnswers[testNum-1] &&
           splitString("50043") && !splitString("9080703");
}

void runSplitTests() {
    cout << "### Run Split tests ###" << endl;
    int passedNum = 0;
    int testNum = 1;

    for (; testNum<=splitTestsNum; testNum++) {
        bool res = runSplitTest(testNum);
        printTestResults(res, testNum, passedNum);
    }

    cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
    runSplitTests();

    return 0;
}
