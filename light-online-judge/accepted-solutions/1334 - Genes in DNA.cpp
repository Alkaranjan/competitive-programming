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
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 50111

int n, m, pre[maxN], suf[maxN], f[maxN], g[maxN];
char a[maxN], b[maxN];

void cal(int *cnt) {
	f[0] = f[1] = 0;
	fr(i, 2, m - 1) {
		for (int j = f[i - 1]; ; ) {
			if (b[i - 1] == b[j]) { f[i] = j + 1; break; }
			if (j == 0) { f[i] = 0; break; }
			j = f[j];
		}
	}
	g[0] = 0; g[1] = 1;
	fr(i, 2, m - 1) g[i] = g[f[i]] + 1;
	rep(i, n) cnt[i] = 0;
	for (int j = 0, i = 0; j < n; ) {
		if (a[j] == b[i]) {
			cnt[j++] = g[++i];
			if (i == m - 1) i = f[i];
		}
		else if (i > 0) i = f[i];
		else j++;
	}
}

int64 solve() {
	cal(pre);
	reverse(a, a + n); reverse(b, b + m);
	cal(suf);
	int64 res = 0;
	rep(i, n - 1) res += pre[i] * (int64)suf[n - i - 2];
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %s %s ", a, b);
		n = strlen(a); m = strlen(b);
		printf("Case %d: %lld\n", ++caseNo, solve());
	}
	return 0;
}
