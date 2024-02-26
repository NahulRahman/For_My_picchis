#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,W;
    cin>>W>>n;
    int cost[n];
    for(int i=0; i<n; ++i){
        cin>>cost[i];
    }
    sort(cost,cost+n);
    int res=0;
    for(int i=n-1; i>=max(n-W,0); --i){
        res+=cost[i];
    }
    cout<<res;
    return 0;
}
/*
Vasya is going to hike with fellow programmers and decided to take a responsible approach to the choice of what he will take with him. Vasya has n things that he could take with him in his knapsack. Every thing weighs 1 kilogram. Things have different "usefulness" for Vasya.

The hiking is going to be very long, so Vasya would like to carry a knapsack of weight no more than w kilo.

Help him to determine the total "usefulness" of things in his knapsack if the weight of backpack can be no more than w kilo.

Input data
The first line contains integers w и n (1 ≤ w, n ≤ 20). The second line contains n integers c[i] (1 ≤ c[i] ≤ 1000) - the "usefulness" for each thing.

Output data
Print the total "usefulness" of things that Vasya can take with him.

Examples
Input example #1
2 3
1 5 3
Output example #1
8
Input example #2
3 2
3 2
Output example #2
5

Generate the code in c++, make sure to get it accepted.
*/
