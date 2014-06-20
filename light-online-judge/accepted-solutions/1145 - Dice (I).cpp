//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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
#define maxN 15001
#define mod 100000007

int n, k, m;
int f1[maxN], f2[maxN], sum[maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &k, &m); m++;
		rep(i, m) f2[i] = 0;
		fr(i, 1, k) f2[i] = 1;
		rep(_, n - 1) {
			rep(i, m) {
				f1[i]= f2[i], f2[i] = 0;
				if (!i) sum[i] = 0;
				else sum[i] = (sum[i - 1] + f1[i]) % mod;
			}
			rep(i, m) {
				f2[i] = 0;
				if (i - 1 >= 0) f2[i] += sum[i - 1];
				if (i - k - 1 >= 0) f2[i] -= sum[i - k - 1];
				f2[i] = (f2[i] + mod) % mod;
			}
		}
		printf("Case %d: %d\n", ++caseNo, f2[m - 1] % mod);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet