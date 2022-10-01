/*
Problem: You have to find the maximum sum of digits of integers between l and r inclusive.
*/

#include<bits/stdc++.h>
using namespace std;

int dp[2][2][21];
vector<int> v1(21), v2(21);

// Time Complexity: O(length of digits)
// Space Complexity: O(length of digits)
int DDP(int f1, int f2, int ind) {
	if (ind == 21)
		return 0;
	if (dp[f1][f2][ind] != -1)
		return dp[f1][f2][ind];
	int &res = dp[f1][f2][ind] = 0;
	int l = 0, r = 9;
	if (f1 && f2 && v1[ind] == v2[ind]) {
		res = DDP(1, 1, ind + 1);
		res += v1[ind];
		return res;
	}
	if (f1) {
		res = max(res, v1[ind] + DDP(1, 0, ind + 1));
		l = v1[ind] + 1;
	}
	if (f2) {
		res = max(res, v2[ind] + DDP(0, 1, ind + 1));
		r = v2[ind] - 1;
	}
	for (int i = l; i <= r; i++)
		res = max(res, i + DDP(0, 0, ind + 1));
	return res;
}

int main() {

	int l, r;
	cin >> l >> r;
	int x = 20;
	while (x >= 0) {
		v1[x] = l % 10;
		v2[x] = r % 10;
		l /= 10, r /= 10;
		x--;
	}
	memset(dp, -1, sizeof(dp));
	DDP(1, 1, 0);
	cout << dp[1][1][0] << "\n";

	return 0;
}