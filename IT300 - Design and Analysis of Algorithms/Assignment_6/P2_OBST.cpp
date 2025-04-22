#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> root;
vector<vector<double>> cost;
vector<vector<double>> weight;

void printStructure(int i, int j, const string& relation, int parent) {
    if (i < j) {
        int r = root[i][j];
        if (relation == "root") {
            cout << "k" << r - 1 << " is the root" << endl;
        } else {
            cout << "k" << r - 1 << " is the " << relation << " child of k" << parent - 1 << endl;
        }
        printStructure(i, r - 1, "left", r);
        printStructure(r, j, "right", r);
    } else if (i == j) {
        cout << "d" << i << " is the " << relation << " child of k" << parent - 1 << endl;
    }
}


double getWeight(int i, int j, const vector<double>& p, const vector<double>& q) {
    if (i == j) return q[i];
    if (weight[i][j] != -1) return weight[i][j];
    
    weight[i][j] = getWeight(i, j-1, p, q) + p[j-1] + q[j];
    return weight[i][j];
}


double optimalBSTRec(int i, int j, const vector<double>& p, const vector<double>& q) {
    
    if (i == j) {
        root[i][j] = i;
        return q[i];
    }
    
    if (cost[i][j] != -1) return cost[i][j];

    double w = getWeight(i, j, p, q);
    double minCost = 1e9;
    int minRoot = i + 1;
    
    for (int r = i + 1; r <= j; r++) {
        double leftCost = (r - 1 >= i) ? optimalBSTRec(i, r - 1, p, q) : 0;
        double rightCost = (r <= j) ? optimalBSTRec(r, j, p, q) : 0;
        double totalCost = leftCost + rightCost + w;
        
        if (totalCost < minCost) {
            minCost = totalCost;
            minRoot = r;
        }
    }

    root[i][j] = minRoot;
    cost[i][j] = minCost;
    return minCost;
}

void optimalBST(const vector<double>& p, const vector<double>& q, int n) {
    
    cost = vector<vector<double>>(n + 1, vector<double>(n + 1, -1));
    root = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    weight = vector<vector<double>>(n + 1, vector<double>(n + 1, -1));
    
    for (int i = 0; i <= n; i++) {
        cost[i][i] = q[i];
        weight[i][i] = q[i];
    }
    
    double optimalCost = optimalBSTRec(0, n, p, q);
    
    cout << "The structure of the optimal BST is:" << endl;
    printStructure(0, n, "root", -1);
    cout << "Optimal cost: " << optimalCost << endl;
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    vector<double> p(n), q(n + 1);
    
    cout << "Enter the probabilities for keys (p[]): ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Enter the probabilities for dummy nodes (q[]): ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    optimalBST(p, q, n);
    return 0;
}