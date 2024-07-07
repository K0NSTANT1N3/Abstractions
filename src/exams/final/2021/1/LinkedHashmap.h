
#ifndef LinkedHashMap_Included
#define LinkedHashMap_Included

#include <iostream>
using namespace std;

class LinkedHashMap {

public:
	LinkedHashMap();
	
	void put(string key, int value);
	bool containsKey(string key);
	int get(string key);
	void remove(string key);
	
	void resetKeyIterator();
	bool hasNextKey();
	string nextKey();

	int size();

private:

};
#endif;