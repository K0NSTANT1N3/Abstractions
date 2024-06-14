/**********************************************************
 * File: HuffmanEncoding.cpp
 *
 * Implementation of the functions from HuffmanEncoding.h.
 * Most (if not all) of the code that you write for this
 * assignment will go into this file.
 */

#include "HuffmanEncoding.h"
#include "pqueue.h"

/* Function: getFrequencyTable
 * Usage: Map<ext_char, int> freq = getFrequencyTable(file);
 * --------------------------------------------------------
 * Given an input stream containing text, calculates the
 * frequencies of each character within that text and stores
 * the result as a Map from ext_chars to the number of times
 * that the character appears.
 *
 * This function will also set the frequency of the PSEUDO_EOF
 * character to be 1, which ensures that any future encoding
 * tree built from these frequencies will have an encoding for
 * the PSEUDO_EOF character.
 */
Map<ext_char, int> getFrequencyTable(istream &file) {
    Map<ext_char, int> ans;
    char c;
    ext_char ch;
    while (file.get(c)) {
        ch = c;
        ans[ch]++;
    }
    ans[PSEUDO_EOF] = 1;

    return ans;
}


void codesOfChar(PriorityQueue<int> &indexesOfUnionsInArray, std::string (&parentUnion)[600], int k) {
    /* Base Case */
    if (indexesOfUnionsInArray.size() <= 2) {
        int i1 = indexesOfUnionsInArray.dequeue();
        int i0 = indexesOfUnionsInArray.dequeue();

        parentUnion[i1] = "1";
        parentUnion[i0] = "0";
        return;
    }

    /* Inductive Step */
    int i1Priority = indexesOfUnionsInArray.peekPriority();
    int i1 = indexesOfUnionsInArray.dequeue();

    int i0Priority = indexesOfUnionsInArray.peekPriority();
    int i0 = indexesOfUnionsInArray.dequeue();

    int newPriority = i1Priority + i0Priority;
    indexesOfUnionsInArray.enqueue(k, newPriority);

    codesOfChar(indexesOfUnionsInArray, parentUnion, k + 1);
    parentUnion[i1] = parentUnion[k] + "1";
    parentUnion[i0] = parentUnion[k] + "0";
}

void buildTreeFromMap(Map<string, ext_char> &codedChars, Map<ext_char, int> &frequencies, Node *&head) {
    /* Base Case */
    if (codedChars.size() <= 0) {
        head = NULL;
        return;
    } else if (codedChars.size() == 1) {
        for (string str: codedChars) {
            ext_char curChar = codedChars[str];
            head->character = curChar;
            head->weight = frequencies[curChar];
            head->one = head->zero = NULL;
        }
        return;
    } else {
        Map<string, ext_char> zeroCodedChars;
        Map<string, ext_char> oneCodedChars;

        for (string str: codedChars) {
            if (str[0] == '0') {
                zeroCodedChars.put(str.substr(1), codedChars[str]);
            } else if (str[0] == '1') {
                oneCodedChars.put(str.substr(1), codedChars[str]);
            }
        }

        head->character = NOT_A_CHAR;
        head->one = new Node;
        head->zero = new Node;

        buildTreeFromMap(zeroCodedChars, frequencies, head->zero);
        buildTreeFromMap(oneCodedChars, frequencies, head->one);

        head->weight = head->zero->weight + head->one->weight;
    }
}

/* Function: buildEncodingTree
 * Usage: Node* tree = buildEncodingTree(frequency);
 * --------------------------------------------------------
 * Given a map from extended characters to frequencies,
 * constructs a Huffman encoding tree from those frequencies
 * and returns a pointer to the root.
 *
 * This function can assume that there is always at least one
 * entry in the map, since the PSEUDO_EOF character will always
 * be present.
 */
Node *buildEncodingTree(Map<ext_char, int> &frequencies) {
    PriorityQueue<int> indexesOfUnionsInArray;

    string parentUnion[600];
    ext_char charNumeration[300];

    int count = 0;
    for (ext_char c: frequencies) { // create priority queue of characters
        count++;
        charNumeration[count] = c;
        indexesOfUnionsInArray.enqueue(count, frequencies[c]);
    }

    /*
     * charNumeration contains characters and their indexes
     * charArchive contains frequency of characters on indexes in charNumeration array
     *
     */

    codesOfChar(indexesOfUnionsInArray, parentUnion, count + 1);

    Map<string, ext_char> codedChars;
    for (int i = 1; i <= count; i++) {
        ext_char ch = charNumeration[i];
        string chString = parentUnion[i];

        codedChars.put(chString, ch);
    }

    Node *head = new Node;
    buildTreeFromMap(codedChars, frequencies, head);
    return head;
}

/* Function: freeTree
 * Usage: freeTree(encodingTree);
 * --------------------------------------------------------
 * Deallocates all memory allocated for a given encoding
 * tree.
 */
void freeTree(Node *root) {
    if (root == NULL)return;

    freeTree(root->one);
    freeTree(root->zero);
    delete root;
}

void getCodeFromTree(Node *encodingTree, Map<ext_char, string> &ans, string curPath) {
    if (encodingTree == NULL)return;

    if (encodingTree->character == NOT_A_CHAR) {
        getCodeFromTree(encodingTree->zero, ans, curPath + "0");
        getCodeFromTree(encodingTree->one, ans, curPath + "1");
        return;
    }

    ans.put(encodingTree->character, curPath);
}

/* Function: encodeFile
 * Usage: encodeFile(source, encodingTree, output);
 * --------------------------------------------------------
 * Encodes the given file using the encoding specified by the
 * given encoding tree, then writes the result one bit at a
 * time to the specified output file.
 *
 * This function can assume the following:
 *
 *   - The encoding tree was constructed from the given file,
 *     so every character appears somewhere in the encoding
 *     tree.
 *
 *   - The output file already has the encoding table written
 *     to it, and the file cursor is at the end of the file.
 *     This means that you should just start writing the bits
 *     without seeking the file anywhere.
 */
void encodeFile(istream &infile, Node *encodingTree, obstream &outfile) {
    Map<ext_char, string> ans;
    getCodeFromTree(encodingTree, ans, "");

    char c;
    ext_char ec;

    while (infile.get(c)) {
        ec = c;
        string hashStr = ans.get(ec);

        for (char i: hashStr) {
            if (i == '1') outfile.writeBit(1);
            else outfile.writeBit(0);
        }
    }

    string eofStr = ans.get(PSEUDO_EOF);
    for (char i: eofStr) {
        if (i == '1') outfile.writeBit(1);
        else outfile.writeBit(0);
    }
}

void getHashFromTree(Node *encodingTree, Map<string, ext_char> &hashOfStr, string curPath) {
    /* Base Case */
    if (encodingTree == NULL) {
        return;
    }
    if (encodingTree->character != NOT_A_CHAR) {
        hashOfStr.put(curPath, encodingTree->character);
        return;
    }

    /* Inductive Step */
    getHashFromTree(encodingTree->zero, hashOfStr, curPath + "0");
    getHashFromTree(encodingTree->one, hashOfStr, curPath + "1");
}

/* Function: decodeFile
 * Usage: decodeFile(encodedFile, encodingTree, resultFile);
 * --------------------------------------------------------
 * Decodes a file that has previously been encoded using the
 * encodeFile function.  You can assume the following:
 *
 *   - The encoding table has already been read from the input
 *     file, and the encoding tree parameter was constructed from
 *     this encoding table.
 *
 *   - The output file is open and ready for writing.
 */
void decodeFile(ibstream &infile, Node *encodingTree, ostream &file) {
    Map<string, ext_char> hashOfStr;
    getHashFromTree(encodingTree, hashOfStr, "");

    string constructedSequence = "";
    ext_char charFromSequence = NOT_A_CHAR;

    while (true) {
        int curBit = infile.readBit();

        if (curBit == 0) {
            constructedSequence += "0";
        } else if (curBit == 1) {
            constructedSequence += "1";
        }

        if (hashOfStr.containsKey(constructedSequence)) {
            charFromSequence = hashOfStr.get(constructedSequence);
            constructedSequence = "";

            if (charFromSequence == PSEUDO_EOF)break;

            file.put(charFromSequence);
        }
    }
}

/* Function: writeFileHeader
 * Usage: writeFileHeader(output, frequencies);
 * --------------------------------------------------------
 * Writes a table to the front of the specified output file
 * that contains information about the frequencies of all of
 * the letters in the input text.  This information can then
 * be used to decompress input files once they've been
 * compressed.
 *
 * This function is provided for you.  You are free to modify
 * it if you see fit, but if you do you must also update the
 * readFileHeader function defined below this one so that it
 * can properly read the data back.
 */
void writeFileHeader(obstream &outfile, Map<ext_char, int> &frequencies) {
    /* The format we will use is the following:
     *
     * First number: Total number of characters whose frequency is being
     *               encoded.
     * An appropriate number of pairs of the form [char][frequency][space],
     * encoding the number of occurrences.
     *
     * No information about PSEUDO_EOF is written, since the frequency is
     * always 1.
     */

    /* Verify that we have PSEUDO_EOF somewhere in this mapping. */
    if (!frequencies.containsKey(PSEUDO_EOF)) {
        error("No PSEUDO_EOF defined.");
    }

    /* Write how many encodings we're going to have.  Note the space after
     * this number to ensure that we can read it back correctly.
     */
    outfile << frequencies.size() - 1 << ' ';

    /* Now, write the letter/frequency pairs. */
    foreach (ext_char ch in frequencies) {
            /* Skip PSEUDO_EOF if we see it. */
            if (ch == PSEUDO_EOF) continue;

            /* Write out the letter and its frequency. */
            outfile << char(ch) << frequencies[ch] << ' ';
        }
}

/* Function: readFileHeader
 * Usage: Map<ext_char, int> freq = writeFileHeader(input);
 * --------------------------------------------------------
 * Reads a table to the front of the specified input file
 * that contains information about the frequencies of all of
 * the letters in the input text.  This information can then
 * be used to reconstruct the encoding tree for that file.
 *
 * This function is provided for you.  You are free to modify
 * it if you see fit, but if you do you must also update the
 * writeFileHeader function defined before this one so that it
 * can properly write the data.
 */
Map<ext_char, int> readFileHeader(ibstream &infile) {
    /* This function inverts the mapping we wrote out in the
     * writeFileHeader function before.  If you make any
     * changes to that function, be sure to change this one
     * too!
     */
    Map<ext_char, int> result;

    /* Read how many values we're going to read in. */
    int numValues;
    infile >> numValues;

    /* Skip trailing whitespace. */
    infile.get();

    /* Read those values in. */
    for (int i = 0; i < numValues; i++) {
        /* Get the character we're going to read. */
        ext_char ch = infile.get();

        /* Get the frequency. */
        int frequency;
        infile >> frequency;

        /* Skip the space character. */
        infile.get();

        /* Add this to the encoding table. */
        result[ch] = frequency;
    }

    /* Add in 1 for PSEUDO_EOF. */
    result[PSEUDO_EOF] = 1;
    return result;
}

/* Function: compress
 * Usage: compress(infile, outfile);
 * --------------------------------------------------------
 * Main entry point for the Huffman compressor.  Compresses
 * the file whose contents are specified by the input
 * ibstream, then writes the result to outfile.  Your final
 * task in this assignment will be to combine all of the
 * previous functions together to implement this function,
 * which should not require much logic of its own and should
 * primarily be glue code.
 */
void compress(ibstream &infile, obstream &outfile) {
    Map<ext_char, int> freq = getFrequencyTable(infile);
    Node* root = buildEncodingTree(freq);

    encodeFile(infile, root, outfile);
}

/* Function: decompress
 * Usage: decompress(infile, outfile);
 * --------------------------------------------------------
 * Main entry point for the Huffman decompressor.
 * Decompresses the file whose contents are specified by the
 * input ibstream, then writes the decompressed version of
 * the file to the stream specified by outfile.  Your final
 * task in this assignment will be to combine all of the
 * previous functions together to implement this function,
 * which should not require much logic of its own and should
 * primarily be glue code.
 */
void decompress(ibstream &infile, ostream &outfile) {

}

