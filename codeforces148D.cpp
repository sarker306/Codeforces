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

char vis[1001][1001];
double dp[1001][1001];

double rec(int w, int b){
	double res = 0, tmp = 0;
	
	if ( w == 0 ) return 0;
	if ( b == 0 ) return 1;
	if ( vis[w][b] ) return dp[w][b];
	
	vis[w][b] = 1;
	res += w;
	if ( b >= 2 ){
		if ( w ) tmp += w * rec(w-1, b-2);
		if ( b >= 3 ) tmp += (b - 2) * rec(w, b - 3);
		tmp *= b * (b-1);
		tmp /= (w + b - 1) * (w + b - 2);
		res += tmp;
	}
	
	res /= ( w + b );
	//printf("%d %d -> %lf\n", w, b, res);
	return dp[w][b] = res;
}

int main(){
	int w, b;
	
	while ( cin >> w >> b ){
		memset(vis, 0, sizeof(vis));
		printf("%.12lf\n", rec(w, b));
	}
	
	return 0;
}

