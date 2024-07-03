#include <string>

using namespace std;

class PrQueue {
public:
	PrQueue();
	void enqueue(int k, int pr);
	int dequeue();
	int peek();
	int size();
	void resetIterator();
	bool hasNext();
	void next(int &next, int &pr);
private:

};