#include "my_string.h"

MyString::MyString() {
    locLength = 0;
    this->head = NULL;
}

MyString::~MyString() {
    while (this->head != NULL) {
        Node *tmp = this->head->next;
        delete this->head;
        head = tmp;
    }
}

int MyString::length() {
    if (this->head == NULL)return 0;
    else return locLength;
}

void MyString::insert(int pos, char c) {
    if (locLength == 0) {
        if (pos != 0)return;
        this->head = new Node(c, NULL);
        locLength++;
        return;
    }
    if (pos > locLength)return;

    if (pos == 0) {
        Node *newNode = new Node(c, this->head);
        head = newNode;
        locLength++;
        return;
    }

    Node *itr = this->head;
    for (; pos > 1; itr = itr->next, pos--) {}
    Node *newNode = new Node(c, itr->next);
    itr->next = newNode;
    locLength++;
}

char MyString::get(int indx) {
    Node *itr = this->head;
    for (; indx > 0; itr = itr->next, indx--) {}
    return itr->val;
}

void MyString::set(int pos, char c) {
    if (pos >= locLength)return;

    Node *itr = this->head;
    for (; pos > 0; itr = itr->next, pos--) {}
    itr->val = c;
}

MyString *MyString::substr(int start, int len) {
    if (start + len > locLength)return NULL;
    if (start < 0 || len < 0)return NULL;

    MyString *str = new MyString();
    if (len == 0)return str;

    Node *itr = this->head;
    for (; start > 0; itr = itr->next, start--) {}

    for (int i = 0; i < len; i++) {
        if (itr == NULL)break;
        str->insert(i, itr->val);
        itr = itr->next;
    }

    return str;
}

int MyString::find(MyString *s) {
    int index = -1;
    for(int i = 0; i <= locLength - s->locLength; i++){
        if(this->get(i) == s->get(0)){
            index = i;
            for(int j = 0; j < s->locLength; j++){
                if(this->get(i + j) != s->get(j)){
                    index = -1;
                    break;
                }
            }
        }
    }
    return index;
}
