/*
                                    Convex-Hull trick
                    Problem: https://codeforces.com/contest/319/problem/C
        This trick is applied when transitions is of the form:
            dp[i] = min(dp[i], dp[j] + b[j] * a[i]),  0 <= j <= i.
        conditions:
            b[j] <= b[j+1], 0 <= j < n-1.
            b[j] >= b[j+1], 0 <= j < n-1.
*/

#include<bits/stdc++.h>
using namespace std;

deque<int> dq;
vector<long long> a, b dp;

// Dynammic Programming
// Time Complexity: O(n*n)
// Space Complexity: O(n)
// dp[i] stores the minimum cost to cut tree i completely.
void fun1(int n) {
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = LLONG_MAX;
		for (int j = 0; j < i; j++)
			dp[i] = min(dp[i], dp[j] + b[j] * a[i]);
	}
}

ll eval(int idx, int x) {
	return dp[idx] + b[idx] * x;
}

long double intersectX(int idx1, int idx2) {
	ll m1 = b[idx1], c1 = dp[idx1];
	ll m2 = b[idx2], c2 = dp[idx2];
	long double ret = -(c1 - c2);
	ret /= (m1 - m2);
	return ret;
}

ll query(int x) {
	while ((int)dq.size() > 1 && eval(dq[0], x) > eval(dq[1], x))
		dq.pop_front();
	return eval(dq[0], x);
}

void update(int idx) {
	while ((int)dq.size() > 1 && intersectX(dq[(int)dq.size() - 1], idx) > intersectX(dq[(int)dq.size() - 1], dq[(int)dq.size() - 2]))
		dq.pop_back();
	dq.push_back(idx);
}

// Dynammic Programming Optimisation - Convex-Hull Trick.
// Time Complexity: O(n)
// Space Complexity: O(n)
// dp[i] stores the minimum cost to cut tree i completely.
void fun2(int n) {
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = query(a[i]);
		update(i);
	}
}

int main() {

	int n;
	cin >> n;
	a = b = dp = vector<long long>(n);
	for (auto & i : a)
		cin >> i;
	for (auto & i : b)
		cin >> i;

	return 0;
}