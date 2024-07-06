#ifndef COMMON_INCL
#define COMMON_INCL

#include <string>

struct Node {
    int id;
    Node *left;
    Node *right;
};

struct Arc {
    int dist;
    int from;
    int to;

    Arc(int from, int to, int dist){
        this->from = from;
        this->to = to;
        this->dist = dist;
    }

    Arc(const Arc &other){
        this->from = other.from;
        this->to = other.to;
        this->dist = other.dist;
    }



    bool operator<(const Arc &other)const{
        return dist < other.dist || (dist == other.dist && from < other.from) || (dist == other.dist && from == other.from && to < other.to);
    }

    bool operator>(const Arc &other)const{
        return dist > other.dist || (dist == other.dist && from > other.from) || (dist == other.dist && from == other.from && to > other.to);
    }

    bool operator==(const Arc &other)const{
        return dist == other.dist && from == other.from && to == other.to;
    }
};

#endif