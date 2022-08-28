/* Problem : There are N persons and N tasks, each task is to be alloted to
a single person. We are also given a matrix cost of size N*N, where
cost[i][j] denotes, how much person i is going to charge for jth task. Now
we need to assign each task to a person in such a way that the total cost
is minimum. Note that each task is to be alloted to a single person, and
each person will be alloted only one task. */

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n!)
// Space Complexity: O(n)
void btmsk1(int n, vector<vector<int>> &cost) {
	vector<int> per(n);
	iota(per.begin(), per.end(), 0);
	int res = INT_MAX;
	do {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			temp += cost[i][per[i]];
		}
		res = min(res, temp);
	} while (next_permutation(per.begin(), per.end()));
	cout << res << "\n";
}

// Time Complexity: O(n*2^n)
// Space Complexity: O(2^n)
// Let j be the count of set bits in i. dp[i] stores the minimum cost to
// assign first j person to task corresponding to every set bit in i.
void btmsk2(int n, vector<vector<int>> &cost) {
	vector<vector<int>> dp(1 << n, INT_MAX);
	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		int x = __builtin_popcount(mask);
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))
				continue;
			dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + cost[x][i]);
		}
	}
	cout << dp[(1 << n) - 1] << "\n";
}

int main() {

	int n;
	cin >> n;
	vector<vector<int>> cost(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	}

	btmsk(n, cost);

	return 0;
}