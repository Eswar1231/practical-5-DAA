#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int wt[100], val[100];
    int dp[101][101];
    int selected[100];

    cout << "Enter weights of " << n << " items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values of " << n << " items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    // Dynamic Programming
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    dp[i - 1][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]
                );

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Find selected items
    int w = W;

    for (int i = n - 1; i >= 0; i--) {
        if (dp[i + 1][w] != dp[i][w]) {
            selected[i] = 1;
            w -= wt[i];
        }
        else {
            selected[i] = 0;
        }
    }

    cout << "\nMaximum Profit: " << dp[n][W] << endl;

    cout << "Selected Items: ";
    for (int i = 0; i < n; i++)
        cout << selected[i] << " ";

    cout << endl;

    return 0;
}
