#include<bits/stdc++.h>
using namespace std;

int dp[2005][2005];
int c, n;
int p[2005],w[2005];

int knapsack(int i, int j)
{
    if(i<0 || j<=0) return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    int v1 = knapsack(i-1,j), v2=-1;
    if(w[i]<=j) v2 = p[i] + knapsack(i-1,j-w[i]);
    return dp[i][j] = max(v1, v2);
}

int main()
{
    cin>>c>>n;
    for(int i=0; i<n; i++)  cin>>w[i]>>p[i];
    for(int i=0; i<2005; i++)
        for(int j=0; j<2005; j++)
            dp[i][j] =  -1;

    cout<<knapsack(n-1,c)<<endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=c; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
4 5
1 8
2 4
3 0
2 5
2 3

-1  8  8 -1  8
-1  8  8 -1 12
-1 -1  8 -1 12
-1 -1  8 -1 13
-1 -1 -1 -1 13
-1 -1 -1 -1 -1
*/
