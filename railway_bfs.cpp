#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

// Breadth-First Search (BFS) for exploring railway stations.
void BFS(const unordered_map<string, vector<string>>& railwayNetwork,
         const string& startStation) {
    if (railwayNetwork.find(startStation) == railwayNetwork.end()) {
        cout << "Starting station not found in the railway network.\n";
        return;
    }

    queue<string> stationsQueue;
    unordered_map<string, bool> visited;

    visited[startStation] = true;
    stationsQueue.push(startStation);

    cout << "BFS exploration order: ";

    while (!stationsQueue.empty()) {
        string currentStation = stationsQueue.front();
        stationsQueue.pop();

        cout << currentStation;

        if (!stationsQueue.empty()) {
            cout << " -> ";
        }

        auto neighbours = railwayNetwork.find(currentStation);
        if (neighbours != railwayNetwork.end()) {
            for (const string& nextStation : neighbours->second) {
                if (!visited[nextStation]) {
                    visited[nextStation] = true;
                    stationsQueue.push(nextStation);
                }
            }
        }
    }

    cout << '\n';
}

int main() {
    unordered_map<string, vector<string>> railwayNetwork;
    int connections;

    cout << "Enter the number of train connections: ";
    cin >> connections;

    if (connections < 0) {
        cout << "Number of connections cannot be negative.\n";
        return 1;
    }

    cout << "Enter each connection as: Station1 Station2\n";
    cout << "Example: Mumbai Pune\n";

    for (int i = 0; i < connections; ++i) {
        string station1, station2;
        cin >> station1 >> station2;

        // Treat each connection as bidirectional.
        railwayNetwork[station1].push_back(station2);
        railwayNetwork[station2].push_back(station1);
    }

    string startStation;
    cout << "Enter the starting station: ";
    cin >> startStation;

    BFS(railwayNetwork, startStation);

    return 0;
}
