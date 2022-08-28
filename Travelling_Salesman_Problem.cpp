/* Problem : Given a matrix cost of size n where cost[i][j] denotes the
cost of moving from city i to city j. Your task is to complete a tour from
the city 0 (0 based index) to all other cities such that you visit each
city atmost once and then at the end come back to city 0 in min cost. */

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^2*2^n)
// Space Complexity : O(n*2^n)
// dp[i][j] stores the minimum cost to reach every set bit of j
// starting from 0 end to i.
void TSP(int n, vector<vector<int>> &cost) {
	vector<vector<int>> dp(1 << n, vector<int>(n, 1e9));
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))
				continue;
			int &x = dp[mask | (1 << i)][i];
			for (int j = 0; j < n; j++)
				x = min(x, dp[mask][j] + cost[j][i]);
		}
	}
	cout << dp[msk][0] << "\n";
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> cost(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	}

	TSP(n, cost);

	return 0;
}