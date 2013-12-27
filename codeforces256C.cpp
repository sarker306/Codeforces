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
#define SIZE 2000005
#define MOD 7340033

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int grundy[SIZE];
ll minLimit[] = {1,4,16,82,6724,50626,2000000};
int gVals[] = {0, 1, 2, 0, 3, 1, 1};

int findCleverGrundy(ll x){
	int j;
	ll i, rt4, rt2;
	int avl[4] = {0,0,0,0};
	if ( x < 4 ) return 0;
	
	rt4 = (ll)(sqrt(sqrt(x)));
	if ( rt4 * rt4 * rt4 * rt4 < x ) rt4++;
	rt2 = (ll)(sqrt(x));
	if ( rt2 * rt2 < x ) rt2++;
	if ( rt2 * rt2 > x ) rt2--;
	
	//printf("%lld -> %lld, %lld\n", x, rt4, rt2);
	for ( j = 0 ; j < 7 ; j++ ){
		if ( minLimit[j] == rt4 || (minLimit[j] < rt4 && rt4 < minLimit[j+1]) ) break;
	}
	
	for ( ; j < 7 ; j++ ){
		if ( minLimit[j] > rt2 ) break;
		//printf("%d ", j);
		avl[gVals[j]] = 1;
	}
	//puts("");
	/*
	for ( j = 0 ; j < 7 ; j++ ){
		i = minLimit[j];
		if ( i * i > x ) break;
		if ( x <= i * i * i * i ) avl[gVals[j]] = 1;
	}
	*/
	for ( j = 0 ; ; j++ ) if ( avl[j] == 0 ) return j;
}

int findGrundy(ll x){
	int i;
	set<int>avl;
	
	if ( grundy[x] != -1 ) return grundy[x];
	for ( i = 0 ; i * i * i * i < x ; i++ );
	for ( ; i * i <= x ; i++ ){
		if ( i != x ) avl.insert(findGrundy(i));
	}
	
	for ( i = 0 ; ; i++ ) if ( avl.find(i) == avl.end() ) break;
	return grundy[x] = i;
}

int main(){
	int n, res;
	ll x;
	/*memset(grundy, -1, sizeof(grundy));
	
	/*for ( int i = 1 ; i < SIZE ; i++ ){
		if ( findGrundy(i) != findCleverGrundy(i) ){
			printf("%d %d %d\n", i, findGrundy(i), findCleverGrundy(i));
		}
		if ( findGrundy(i) == grundy[i-1] ) continue;
		cout << i << " - " << findGrundy(i) << endl;
	}*/
	
	while ( cin >> n ){
		res = 0;
		for ( int i = 0 ; i < n ; i++ ){
			cin >> x;
			res ^= findCleverGrundy(x);
		}
		
		cout << ( res ? "Furlo":"Rublo" ) << endl;
	}
	
	return 0;
}
/*
1 - 0
4 - 1
16 - 2
82 - 0
6724 - 3
50626 - 1
*/
