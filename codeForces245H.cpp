#include <stdio.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long llu;
#define SIZE 5001

long dp[SIZE][SIZE];
char dp2[SIZE][SIZE];
char str[SIZE];

char isPalin(int x, int y){
	char res = 0;

	if ( x >= y ) return 1;
	if ( dp2[x][y] != -1 ) return dp2[x][y];
	
	if ( str[x] == str[y] ) res = isPalin(x + 1, y - 1);
	
	return dp2[x][y] = res;
}

long rec(int x, int y){
	long res = 0;
	
	if ( x > y ) return 0;
	if ( x == y ) return 1;
	
	if ( dp[x][y] != -1 ) return dp[x][y];
	
	res += rec(x, y - 1) + rec(x + 1, y);
	res -= rec(x + 1, y - 1);
	if ( isPalin(x,y) ) res++;
	
	return dp[x][y] = res;
}

int main(){
	unsigned long q;
	int x, y;
	
	/*while ( scanf("%s", str) == 1 ){
		memset(dp2, -1, sizeof(dp2));
		memset(dp, -1, sizeof(dp));
		scanf("%lu", &q);
		while ( q-- ){
			scanf("%d%d", &x, &y);
			x--, y--;
			printf("%ld\n", rec(x, y));
		}
	}*/

	scanf("%s", str);
	memset(dp2, -1, sizeof(dp2));
	memset(dp, -1, sizeof(dp));
	scanf("%lu", &q);
	while ( q-- ){
		scanf("%d%d", &x, &y);
		x--, y--;
		printf("%ld\n", rec(x, y));
	}
	
	return 0;
}

