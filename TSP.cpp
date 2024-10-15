#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define INF 999

int n, cost = 0;
vector<vector<int>> costMat;
vector<bool> visited;

void tcp(int city) {
    cout << city + 1 << "-->";
    visited[city] = true;

    int miniCost = INF;
    int nextcity = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && costMat[city][i] && costMat[city][i] < miniCost) {
            miniCost = costMat[city][i];
            nextcity = i;
        }
    }

    if (nextcity == -1) {
        cout << "1"; // Returning to the first city
        cost += costMat[city][0]; // Add cost to return to start
    } else {
        cost += miniCost;
        tcp(nextcity);
    }
}

int main() {
    cout << "\nEnter the total number of cities: ";
    cin >> n;

    // Resize costMat and visited vectors
    costMat.resize(n, vector<int>(n));
    visited.resize(n, false);

    cout << "Enter the cost matrix (use 999 for no path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Cost from city " << i + 1 << " to city " << j + 1 << ": ";
            cin >> costMat[i][j];
        }
    }

    cout << "\nThe minimum path for TCP is: ";
    tcp(0);
    cout << "\nTotal cost: " << cost << endl;

    return 0;
}
