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

vector<ll>lucky;
ll factorial[14], k;

int isLucky(ll val){
	while ( val ){
		int t = val % 10;
		if ( t != 4 && t != 7 ) return 0;
		val /= 10;
	}
	
	return 1;
}

void init(){
	queue<ll>q;
	lucky.pb(0);
	q.push(0);
	
	while ( q.empty() == false ){
		ll u = q.front();
		q.pop();

		ll v = u * 10 + 4;
		if ( v <= 1000000000LL ) lucky.pb(v), q.push(v);
		v = u * 10 + 7;
		if ( v <= 1000000000LL ) lucky.pb(v), q.push(v);
	}
	
	factorial[0] = 1;
	for ( int i = 1 ; i < 14 ; i++ ) factorial[i] = factorial[i-1] * i;
}

int last;
void buildPerm(ll *arr, int *used, int pos){
	if ( pos == last ){
		return;
	}
	
	for ( int i = 1 ; i <= last ; i++ ){
		if ( used[i] == 1 ) continue;
		ll tmp = factorial[last - pos - 1];
		if ( k <= tmp ){
			arr[pos] = i;
			used[i] = 1;
			buildPerm(arr, used, pos + 1);
			break;
		}
		else k -= tmp;
	}
}

int bSearch(vector<ll> &arr, ll n){
	int low = 0, hi = arr.size();
	
	while ( low + 1 < hi ){
		int mid = ( low + hi ) >> 1;
		if ( arr[mid] <= n ) low = mid;
		else hi = mid;
	}
	
	return low;
}

int findLuckyPositions(ll *arr, int len, ll offset){
	int cnt = bSearch(lucky, offset);
	for ( int i = 0 ; i < len ; i++ )
		if ( isLucky(i + offset + 1) && isLucky(arr[i] + offset)) cnt++;
		
	return cnt;
}

int main(){
	ll n, arr[15];
	int used[15];
	
	init();
	while ( cin >> n >> k ){
		//
		if ( n < 13 && factorial[n] < k ){
			cout << -1 << endl;
			continue;
		}
		if ( n >= 13 ) last = 13, n -= 13;
		else last = n, n = 0;
		for ( int i = 0 ; i <= last ; i++ ) used[i] = 0;
		buildPerm(arr, used, 0);
/*
		for ( int i = 0 ; i < last ; i++ ) printf("%d ", arr[i] + n);
		puts("");*/
		
		cout << findLuckyPositions(arr, last, n) << endl;
	}
	
	return 0;
}

