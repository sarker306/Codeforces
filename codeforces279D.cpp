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

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

bool dp[24][1<<23];
int arr[24];
int n, m;

int process(){
	int i, j, k;
	vector<pair<int, int> > pos[24];
	
	m = INT_MAX;
	
	for ( k = 0 ; k < n ; k++ )
		for ( i = 0 ; i < k ; i++ )
			for ( j = i ; j < k ; j++ )
				if ( arr[k] == arr[i] + arr[j] ) pos[k].pb(pair<int, int>(i, j));

	for ( i = 1 ; i < n ; i++ ) if ( pos[i].size() == 0 ) return -1;
	
	dp[1][1] = true;
	for ( i = 1 ; i < n ; i++ ){
		for ( j = 0 ; j < ( 1 << i ) ; j++ ){
			//printf("%d ", dp[i][j]);
			if ( dp[i][j] ){
				int flag = 0;
				for ( k = 0 ; k < pos[i].size() ; k++ ){
					if ( ( j & (1<<pos[i][k].first)) && (j &(1<<pos[i][k].second))){
						//printf("(%d %d %d) ", j, (pos[i][k].first), (pos[i][k].second));
						flag = 1;
						break;
					}
				}
				
				if ( flag == 0 ) continue;
				dp[i+1][j | (1<<i)] = true;
				for ( k = 0 ; k < i ; k++ ) if ( j & (1<<k) ) dp[i+1][(j | (1<<i)) ^ (1<<k)] = true;
			}
		}
		
		//puts("");
	}

	for ( j = 0 ; j < ( 1 << n ) ; j++ )
		if ( dp[n][j] ){
			k = j;
			int cnt = 0;
			while ( k ){
				k &= k - 1;
				cnt++;
			}
			
			if ( cnt < m ) m = cnt;
  		}

	return ( m == INT_MAX ) ? -1 : m;
}

int main(){
	while ( scanf("%d", &n) == 1 ){
		for ( int i = 0 ; i < n ; i++ )
			scanf("%d", &arr[i]);

		cout<<process()<<endl;
		memset(dp, 0, sizeof(dp));
	}
	
	return 0;
}

