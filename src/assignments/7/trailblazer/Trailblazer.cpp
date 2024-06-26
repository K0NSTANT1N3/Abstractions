/******************************************************************************
 * File: Trailblazer.cpp
 *
 * Implementation of the graph algorithms that comprise the Trailblazer
 * assignment.
 */

#include "Trailblazer.h"
#include "TrailblazerGraphics.h"
#include "TrailblazerTypes.h"
#include "TrailblazerPQueue.h"
#include <algorithm>
#include "pqueue.h"
#include "random.h"

using namespace std;

/* Function: shortestPath
 * 
 * Finds the shortest path between the locations given by start and end in the
 * specified world.	 The cost of moving from one edge to the next is specified
 * by the given cost function.	The resulting path is then returned as a
 * Vector<Loc> containing the locations to visit in the order in which they
 * would be visited.	If no path is found, this function should report an
 * error.
 *
 * In Part Two of this assignment, you will need to add an additional parameter
 * to this function that represents the heuristic to use while performing the
 * search.  Make sure to update both this implementation prototype and the
 * function prototype in Trailblazer.h.
 */
Vector<Loc>
shortestPath(Loc start,
             Loc end,
             Grid<double> &world,
             double costFn(Loc from, Loc to, Grid<double> &world),
             double heuristic(Loc start, Loc end, Grid<double> &world)) {

    Vector<Loc> ans;
    if (start == end) {
        ans.push_back(start);
        return ans;
    }

    /* distance from root to current node is saved for each end node as vector from start to parent node */
    map<Loc, pair<double, Loc>> distances;
    /* nodes we know shortest path for sure is saved in set for quick access */
    Set<Loc> greenNodes;
    /* priority queue for nodes we must visit */
    TrailblazerPQueue<Loc> yellowNodes;

    distances[start] = make_pair(0.0, start);
    yellowNodes.enqueue(start, 0);

    int deltaRow[] = {1, 1, 1, -1, -1, -1, 0, 0};
    int deltaCol[] = {1, -1, 0, 1, -1, 0, 1, -1};

    while (!yellowNodes.isEmpty()) {
        Loc cur = yellowNodes.dequeueMin();
        greenNodes.insert(cur);
        colorCell(world, cur, GREEN);

        if (cur == end) {
            Loc itr = end;
            while (true) {
                if (itr == start) {
                    ans.push_back(start);
                    std::reverse(ans.begin(), ans.end());
                    return ans;
                }

                ans.push_back(itr);
                itr = distances[itr].second;
            }
        }

        for (int i = 0; i <= 7; i++) {
            if (!world.inBounds(cur.row + deltaRow[i], cur.col + deltaCol[i]))continue;

            Loc nextNode = makeLoc(cur.row + deltaRow[i], cur.col + deltaCol[i]);
            if (greenNodes.contains(nextNode))continue;

            double distanceFromPrev = distances[cur].first + costFn(cur, nextNode, world)
                                      - heuristic(cur, end, world) + heuristic(nextNode, end, world);

            if (distances.find(nextNode) != distances.end()) { // node is already yellow
                double oldDistance = distances[nextNode].first;
                if (distanceFromPrev < oldDistance) {
                    yellowNodes.decreaseKey(nextNode, distanceFromPrev);
                    distances[nextNode].first = distanceFromPrev;
                    distances[nextNode].second = cur;
                }
            } else { // make node yellow
                distances[nextNode].first = distanceFromPrev;
                distances[nextNode].second = cur;
                yellowNodes.enqueue(nextNode, distanceFromPrev);
                colorCell(world, nextNode, YELLOW);
            }

        }
    }

    error("shortestPath is not implemented yet.");
    return Vector<Loc>();
}

PriorityQueue<Edge> edgesWithRandomLengths(int numRows, int numCols) {
    PriorityQueue<Edge> edges;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i != numRows - 1) {
                Edge edge = makeEdge(makeLoc(i, j), makeLoc(i + 1, j));
                edges.enqueue(edge, randomReal(0, 1));
            }
            if (j != numCols - 1) {
                Edge edge = makeEdge(makeLoc(i, j), makeLoc(i, j + 1));
                edges.enqueue(edge, randomReal(0, 1));
            }
        }
    }
    return edges;
}

Map<Loc, pair<Loc, int>> starterClusterCreator(int numRows, int numCols) {
    Map<Loc, pair<Loc, int>> clusters;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            Loc node = makeLoc(i, j);
            clusters.put(node, {node, 1});
        }
    }
    return clusters;
}

Loc parentOfLoc(Map<Loc, pair<Loc, int>> &clusters, Loc nextLoc) {
    if(clusters[nextLoc].first != nextLoc){
        clusters[nextLoc].first = parentOfLoc(clusters, clusters[nextLoc].first);
    }
    return clusters[nextLoc].first;
}

void unionClusters(Map<Loc, pair<Loc, int>> &clusters, Loc parent, Loc son) {
    if (clusters[parent].second < clusters[son].second) {
        unionClusters(clusters, son, parent);
        return;
    }

    clusters[son].first = parent;
    clusters[parent].second += clusters[son].second;
}


Set<Edge> createMaze(int numRows, int numCols) {
    Set<Edge> tree;
    Map<Loc, pair<Loc, int>> clusters = starterClusterCreator(numRows, numCols);
    PriorityQueue<Edge> edges = edgesWithRandomLengths(numRows, numCols);

    for (int i = numRows * numCols; i > 1 && !edges.isEmpty(); i--) {
        Edge nextEdge = edges.dequeue();
        /* edge connects nodes of same cluster */
        Loc parent1 = parentOfLoc(clusters, nextEdge.start);
        Loc parent2 = parentOfLoc(clusters, nextEdge.end);
        if (parent1 == parent2) {
            i++;
            continue;
        }

        tree.insert(nextEdge);
        unionClusters(clusters, parent1, parent2);
    }

    return tree;
}
