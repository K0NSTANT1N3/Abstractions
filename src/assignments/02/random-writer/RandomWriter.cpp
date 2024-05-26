// Description: Implementation of the Random Writer program.
#include "RandomWriter.h"

/** private functions **/
char RandomWriter::generateRandomChar(const map<char, double> &probability) {
    // Base case: if the probability map is empty, return a default value
    if (probability.empty()) return ' ';

    double random = randomReal(0.0, 1.0); // Generate a random double from 0 to 1

    // Loop through the probability map and find the character corresponding to the generated random number
    double cumulativeProbability = 0.0;
    for (auto it = probability.begin(); it != probability.end(); ++it) {
        cumulativeProbability += it->second;
        if (random <= cumulativeProbability) {
            return it->first;
        }
    }
    return ' ';
}

// Function to create a Markov model of order k
map<string, map<char, double>> RandomWriter::createProbabilityList(const map<string, map<char, int>> &model) {
    // Initialize the probability map
    map<string, map<char, double>> probability;

    // Iterate through each entry in the model map
    for (const auto &entry: model) {
        const string &key = entry.first;
        int total = 0;

        // Calculate the total count of characters for the current key
        for (const auto &pair: entry.second) {
            total += pair.second;
        }

        // Calculate the probability for each character and store it in the probability map
        for (const auto &pair: entry.second) {
            probability[key][pair.first] = static_cast<double>(pair.second) / total;
        }
    }

    return probability;
}

// Function to update the model based on the input line and parameter k
void RandomWriter::updateModel(int k, const string &line, map<string, map<char, int>> &model) {
    if (line.size() < k) return;

    for (int i = 0; i < line.size() - k; i++) {
        string key = line.substr(i, k);
        char nextChar = line[i + k];

        if (model.find(key) == model.end()) {
            model[key] = map<char, int>();
        }
        if (model[key].find(nextChar) == model[key].end()) {
            model[key][nextChar] = 0;
        }
        model[key][nextChar]++;
    }
}

// calculate the "starter" string
string RandomWriter::calculateStarter(const map<string, map<char, int>> &model) {
    string starter;
    int popularity = 0;

    // Iterate through each entry (string) in the model
    for (const auto &entry: model) {
        int newPopularity = 0;
        for (const auto &pair: entry.second) {
            newPopularity += pair.second;
        }
        // Check if the popularity of the current entry is greater than the previous maximum popularity
        if (newPopularity > popularity) {
            starter = entry.first;
            popularity = newPopularity;
        }
    }
    cout << starter << endl;
    return starter;
}

// Function to read the model from a file and update it based on the input line and parameter k
void RandomWriter::readModelFromFile(int k, const string &src, map<string, map<char, int>> &model) {
    ifstream file(src);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << src << endl;
        return;
    }

    // Read the file line by line and update the model
    string line;
    while (getline(file, line)) {
        updateModel(k, line, model);
    }
    cout << "Model: " << model.size() << endl;
    file.close();
}

// Function to generate text based on the Markov model and the starter string
void RandomWriter::generateText(const map<string, map<char, double>> &probability, const string &starter, int charNum) {
//     Open the output file for writing
    ofstream output("output.txt");
    if (!output.is_open()) {
        cerr << "Error: Unable to open file output.txt" << endl;
        return;
    }

    // Generate the text based on the Markov model and the starter string
    string current = starter;
    for (int i = 0; i < charNum; i++) {
        if (probability.find(current) != probability.end()) {
            map<char, double> prob = probability.at(current);
            char nextChar = generateRandomChar(prob);
            cout << nextChar;
            output << nextChar;
            current = current.substr(1) + nextChar;
        } else {
            current = starter;
        }

        if (i % 200 == 0) {
            cout << endl;
        }
    }
    output.close();
}
/** public functions **/

void RandomWriter::markovModel(int k, string src) {
    map<string, map<char, int> > model;
    readModelFromFile(k, src, model);
    //calculate starter
    string starter = calculateStarter(model);
    //create probability list
    map<string, map<char, double>> probability = createProbabilityList(model);
    //generate random text
    generateText(probability, starter, charNum);
}

