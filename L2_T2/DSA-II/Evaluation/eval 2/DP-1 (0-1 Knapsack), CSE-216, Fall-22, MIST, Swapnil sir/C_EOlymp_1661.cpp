#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;

    vector<int> weight(n);
    vector<int> value(n);

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<int> > dp(n + 1, vector<int>(s + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }

    cout << dp[n][s] << endl;

    return 0;
}
/*
Entering into the cave with treasures, our Aladdin did not take an old blackened lamp. He rushed to collect the gold coins and precious stones into his knapsack. He would, of course, take everything, but miracles do not happen - too much weight the knapsack can not hold.

Many times he laid out one thing and put others in their place, trying to raise the value of the jewels as high as possible.

Determine the maximum value of weight that Aladdin can put in his knapsack.

We will assume that in the cave there are objects of
�
n different types, the number of objects of each type is not limited. The maximum weight that a knapsack can hold is
�
s. Each item of type
�
i has the weight
�
�
w
i
​
  and cost
�
�
(
�
=
1
,
2
,
.
.
.
,
�
)
v
i
​
 (i=1,2,...,n).

Input data
First line contains two integers
�
s and
�
(
1
≤
�
≤
250
,
1
≤
�
≤
35
)
n(1≤s≤250,1≤n≤35) — the maximum possible weight of items in the knapsack and the number of types of items. Each of the next
�
n lines contains two numbers
�
�
w
i
​
  and
�
�
(
1
≤
�
�
≤
250
,
1
≤
�
�
≤
250
)
v
i
​
 (1≤w
i
​
 ≤250,1≤v
i
​
 ≤250) — the weight of item of type
�
i and its cost.

Output data
Print the maximum value of the loading, which weight does not exceed
�
s.

Sample 1
Inputcopy	Outputcopy
10 2
5 10
6 19
20
*/
