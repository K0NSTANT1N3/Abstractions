#include "shortest_path.h"
#include "queue.h"
#include "set.h"
#include "grid.h"


int getShortestPath(Grid<int> &table) {
    Queue<coordT> yellow;
    Set<coordT> green;
    Map<coordT, int> distances;

    coordT startCoord(0, 0);
    coordT endCoord(table.numRows(), table.numCols());

    yellow.enqueue(startCoord);
    distances.put(startCoord, 0);

    int directRow[] = {0, 1, -1};
    int directCol[] = {1, 0, 0};

    while (!yellow.isEmpty()) {
        coordT cur = yellow.dequeue();
        if (green.contains(cur))continue;
        if (cur == endCoord) {
            return distances[cur];
        }
        green.insert(cur);

        for (int i = 0; i < 3; i++) {
            int newX = cur.row + directRow[i];
            int newY = cur.col + directCol[i];
            if (!table.inBounds(newX, newY)) continue;

            coordT newCoord(newX, newY);

            if (green.contains(newCoord))continue;
            yellow.enqueue(newCoord);
        }
    }
}
