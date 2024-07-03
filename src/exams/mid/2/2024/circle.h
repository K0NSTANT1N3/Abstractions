#ifndef MY_STRING_INCL
#define MY_STRING_INCL
#include <cstdio>

using namespace std;

class Circle {
public:
	Circle();
	int length();
	void insert(int pos, int v);
	int get(int pos);
	void set(int pos, int v);
	Circle* subCircle(int start, int end);
	int contains(Circle* c);

private:
	int logLength;
	struct Node {
		int v;
		Node* next;

		Node() {
			v = 0;
			next = NULL;
		}

		Node(int v, Node* next) {
			this->v = v;
			this->next = next;
		}
	};

	Node* head;


};
#endif