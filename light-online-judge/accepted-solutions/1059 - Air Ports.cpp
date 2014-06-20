//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1059 - Air Ports 
// Time Limit   : 2.000s
// Description  : MST - graph
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
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, ii> iii;

int n, m, lab[maxN], airpCost;
vector<iii> edges;

int getRoot(int v) {
    if (lab[v] < 0) return v;
    lab[v] = getRoot(lab[v]);
    return lab[v];
}

void unionTree(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (r1 > r2) {
        lab[r1] = r2;
        lab[r2] = x;
    }
    else {
        lab[r1] = x;
        lab[r2] = r1;
    }
}

ii kruskal() {
    sort(all(edges));
    FOR (i, 1, n) lab[i] = -1;
    int res = 0, counter = 0;
    REP(i, edges.size()) {
        int u = getRoot(edges[i].ss.ff), v = getRoot(edges[i].ss.ss);
        if (u != v) {
            if (edges[i].ff < airpCost)
                res += edges[i].ff;
            else break;
            if (++counter == n - 1) break;
            unionTree(u, v);
        }
    }
    return ii(res + (n - counter) * airpCost, n - counter);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, u, v, w;
    scanf("%d", &caseNo);
    while (caseNo--) {
        edges.clear();
        scanf("%d %d %d", &n, &m, &airpCost);
        REP(i, m) {
            scanf("%d %d %d", &u, &v, &w);
            edges.pb(iii(w, ii(u, v)));
        }
        ii res = kruskal();
        printf("Case %d: %d %d\n", ++cases, res.ff, res.ss);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
