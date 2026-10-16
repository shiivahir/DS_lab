//
//  main.cpp
//  practical_9
//
//  Created by apexpredator on 16/10/26.
//

#include <iostream>
#include <queue>
using namespace std;

int graph[20][20];
int visited[20];
int n;

void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Invalid number of vertices." << endl;
        return 1;
    }

    cout << "Enter adjacency matrix (0 or 1):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "\nDFS Traversal: ";
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    cout << endl;
    return 0;
}
