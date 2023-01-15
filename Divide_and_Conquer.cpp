
/*
                                  Divide and Conquer
                   Problem: https://codeforces.com/contest/321/problem/E
        This trick is applied when transition is of the form
            dp[i][j] = dp[i-1][k]+cost[k][j], 1 <= k <= j.
        Conditions:
            opt[i][j] <= opt[i][j+1]
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> cost;
vector<int> dp_prev, dp_cur;

// Dynammic Programming
// Time Complexity: O(k*n*n)
// Space Complexity: O(n)
void fun1(int n, int K) {
	for (int i = 1; i <= n; i++)
		dp_prev[i] = cost[i][1];

	for (int k = 1; k < K; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++)
				dp_cur[i] = min(dp_cur[i], dp_prev[j - 1] + cost[j][i]);
		}
		dp_prev = dp_cur;
		dp_cur = vector<int>(n + 1, INT_MAX);
	}

	cout << dp_prev[n] << "\n";
}

void dnc(int l, int r, int optl, int optr) {
	if (l > r)
		return;
	int mid = (l + r) >> 1;
	pair<int, int> bst = {INT_MAX, -1};
	for (int i = optl; i <= min(mid, optr); i++) {
		int cst = (cost[mid][mid] + cost[i - 1][i - 1] - cost[i - 1][mid] - cost[mid][i - 1]) / 2;
		bst = min(bst, {dp_prev[i - 1] + cst, i});
	}
	dp_cur[mid] = bst.first;
	dnc(l, mid - 1, optl, bst.second);
	dnc(mid + 1, r, bst.second, optr);
}

// Dynammic Programming Optimisation - Divide and Conquer
// Time Complexity: O(k*n*logn)
// Space Complexity: O(n)
void fun2(int n, int k) {
	for (int i = 1; i <= n; i++)
		dp_prev[i] = cost[i][1];

	for (int i = 1; i < k; i++) {
		dnc(1, n, 1, n);
		dp_prev = dp_cur;
	}

	cout << dp_prev[n] << "\n";
}

int main() {

	int n, k;
	cin >> n >> k;
	dp_prev = dp_cur = vector<int>(n + 1);
	cost = vector<vector<int>>(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> cost[i][j];
	}

	return 0;
}