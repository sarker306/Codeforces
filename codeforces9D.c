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

llu arr[36][36];

int main(){
	int i, j, k, n;
	llu sum;
	
	for ( i = 1 ; i <= 35 ; i++ ) arr[0][i] = arr[1][i] = 1;
	for ( i = 2 ; i <= 35 ; i++ ){
		for ( j = 1 ; j <= 35 ; j++ ){
			arr[i][j] = 0;
			for ( k = 0 ; k < i ; k++ ){
				arr[i][j] += arr[k][j-1] * arr[i-k-1][j-1];
			}
		}
	}
	
	for ( i = 1 ; i <= 35 ; i++ )
		for ( j = 35 ; j ; j-- ){
			arr[i][j] -= arr[i][j-1];
		}

	while ( scanf("%d%d", &n, &k) == 2 ){
		sum = 0;
		for ( j = k ; j <= n ; j++ ) sum += arr[n][j];
		printf("%llu\n", sum);
	}
	
	return 0;
}

