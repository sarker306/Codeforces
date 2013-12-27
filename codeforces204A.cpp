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
#include <stack>
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

char limit[25];

ll dp[20][2][10][10], a, b;
int vis[20][2][10][10], Turn = 1;

ll rec(int pos, int eq, int first, int last){
	ll res = 0;

	if ( limit[pos] == 0 ) return (first == last);
	if ( vis[pos][eq][first][last] == Turn ) return dp[pos][eq][first][last];
	vis[pos][eq][first][last] = Turn;

	for ( int i = 0 ; i < 10 ; i++ ){
		int neq = eq;
		if ( eq == 0 && i + '0' < limit[pos] ) neq = 1;
		if ( eq == 0 && i + '0' > limit[pos] ) break;

		int nfirst = first;
		if ( first == 0 && i ) nfirst = i;

		res += rec(pos + 1, neq, nfirst, i);
	}

	return dp[pos][eq][first][last] = res;
}

void fillStr(ll x){
	int len = 0;
	//cout << x << endl;
	while ( x ){
		limit[len++] = (char)(x % 10) + '0';
		x /= 10;
	}

	while ( len < 19 ) limit[len++] = '0';
	limit[len] = 0;
	//cout << limit << endl;
	for ( int i = 0, j = len - 1 ; i < j ; i++, j-- ){
		char ch = limit[i];
		limit[i] = limit[j];
		limit[j] = ch;
	}
}

ll calcNums(){
	ll res = 0;
	fillStr(b);
	//sprintf(limit, "%lld", b);
	//cout << limit << endl;
	Turn++;
	res += rec(0, 0, 0, 0);
	fillStr(a-1);
	//sprintf(limit, "%lld", a-1);
	//cout << limit << endl;
	Turn++;
	res -= rec(0, 0, 0, 0);
	return res;
}

int main(){
	while ( cin >> a >> b ){
		cout << calcNums() << endl;
	}

	return 0;
}
