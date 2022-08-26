/* Problem: During midnight, a thief breaks into a jewelry shop. There are N
priceful items whose value and weight are known. The item p can be sold for Vp
money but having Cp weight. There is a bag with infinity amount of space, means
that any item can be put into it while the item's weight in the bag remains less
than W.
Question: What is the value V that the thief can steal from the shop. */


#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(N!)
// Space Complexity : O(N)
// for every permutation, start from first index and go on till current weight is
// less than capacity of knapsack and return the maximum cost as answer.
void Knapsack1(int N, int W, vector<pair<int, int>> &vec) {
	int res = 0;
	vector<int> v(N);
	iota(v.begin(), v.end(), 0);
	do {
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < N; i++) {
			temp2 += vec[i].second;
			temp1 += vec[i].first;
			if (temp2 > W)
				break;
			res = max(res, temp1);
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << res << "\n";
}

// Time Complexity : O(2^N)
// Space Complexity : O(N)
// for every subset of N, calculate its W and cost and if weight is less
// than capacity of knapsack ,take the maximum of such cost and return it.
void Knapsack2(int N, int W, vector<pair<int, int>> &vec) {
	int res = 0;
	for (int mask = 0; mask < (1 << N); mask++) {
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < N; i++) {
			if (mask & (1 << i))
				temp2 += vec[i].second, temp1 += vec[i].first;
		}
		if (temp2 <= W)
			res = max(res, temp1);
	}
	cout << res << "\n";
}

// Time Complexity : O(N*W)
// Space Complexity : O(N*W)
// dp[i][s] stores the maximum cost of items starting from ith index such that
// s + weight of items is less than or equal to capacity of knapsack.
int Knapsack3(int i, int s, int N, int W, vector<pair<int, int>> &vec, vector<vector<int>> &dp) {
	if (s > W)
		return -1e9;
	if (i >= N)
		return 0;
	int &res = dp[i][s];
	if (res != -1)
		return res;
	res = max(res, Knapsack3(i + 1, s, N, W, vec, dp));
	res = max(res, vec[i].first + Knapsack3(i + 1, s + vec[i].second, N, W, vec, dp));
	return res;
}

// Time Complexity : O(N*W)
// Space Complexity : O(N*W)
// dp[i][j] stores the maximum cost of items till ith index such that weight of
// items is less than or equal to j.
void Knapsack4(int N, int W, vector<pair<int, int>> &vec) {
	vector<vector<int>> dp(N + 1, vector<int>(W + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= W; j++) {
			dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - 1]);
			if (j - vec[i].second >= 0)
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - vec[i].second] + vec[i].first);
		}
	}
	cout << dp[N][W] << "\n";
}

// Time Complexity : O(N*W)
// Space Complexity :O(N+2*W)
// since state of dp depends only on the previous dp. i,e, dp[i] depends only
// on dp[i] and dp[i-1]. we can avoid using whole dp matrix.
void Knapsack5(int N, int W, vector<pair<int, int>> &vec) {
	vector<int> prev(W + 1), cur(W + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= W; j++) {
			cur[j] = max(cur[j - 1], prev[j]);
			if (j >= vec[i].second)
				cur[j] = max(cur[j], prev[j - vec[i].second] + vec[i].first);
		}
		swap(prev, cur);
	}
	cout << prev[W] << "\n";
}

// Time Complexity : O(N*W)
// Space Complexity :O(N+W)
// dp[i] stores the maximum cost of items whose weight is less than or equal to i.
void Knapsack6(int N, int W, vector<pair<int, int>> &vec) {
	vector<int> dp(W + 1);
	for (int i = 0; i < N; i++) {
		for (int j = W; j >= vec[i].second; j--)
			dp[j] = max(dp[j], dp[j - vec[i].second] + vec[i].first);
	}
	cout << dp[W] << "\n";
}

int main() {

	int N, w;
	cin >> N >> w;
	vector<pair<int, int>> vec(N);
	for (auto &[x, y] : vec)
		cin >> x >> y;

	return 0;
}