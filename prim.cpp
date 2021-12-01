#include<iostream>
#include<vector>

using namespace std;
#define V 1000

bool createsMST(int u, int v, vector<bool> inMST) {
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}

void printMinSpanningTree(int cost[][V]) {
    vector<bool> inMST(V, false);
    inMST[0] = true;
    int a, b;
    int edgeNo = 0, MSTcost = 0;
    while (edgeNo < V - 1) {
        int min = INT8_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (cost[i][j] < min) {
                    if (createsMST(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            MSTcost += min;
            inMST[b] = inMST[a] = true;
        }
    }
    cout << MSTcost << endl;
}
int main() {
    int m, n, u, v, w;
    cin >> m >> n;
    int cost[V][V];
    for (int counter1 = 0; counter1 < m; counter1++)
    {
        cin >> u >> v >> w;
        cost[u][v] = w;
    }
    printMinSpanningTree(cost);
    return 0;
}
