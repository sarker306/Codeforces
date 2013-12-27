#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

typedef unsigned long long llu;
typedef long long ll;

int cost[1001][2];
int dp[1001][1001][2];
char vis[1001][1001][2];
int n, m, x, y;
char grid[1001][1001];
enum Color{BLACK, WHITE};

int min(int a, int b){ return a < b ? a : b; }

int rec(int pos, int run, int lastCol){
	int res = INT_MAX, now = 0;
	
	if ( pos == m && run >= x ) return 0;
	if ( pos == m && run < x ) return 10000;
	if ( vis[pos][run][lastCol] ) return dp[pos][run][lastCol];
	vis[pos][run][lastCol] = 1;
	
	if ( run < y ){
		now = rec(pos + 1, run + 1, lastCol) + cost[pos][lastCol];
		if ( res > now ) res = now;
	}
	if ( run >= x ){
		now = rec(pos + 1, 1, lastCol ^ 1) + cost[pos][lastCol ^ 1];
		if ( res > now ) res = now;
	}
	
	return dp[pos][run][lastCol] = res;
}

int main(){
	int i, j;
	
	while ( scanf("%d%d%d%d", &n, &m, &x, &y) == 4 ){
		for ( i = 0 ; i < n ; i++ ) scanf("%s", grid[i]);
		for ( i = 0 ; i < n ; i++ )
			for ( j = 0 ; j < m ; j++ ){
				if ( grid[i][j] == '#' ) cost[j][WHITE]++;
				else cost[j][BLACK]++;
			}

		printf("%d\n", min(rec(0,0,BLACK), rec(0,0,WHITE)));
		memset(cost, 0, sizeof(cost));
		memset(vis, 0, sizeof(vis));
	}
	
	return 0;
}

