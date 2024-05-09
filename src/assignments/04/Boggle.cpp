/*
 * File: Boggle.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */

#include <iostream>
//#include "gboggle.h"
//#include "grid.h"
//#include "gwindow.h"
//#include "lexicon.h"
#include "random.h"
#include <vector>
#include "simpio.h"
#include "lexicon.h"

using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;

const string STANDARD_CUBES[16] = {
        "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
        "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
        "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
        "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

const string BIG_BOGGLE_CUBES[25] = {
        "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
        "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
        "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
        "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
        "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

/* new constants */
Lexicon english("/home/konstantine/CLionProjects/Abstractions/src/assignments/04/EnglishWords.dat");

/* Function prototypes */

void welcome();

void giveInstructions();

/* Additional function prototypes */
vector<vector<string>> getDiceVector();

vector<vector<char>> getBoard(vector<vector<string>> &diceVector);

vector<string> playerGuesses(vector<vector<char>> &board);

bool isWordValid(vector<vector<char>> &board, string word);

void makeCapital(string &word);

bool allLetters(string basicString);

bool canWordBeConstructed(vector<vector<char>> &board, string word, int row, int col, vector<vector<bool>> &visited);

bool isWordOnBoard(vector<vector<char>> &board, string word);

/* Main program */

int main() {
//    GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
//    initGBoggle(gw);
//    welcome();
//    giveInstructions();
//
//    vector<vector<string>> words = getDiceVector();
//    vector<vector<char>> board = getBoard(words);

    //create 4x4 board
    vector<vector<char>> board =

    return 0;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
    cout << "Welcome!  You're about to play an intense game ";
    cout << "of mind-numbing Boggle.  The good news is that ";
    cout << "you might improve your vocabulary a bit.  The ";
    cout << "bad news is that you're probably going to lose ";
    cout << "miserably to this little dictionary-toting hunk ";
    cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
    cout << endl;
    cout << "The boggle board is a grid onto which I ";
    cout << "I will randomly distribute cubes. These ";
    cout << "6-sided cubes have letters rather than ";
    cout << "numbers on the faces, creating a grid of ";
    cout << "letters on which you try to form words. ";
    cout << "You go first, entering all the words you can ";
    cout << "find that are formed by tracing adjoining ";
    cout << "letters. Two letters adjoin if they are next ";
    cout << "to each other horizontally, vertically, or ";
    cout << "diagonally. A letter can only be used once ";
    cout << "in each word. Words must be at least four ";
    cout << "letters long and can be counted only once. ";
    cout << "You score points based on word length: a ";
    cout << "4-letter word is worth 1 point, 5-letters ";
    cout << "earn 2 points, and so on. After your puny ";
    cout << "brain is exhausted, I, the supercomputer, ";
    cout << "will find all the remaining words and double ";
    cout << "or triple your paltry score." << endl << endl;
    cout << "Hit return when you're ready...";
    getLine();
}

// [TODO: Fill in the rest of the code]

vector<vector<string>> getDiceVector() {
    vector<vector<string>> words;
    int n;
    cout << "Enter the dimension of the board: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<string> row;
        for (int j = 0; j < n; j++) {
            cout << "Enter the letters for cube " << i + 1 << ": ";
            string word;
            cin >> word;
            //check if all symbols are letters
            if (word.size() != 6 || !allLetters(word)) {
                cout << "Invalid input. Please enter 6 letters." << endl;
                j--;
                continue;
            }
            makeCapital(word); //make word upperCase
            row.push_back(word);
        }
        words.push_back(row);
        cout << endl;
    }

    return words;
}

bool allLetters(string basicString) {
    for (int i = 0; i < basicString.size(); i++) {
        if (!isalpha(basicString[i])) {
            return false;
        }
    }
    return true;
}

vector<vector<char>> getBoard(vector<vector<string>> &diceVector) {
    vector<vector<char>> board;
    for (int i = 0; i < diceVector.size(); i++) {
        vector<char> row;
        for (int j = 0; j < diceVector[i].size(); j++) {
            int randomIndex = randomInteger(0, diceVector[i][j].size() - 1);
            char letter = diceVector[i][j][randomIndex];
            row.push_back(letter);
        }
        board.push_back(row);
    }

    return board;
}

vector<string> playerGuesses(vector<vector<char>> &board) {
    vector<string> guesses;
    while (true) {
        string guess = getLine("Enter a word: ");
        if (guess == "") {
            break;
        }
        if (isWordValid(board, guess)) {
            guesses.push_back(guess);
        } else {
            cout << "Invalid word. Try again." << endl;
        }
    }
    return guesses;
}

bool isWordValid(vector<vector<char>> &board, string word) {
    return !(word.size() < 4 || word.size() > board.size() * board[0].size() || !english.contains(word) ||
             !isWordOnBoard(board, word));
}

bool canWordBeConstructed(vector<vector<char>> &board, string word, int row, int col, vector<vector<bool>> &visited) {
    if (word.size() == 0) {
        return true;
    }

    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
        return false;
    }

    if (visited[row][col]) {
        return false;
    }

    if (board[row][col] != toupper(word[0])) {
        return false;
    }

    visited[row][col] = true;

    string rest = word.substr(1);
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (canWordBeConstructed(board, rest, row + i, col + j, visited)) {
                return true;
            }
        }
    }

    visited[row][col] = false;
    return false;
}

bool isWordOnBoard(vector<vector<char>> &board, string word) {
    //initially visited hase all square false
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == toupper(word[0])) {
                if (canWordBeConstructed(board, word, i, j, visited)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void makeCapital(string &word) {
    for (int i = 0; i < word.size(); i++) {
        word[i] = toupper(word[i]);
    }
}