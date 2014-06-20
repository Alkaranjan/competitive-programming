//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1031 - Easy Game 
// Time Limit   : .000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 111

int n, sum[maxN], a[maxN], f[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases = 0, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		sum[0] = a[0] = 0;
		fr(i, 1, n) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
			f[i][i] = a[i];
		}
		fr(len, 2, n)
			for (int i = 1, j = len; j <= n; i++, j++) {
				int tmpSum = sum[j] - sum[i - 1];
				f[i][j] = tmpSum;
				fr(k, i, j) {
					if (k != j) f[i][j] = max(f[i][j], tmpSum - f[i][k]);
					if (k != i) f[i][j] = max(f[i][j], tmpSum - f[k][j]);
				}
			}
		printf("Case %d: %d\n", ++caseNo, 2 * f[1][n] - sum[n]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet