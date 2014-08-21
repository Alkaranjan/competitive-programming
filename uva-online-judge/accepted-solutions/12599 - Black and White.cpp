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
#define maxN 100111

int n;
char s[maxN];

bool solve() {
	if (s[0] == 'W' || s[n - 1] == 'B') return false;
	int id = 0;
	rep(i, n) if (s[i] == 'W') {
		id = i;
		break;
	}
	bool ok = true;
	fr(i, id, n - 1) if (s[i] == 'B') {
		ok = false;
		break;
	}
	if (ok) {
		puts("1");
		printf("%d", n);
		rep(i, n) printf(" %d", i + 1); puts("");
		return true;
	}
	puts("2");
	int cnt = 1;
	fr(i, 1, n - 2) if (s[i] == 'W') cnt++;
	printf("%d %d", cnt, 1);
	fr(i, 1, n - 2) if (s[i] == 'W') printf(" %d", i + 1); puts("");
	printf("%d", n - cnt);
	fr(i, 1, n - 2) if (s[i] == 'B') printf(" %d", i + 1); printf(" %d\n", n);
	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %s ", s); n = strlen(s);
		if (!solve()) puts("IMPOSSIBLE");
	}
	return 0;
}
