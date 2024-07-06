#include <algorithm>
#include <climits>
#include "../common.h"
#include "sec_min_spanning_tree.h"
#include "set.h"

bool sameClusters(int from, int to, map<int, int> &parent) {
    while (parent[from] != from) {
        from = parent[from];
    }

    while (parent[to] != to) {
        to = parent[to];
    }

    return from == to;
}

void mergeClusters(int from, int to, map<int, int> &parent) {
    while (parent[from] != from) {
        from = parent[from];
    }

    while (parent[to] != to) {
        to = parent[to];
    }

    parent[from] = to;
}

Vector<Arc *> minimalSpanningTree(Vector<Arc *> &graph, int n) {
    Vector<Arc *> result;
    map<int, int> parent;
    int clusterNum = n;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(graph.begin(), graph.end(), [](Arc *a, Arc *b) {
        return a->dist < b->dist;
    });

    for (Arc *arc: graph) {
        if (clusterNum == 1) {
            break;
        }
        int from = arc->from;
        int to = arc->to;

        if (sameClusters(from, to, parent)) {
            continue;
        }

        result.push_back(arc);
        clusterNum--;
        mergeClusters(from, to, parent);
    }

    return result;
}

Vector<Arc *> leftOvers(Vector<Arc *> graph, Vector<Arc *> mst) {
    Vector<Arc *> result;
    for (Arc *arc: graph) {
        if (find(mst.begin(), mst.end(), arc) == mst.end()) {
            result.push_back(arc);
        }
    }

    sort(result.begin(), result.end(), [](Arc *a, Arc *b) {
        return a->dist < b->dist;
    });

    return result;
}

int sumOfWeights(Vector<Arc *> &graph) {
    int sum = 0;
    for (Arc *arc: graph) {
        sum += arc->dist;
    }

    return sum;
}

int largestWeight(Vector<Arc *> &graph) {
    int max = -1;
    for (Arc *arc: graph) {
        if (arc->dist > max) {
            max = arc->dist;
        }
    }

    return max;
}

bool findPath(Vector<Arc *> &mst, int from, int to, int notTo, Vector<Arc *> &path) {
    Set<Arc *> yellowEdges;

    for (Arc *a: mst) {
        if ((a->from == from || a->to == from) && a->to != notTo && a->from != notTo) {
            yellowEdges.add(a);
        }
    }

    for (Arc *a: yellowEdges) {
        if (a->from == to || a->to == to) {
            path.push_back(a);
            return true;
        }
        path.push_back(a);
        int newFrom = a->from == from ? a->to : a->from;
        if (findPath(mst, newFrom, to, from, path)) {
            return true;
        }
        path.remove(path.size() - 1);
    }

    return false;
}

int findSecondMinSpanningTree(Vector<Arc *> graph, const int n) {
    Vector<Arc *> mst = minimalSpanningTree(graph, n);
    Vector<Arc *> left = leftOvers(graph, mst);


    int mstLength = 0;
    for (Arc *arc: mst) {
        mstLength += arc->dist;
    }

    int min = INT_MAX;
    for (Arc *arc: left) {
        int from = arc->from;
        int to = arc->to;
        int notTo = to;
        Vector<Arc *> path;


        findPath(mst, from, to, notTo, path);


        int curMin = arc->dist - largestWeight(path);

        if (curMin < min) {
            min = curMin;
        }
    }

    if(min == INT_MAX) {
        return -1;
    }
    return min + mstLength;
}