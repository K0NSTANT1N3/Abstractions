//
// Created by konstantine on 3/26/24.
//

#include "Collections.h"

/** public functions **/

void Collections::reverseReading(string fileSrc, string fileDest) {
    ifstream in;
    in.open(fileSrc);

    TokenScanner scanner;
    scanner.setInput(in);

    stack<string> words;
    while (scanner.hasMoreTokens()) {
        words.push(scanner.nextToken());
    }
    in.close();

    ofstream out;
    out.open(fileDest);

    while (!words.empty()) {
        out << words.top() << " ";
        words.pop();
    }


    out.close();
}

void Collections::oddEvenReading(string fileSrc, string fileDest) {
    ifstream in;
    in.open(fileSrc);

    TokenScanner scanner;
    scanner.setInput(in);

    vector <string> words;

    while (scanner.hasMoreTokens()) {
        words.push_back(scanner.nextToken());
    }
    in.close();

    ofstream out;
    out.open(fileDest);

    for (int i = 0; i < words.size(); i += 2) out << words[i] << " ";
    for (int i = 1; i < words.size(); i += 2) out << words[i] << " ";

    out.close();
}