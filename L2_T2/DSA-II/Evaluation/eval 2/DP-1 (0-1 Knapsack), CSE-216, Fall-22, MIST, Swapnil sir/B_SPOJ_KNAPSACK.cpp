#include <iostream>
#include <vector>
using namespace std;

int knapsack(int S, int N, vector<int>& size, vector<int>& value) {
    vector<vector<int> > dp(N + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            if (size[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - size[i - 1]] + value[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][S];
}

int main() {
    int S, N;
    cin >> S >> N;

    vector<int> size(N);
    vector<int> value(N);

    for (int i = 0; i < N; i++) {
        cin >> size[i] >> value[i];
    }

    int result = knapsack(S, N, size, value);
    cout << result << endl;

    return 0;
}
/*
The famous knapsack problem. You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 2000). You also have N (1<= N <= 2000) items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to bring. What is this maximum total value?

Input
On the first line you are given S and N. N lines follow with two integers on each line describing one of your items. The first number is the size of the item and the next is the value of the item.

Output
You should output a single integer on one like - the total maximum value from the best choice of items for your trip.

Example
Input:
4 5
1 8
2 4
3 0
2 5
2 3


Output:
13
*/
