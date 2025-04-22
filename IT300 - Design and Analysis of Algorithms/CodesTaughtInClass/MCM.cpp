#include <vector>
#include <climits>
#include <iostream>
using namespace std;
// Helper function to print the optimal parenthesization
void printOptimalParens(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << i+1;
        return;
    }
    cout << "(";
    printOptimalParens(split, i, split[i][j]);
    printOptimalParens(split, split[i][j] + 1, j);
    cout << ")";
}
// Function to perform matrix chain multiplication
void matrixChainMultiplication(const vector<int>& dims) {
    int n = dims.size() - 1;  // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> split(n, vector<int>(n, 0));  // To store split points

    // Initialize the diagonal of dp table with 0s (single matrix case)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill the dp table
    for (int len = 2; len <= n; len++) {  // Chain length
        for (int i = 0; i < n - len + 1; i++) {  // Starting matrix
            int j = i + len - 1;  // Ending matrix
            dp[i][j] = INT_MAX;
            
            // Try all possible split points between i and j
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + 
                          dims[i] * dims[k + 1] * dims[j + 1];
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;  // Store the optimal split point
                }
            }
        }
    }

    // Print the DP table
    cout << "\nDP Table:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                cout << "0\t";
            else
                cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMinimum number of multiplications: " << dp[0][n-1] << endl;

    // Optional: Print the optimal parenthesization
    cout << "\nOptimal Parenthesization: ";
    printOptimalParens(split, 0, n-1);
    cout << endl;
}



// Example usage
int main() {
    vector<int> dims = {10, 30, 5, 60, 10, 20, 5};
    cout << "Matrix dimensions: ";
    for (int i = 0; i < dims.size() - 1; i++) {
        cout << dims[i] << "x" << dims[i+1] << " ";
    }
    cout << endl;

    matrixChainMultiplication(dims);
    return 0;
}