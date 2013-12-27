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

ll a[5005], b[5005];
int N;
ll dp[5005], tmp[5005];

int main(){
	while ( cin >> N ){
		for ( int i = 1 ; i <= N ; i++ ){
			cin >> a[i];
			b[i] = a[i];
		}
		
		sort(b + 1, b + N + 1);
		dp[0] = 1000000000000000LL;
		
		for ( int j = 1 ; j <= N ; j++ ){
			ll diff = a[1] - b[j];
			if ( diff < 0 ) diff = -diff;
			dp[j] = min(dp[j-1], diff);
			tmp[j] = dp[j];
		}
		
		for ( int i = 2 ; i <= N ; i++ ){
			dp[0] = 1000000000000000LL;
			for ( int j = 1 ; j <= N ; j++ ){
				ll diff = a[i] - b[j];
				if ( diff < 0 ) diff = -diff;
				dp[j] = min(dp[j-1], tmp[j] + diff);
			}
			for ( int j = 0 ; j <= N ; j++ ) tmp[j] = dp[j];
		}
		
		ll minMove = LLONG_MAX;
		for ( int i = 1 ; i <= N ; i++ ) minMove = min(minMove, dp[i]);
		cout << minMove << endl;
	}
		
	return 0;
}

