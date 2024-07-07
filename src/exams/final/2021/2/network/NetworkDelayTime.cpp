#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

#include<queue>

map<int, vector<vector<int>>> vecToMap(vector<vector<int>> &times, int n) {
    map<int, vector<vector<int>>> graph;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> nbr;
        graph.insert({i, nbr});
    }

    for (int i = 0; i < times.size(); i++) {
        graph[times[i][0]].push_back(times[i]);
    }

    return graph;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    map<int, vector<vector<int>>> graph = vecToMap(times, n);
    bool green[n + 1];
    for (int i = 1; i <= n; i++) {
        green[i] = false;
    }
    map<int, int> dist;
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    using PII = pair<int, int>; // (distance, node)
    priority_queue<PII, vector<PII>, greater<PII>> yellows;
    yellows.push({0, k});

    green[k] = true;
    dist[k] = 0;

    int mx = 0;
    while (!yellows.empty()) {
        auto[d, u] = yellows.top();
        yellows.pop();

        if (green[u]) continue;
        green[u] = true;

        for (auto &edge: graph[u]) {
            int to = edge[1];
            int time = edge[2];

            if (green[to]) continue;

            if (dist[to] > time + d) {
                dist[to] = time + d;
                mx = dist[to] > mx ? dist[to] : mx;
                yellows.push({time + d, to});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)return -1;
    }
    return mx;
}


int main() {
    vector<vector<int>> times = {{2, 1, 1},
                                 {2, 3, 1},
                                 {3, 4, 1}};
    int n = 4;
    int k = 2;

    int result = networkDelayTime(times, n, k);
    cout << "The network delay time is: " << result << endl;

    return 0;
}
