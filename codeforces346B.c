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

char s1[101], s2[101], vir[101];
char vis[101][101][101];
char action[101][101][101];
int dp[101][101][101];
ll par[101][101][101];
int fail[101];

int max(int a, int b){ return a > b ? a : b ; }

void computeFailure(char *pattern, int *failure){
	int m = strlen(pattern), i, k = 0;

	failure[0] = failure[1] = 0;
	for ( i = 2 ; i <= m ; i++ ){
		while ( k > 0 && pattern[k] != pattern[i - 1] )
			k = failure[k];

		if ( pattern[k] == pattern[i - 1] )
			k++;

		failure[i] = k;
		/* printf("failure[%ld] = %ld\n", i, k); */
	}
}

ll parentify(int x, int y, int z){
	return x*1000000LL + y*1000LL + z;
}

void unparentify(ll p, int *x, int *y, int *z){
	*x = p / 1000000LL;
	p -= (*x)*1000000LL;
	*y = p/1000LL;
	*z = p % 1000LL;
}

void printPath(int x, int y, int z){
	int parx, pary, parz;

	if ( action[x][y][z] ) printf("%c", s1[x]);
	if ( par[x][y][z] != -1 ){
		unparentify(par[x][y][z], &parx, &pary, &parz);
		printPath(parx, pary, parz);
	}
}

int rec(int x, int y, int z){
	int res = INT_MIN, i = 0, j = 0;
	char temp[101];
	int a, b;
	
	if ( vir[z] == 0 ) return INT_MIN;
	if ( s1[x] == 0 || s2[y] == 0 ) return 0;
	if ( vis[x][y][z] ) return dp[x][y][z];
	
	vis[x][y][z] = 1;
	if ( s1[x] == s2[y] ){
		if ( s1[x] != vir[z] ){
			for ( i = 0 ; i < z ; i++ ) temp[i] = vir[i];
			temp[i] = s1[x];
			temp[i+1] = 0;
			
			j = z;
			while ( j > 0 && vir[j] != s1[x] ) j = fail[j];
			if ( vir[j] == s1[x] ) j++;
			
			res = 1 + rec(x + 1, y + 1, j);
			par[x][y][z] = parentify(x+1, y+1, j);
			action[x][y][z] = s1[x];
		}
		else{
			res = 1 + rec(x + 1, y + 1, z + 1);
			par[x][y][z] = parentify(x+1, y+1, z+1);
			action[x][y][z] = s1[x];
		}
	}
	
	res = max(a = rec(x, y + 1, z), res);
	if ( res == a ){
		par[x][y][z] = parentify(x, y + 1, z);
		action[x][y][z] = 0;
	}
	res = max(b = rec(x + 1, y, z), res);
	if ( res == b ){
		par[x][y][z] = parentify(x + 1, y, z);
		action[x][y][z] = 0;
	}
	
	return dp[x][y][z] = res;
}

int main(){
	ll p;
	int x, y, z, i, j;

	while ( scanf("%s%s%s", s1, s2, vir) != EOF ){
		memset(par, -1, sizeof(par));
		computeFailure(vir, fail);
		if ( rec(0,0,0) == 0 ) printf("0\n");
		else{
			printPath(0,0,0);
			puts("");
		}
		memset(vis, 0, sizeof(vis));
		memset(action, 0, sizeof(action));
	}
	
	return 0;
}

