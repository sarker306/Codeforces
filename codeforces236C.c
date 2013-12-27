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

#define SIZE 1000000
char isNotPrime[SIZE + 1];

void sieve(){
	long i, j;
	
	for ( i = 4 ; i <= SIZE ; i += 2 ) isNotPrime[i] = 1;
	for ( i = 3 ; i * i <= SIZE ; i += 2 )
		if ( isNotPrime[i] == 0 ){
			for ( j = i * i ; j <= SIZE ; j += i ) isNotPrime[j] = 1;
		}
}

ll gcd(ll m, ll n){
	ll tmp;

	while ( n ){
		tmp = m;
		m = n;
		n = tmp % m;
	}

	return m;
}

ll findLCM(long n){
	ll res = 0, i, j, k, tmp1, tmp2;
	long last = n;
	int cnt = !isNotPrime[n];
	
	while ( cnt < 3 ){
		last--;
		if ( isNotPrime[last] == 0 ) cnt++;
	}
	
	for ( i = n ; i >= last ; i-- ){
		for ( j = i ; j >= last ; j-- ){
			tmp1 = i * j / gcd(i, j);
			for ( k = j ; k >= last ; k-- ){
				tmp2 = tmp1 * k / gcd(tmp1, k);
				if ( res < tmp2 ) res = tmp2;
			}
		}
	}
	
	return res;
}

int main(){
	long n;
	int ans[10] = {0, 1, 2, 6, 12, 60};
	
	sieve();
	while ( scanf("%ld", &n) != EOF ){
		if ( n < 6 ) printf("%d\n", ans[n]);
		else printf("%I64d\n", findLCM(n));
	}
	
	return 0;
}

