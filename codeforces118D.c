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

int dp[101][101][11][3];
char vis[101][101][11][3];
int runs[2];
enum Person{HORSE, FOOT};
int MOD = 100000000;
int rec(int ft, int hr, int run, int who){
	int res = 0;
	
	if ( ft == 0 && hr == 0 ) return 1;
	if ( vis[ft][hr][run][who] ) return dp[ft][hr][run][who];
	vis[ft][hr][run][who] = 1;
	
	if ( ft ){
		if ( who == FOOT && run < runs[FOOT] )
			res = ( res + rec(ft - 1, hr, run + 1, who ) ) % MOD;

		if ( who != FOOT ) res = ( res + rec(ft - 1, hr, 1, FOOT) ) % MOD;
	}

	if ( hr ){
		if ( who == HORSE && run < runs[HORSE] )
			res = ( res + rec(ft, hr - 1, run + 1, who ) ) % MOD;

		if ( who != HORSE ) res = ( res + rec(ft, hr - 1, 1, HORSE) ) % MOD;
	}
	
	return dp[ft][hr][run][who] = res;
}

int main(){
	int n1, n2;
	
	while ( scanf("%d%d%d%d", &n1, &n2, &runs[1], &runs[0]) != EOF ){
		printf("%d\n", rec(n1, n2, 0, 2));
		memset(vis, 0, sizeof(vis));
	}
	
	return 0;
}

