#include "circle.h"
#include <iostream>

Circle::Circle() {
	logLength = 0;
	head = NULL;
}

int Circle::length() {
	if (this->head == NULL)return 0;
	return logLength;
}
void Circle::insert(int pos, int v) {
	if (head == NULL) {
		head = new Node(v, head);
		logLength = 1;
		return;
	}

	if (pos == 0) {
		Node* tmp = new Node(v, head);

		Node* itr = head;
		for (int i = 1; i < logLength; i++, itr = itr->next) {}
		itr->next = tmp;
		head = tmp;
		logLength++;
		return;
	}

	Node* itr = head;
	for (int i = 1; i < pos; i++, itr = itr->next) {}

	Node* tmp = new Node(v, itr->next);

	itr->next = tmp;
	logLength++;
}

int Circle::get(int pos) {
	pos %= logLength;

	if (pos == 0 || logLength == 1) {
		return head->v;
	}

	Node* itr = head;
	for (int i = 0; i < pos; i++, itr = itr->next) {}

	return itr->v;
}

void Circle::set(int pos, int v) {
	pos %= logLength;

	if (pos == 0 || logLength == 1) {
		head->v = v;
	}


	Node* itr = head;
	for (int i = 0; i < pos; i++, itr = itr->next) {}

	itr->v = v;
}

Circle* Circle::subCircle(int start, int end) {
	Circle* crc = new Circle();

	if (start >= end) {
		return crc;
	}

	if (logLength == 1) {
		crc->insert(0, this->head->v);
		return crc;
	}

	Node* itr = head;
	for (int i = 0; i < start; i++, itr = itr->next) {}


	for (int i = start; i < end; i++, itr = itr->next) {
		crc->insert(i - start, itr->v);
	}

	return crc;
}


int Circle::contains(Circle* c) {
	if (logLength < c->length())return -1;

	if (logLength == 1) {
		if (this->head->v == c->get(0)) {
			return 0;
		}
		return -1;
	}

	for (int i = 0; i < this->length(); i++) {
		if (this->get(i) == c->get(0)) {//when first symbols match

			bool b = true;
			int ans = i;

			for (int j = 0; j < c->length(); j++, i++) {//iterate c and this->circle
				//chech that each c value to be equal to this->circle value accordingly
				if (this->get(i) != c->get(j)) {
					b = false;
					break;
				}
			}
			if (b)return ans;
		}
	}
	return -1;
}
