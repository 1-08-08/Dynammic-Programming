/* Problem : Given a fixed array A of 2^N integers, we need to calculate ∀ x function
F(x) = Sum of all A[i] such that x&i = i, i.e., i is a subset of x. */

#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(4^n)
// Space Complexity : O(2^n)
// dp[i] stores the value for F(i).
void SOS1(int n, vector<int> &v) {
	vector<int> dp(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			if ((i & j) == j)
				dp[i] += v[j];
		}
	}
}

// Time Complexity : O(3^n)
// Space Complexity : O(2^n)
// dp[i] stores the value for F(i).
void SOS2(int n, vector<int> &v) {
	vector<int> dp(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		dp[i] = v[0];
		for (int j = i; j > 0; j = (j - 1)&i)
			dp[i] += v[j];
	}
}

// Time Complexity : O(n*2^n)
// Space Complexity : O(2^n)
// dp[i] stores the value for F(i).
void SOS3(int n, vector<int> &v) {
	vector<int> dp(1 << n);
	for (int i = 0; i < (1 << n); i++)
		dp[i] = v[i];

	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < (1 << n); mask++)
			if (mask & (1 << i))
				dp[mask] += dp[mask ^ (1 << i)];
	}
}

int main() {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < (1 << n); i++)
		cin >> v[i];

	return 0;
}