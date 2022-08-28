/* Problem: Micro is having a graph containing N vertices and M edges, each edge is
having an associated weight. If the graph contains Hamiltonian Paths (path that visits
all the vertices exactly once), return the minimum cost of any hamiltonian path. else
return -1. */

#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^2*2^n)
// Space Complexity : O(n*2^n)
// dp[i][j] stores the minimum cost of path visiting cities corresponding to every set
// bits j ending at i.
void hamiltonianCycle(int n, vector<vector<int>> &cost) {
	vector<vector<int>> dp(n, vector<int>(1 << n, 1e9));
	for (int i = 0; i < n; i++)
		dp[i][(1 << i)] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))
				continue;
			int &res = dp[i][mask | (1 << i)];
			for (int j = 0; j < n; j++) {
				if (mask & (1 << j))
					res = min(res, dp[j][mask] + cost[j][i]);
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
		ans = min(ans, dp[i][(1 << n) - 1]);
	if (ans == 1e9)
		ans = -1;
	cout << ans << "\n";
}

int main() {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> cost(n, vector<int>(n, 1e9));
	for (int i = 0; i < n; i++)
		cost[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		cost[x][y] = cost[y][x] = min(z, cost[x][y]);
	}

	hamiltonianCycle(n, cost);

	return 0;
}