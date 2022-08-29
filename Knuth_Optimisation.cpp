/* Problem : https://www.spoj.com/problems/BRKSTRNG/ */

/*
Conditions : speedup is applied for transitions of the form
       dp[i][j] = min(dp[i][k]+dp[k][j]+cost(i,j)) for all k from i to j.
    1.    opt[i][j-1] <= opt[i][j] <= opt[i+1][j]
                    OR
    2.      for a <= b <= c <= d.
          cost(a,d) <= cost(b,c) && cost(a,c)+cost(b,d) <= cost(a,d)+cost(b,c)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp, opt, cost;

int cost(int l, int r) {
    int ret;
    // calculate cost for l,r.
    return ret;
}

// Bruteforce
// Time Complexity : O(n!)
// Space Complexity : O(n)
int fun1(int l, int n, vector<int> &v) {
    vector<int> v1(n);
    iota(v1.begin(), v1.end(), 0);
    int res = INT_MAX, temp;
    do {
        temp = 0;
        map<int, int> mp;
        mp[0] = mp[l] = 1;
        for (auto i : v1) {
            auto it1 = mp1.lower_bound(v[i]);
            it1--;
            auto it2 = mp1.lower_bound(v[i]);
            temp += (it2->first - it1->first);
        }
        res = min(res, temp);
    } while (next_permutation(v1.begin(), v1.end()));
    cout << res << "\n";
}

// Dynammic Programming
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)
// dp[l][r] stores the minimum cost for index from l upto r.
void fun2(int l, int r) {
    if (dp[l][r] != -1)
        return;
    if ((r - l) < 2) {
        dp[l][r] = 0;
        return;
    }
    fun2(l, r - 1);
    fun2(l + 1, r);
    dp[l][r] = 1e9;
    for (int i = l; i <= r; i++) {
        dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r] + cost(l, r));
    }
}

// Dynammic Programming Optimization - Knuth Optimization
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
// dp[l][r] stores the minimum cost for index from l upto r.
void fun3(int l, int r)
{
    if (dp[l][r] != -1)
        return;
    if (r - l < 2)
    {
        dp[l][r] = 0;
        opt[l][r] = l;
        return;
    }
    fun3(l, r - 1);
    fun3(l + 1, r);
    dp[l][r] = 1e9;
    for (int i = opt[l][r - 1]; i <= opt[l + 1][r]; i++)
    {
        if (dp[l][r] > dp[l][i] + dp[i][r] + cost(l, r))
        {
            dp[l][r] = dp[l][i] + dp[i][r] + cost(l, r);
            opt[l][r] = i;
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int length, n;
    cin >> length >> n;
    vector<int> v(n + 2);
    v[0] = 0;
    v[n + 1] = l;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    dp = opt = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));
    // fun2(0,n+1);
    // fun3(0,n+1);

    //cout<<dp[0][n+1]<<"\n";

    return 0;
}