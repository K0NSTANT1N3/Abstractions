//
// Created by konstantine on 3/18/24.
//

#include "SelfReadingFile.h"

void SelfReadingFile::archiveMyHeader() {
    string filePath = "/home/konstantine/CLionProjects/Abstractions/slides/2-string-streams/SelfReadingFile.h";
    ifstream file(filePath);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filePath << endl;
    }
}