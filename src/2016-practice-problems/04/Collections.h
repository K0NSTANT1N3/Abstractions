//
// Created by konstantine on 3/26/24.
//

#ifndef ABSTRACTIONS_COLLECTIONS_H
#define ABSTRACTIONS_COLLECTIONS_H

#include <iostream>
#include <fstream>
#include <stack>
#include<vector>
#include <tokenscanner.h>

using namespace std;

class Collections {
public:
    void reverseReading(string fileSrc, string fileDest);

    void oddEvenReading(string fileSrc, string fileDest);
};

#endif //ABSTRACTIONS_COLLECTIONS_H