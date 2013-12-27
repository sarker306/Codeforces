#include <cstdio>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
int n, k;
ll fc[19] = {1}, MOD = 1000000007;
/*
map<int, ll> dp[16][1<<16];

ll rec(int pos, int bMask, int cMask){
	ll res = 0;
	map<int,  ll>::iterator ptr;

	if ( pos == n ) return 1;
	ptr = dp[pos][bMask].find(cMask);
	if ( ptr != dp[pos][bMask].end() ) return dp[pos][bMask][cMask];

	for ( int i = 0 ; i < n ; i++ ){
		if ( bMask & ( 1 << i ) ) continue;
		int now = (i + pos) % n;
		if ( cMask & (1<<now) ) continue;
		res += rec(pos + 1, bMask | (1<<i), cMask | (1<<now)) % MOD;
	}

	return dp[pos][bMask][cMask] = res;
}
*/
unsigned ans[]={0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};

int main(){
	ll tmp;
	
	for ( int i = 1 ; i < 16 ; i++ ){
		ll res = fc[i-1] * i;
		fc[i] = res % MOD;
	}
	
	while(scanf("%d", &n)==1){
		/*tmp = rec(0,0,0);
		printf("%lld\n", (tmp * fc[n])%MOD);*/
		printf("%lu\n", ans[n]);
	}
	
	return 0;
}
/*{0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,158820900,0,142610590,0};*/
