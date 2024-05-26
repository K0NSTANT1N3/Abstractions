/*
 * File: InverseGenetics.cpp
 * --------------------------
 * Name: Konstantine Endeladze
 * This file is the starter project for the Inverse Genetics problem
 * on Assignment #3.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "map.h"
#include "console.h"


using namespace std;

/* Function: listAllRNAStrandsFor(string protein,
 *                                Map<char, Set<string> >& codons);
 * Usage: listAllRNAStrandsFor("PARTY", codons);
 * ==================================================================
 * Given a protein and a map from amino acid codes to the codons for
 * that code, lists all possible RNA strands that could generate
 * that protein
 */
void listAllRNAStrandsFor(string protein, Map<char, Set<string> > &codons);

/* Function: loadCodonMap();
 * Usage: Map<char, Lexicon> codonMap = loadCodonMap();
 * ==================================================================
 * Loads the codon mapping table from a file.
 */
Map<char, Set<string> > loadCodonMap();

void listOneRNAStrandsFor(string protein, Map<char, Set<string> > &codons, string rna = "");

int main() {
    /* Load the codon map. */
    Map<char, Set<string> > codons = loadCodonMap();

    //test here
    cout << "Enter desired protein: " << endl;
    string protein;
    cin >> protein;
    listAllRNAStrandsFor(protein, codons);
    return 0;
}

/* You do not need to change this function. */
Map<char, Set<string> > loadCodonMap() {
    ifstream input("codons.txt");
    Map<char, Set<string> > result;

    /* The current codon / protein combination. */
    string codon;
    char protein;

    /* Continuously pull data from the file until all data has been
     * read.
     */
    while (input >> codon >> protein) {
        result[protein] += codon;
    }

    return result;
}

void listAllRNAStrandsFor(string protein, Map<char, Set<string> > &codons) {
    listOneRNAStrandsFor(protein, codons, "");
}

void listOneRNAStrandsFor(string protein, Map<char, Set<string> > &codons, string rna) {
    if(protein == "") {
        cout << rna << endl;
        return;
    }
    char aminoAcid = protein[0];
    for(string codon : codons[aminoAcid]){
        listOneRNAStrandsFor(protein.substr(1), codons, rna + codon);
    }
}