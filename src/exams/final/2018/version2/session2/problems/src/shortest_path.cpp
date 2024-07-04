#include "shortest_path.h"
#include "queue.h"
#include "set.h"
#include "grid.h"

int asc_desc(Grid<int> &table, int growRate) {
    Queue<coordT> yellow;
    Set<coordT> green;
    Map<coordT, int> distances;

    coordT startCoord(0, 0);
    coordT endCoord(table.numRows() - 1, table.numCols() - 1);

    yellow.enqueue(startCoord);
    distances.put(startCoord, 0);

    int directCol[] = {0, 1, -1};
    int directRow[] = {1, 0, 0};

    while (!yellow.isEmpty()) {
        coordT cur = yellow.dequeue();
        if (cur == endCoord) return distances[cur];
        if (green.contains(cur))continue;
        green.insert(cur);

        for (int i = 0; i < 3; i++) {
            int newRow = cur.row + directRow[i];
            int newCol = cur.col + directCol[i];
            if (!table.inBounds(newRow, newCol)) continue;
            if (growRate > 0) {
                if (table[cur.row][cur.col] >= table[newRow][newCol])continue;
            } else if (growRate < 0) {
                if (table[cur.row][cur.col] <= table[newRow][newCol])continue;
            }

            coordT newCoord(newRow, newCol);

            if (green.contains(newCoord))continue;
            yellow.enqueue(newCoord);
            distances.put(newCoord, distances[cur] + 1);
        }
    }
    return -1;
}

int getShortestPath(Grid<int> &table) {
    int ans1 = asc_desc(table, 1);
    int ans2 = asc_desc(table, -1);

    return max(ans1, ans2);
}
