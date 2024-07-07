#include "LinkedHashmap.h"

const int kHashMask = 0x7FFFFFFF;
int hashCode(string key) {
    int hashVal = 0;
    for (int x = 0; x < key.length(); ++x) {
        hashVal ^= (hashVal << 5) +
                   (hashVal >> 2) +
                   key[x];
    }
    return hashVal & kHashMask;
}

const int kNumBuckets = 5;



LinkedHashMap::LinkedHashMap() {

}
	
void LinkedHashMap::put(string key, int value) {
}

bool LinkedHashMap::containsKey(string key) {
	return false;
}

int LinkedHashMap::get(string key) {
	return -1;
}

void LinkedHashMap::remove(string key) {
}

void LinkedHashMap::resetKeyIterator() {
}

bool LinkedHashMap::hasNextKey() {
	return false;
}

string LinkedHashMap::nextKey() {
	return "";
}

int LinkedHashMap::size() {
	return -1;
}

