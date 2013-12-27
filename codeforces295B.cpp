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
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int adj[501][501], order[501], final[501][501], n, avl[501];
ll res[501];

void printMat(){
	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < n ; j++ ) cout << ((final[i][j] == INF) ? -1 : final[i][j]) << ' ';
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	while ( cin >> n ){
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < n ; j++ )
				cin >> adj[i][j];
		for ( int i = 0 ; i < n ; i++ ) cin >> order[i], avl[i] = 0, order[i]--;

		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < n ; j++ )
				final[i][j] = INF;

		for ( int k = n-1 ; k >= 0 ; k-- ){
			//final[order[k]][order[k]] = 0;
			avl[order[k]] = 1;
			for ( int i = 0 ; i < n ; i++ ) if ( avl[order[i]] ) final[order[i]][order[k]] = MIN(final[order[i]][order[k]], adj[order[i]][order[k]]);
			for ( int i = 0 ; i < n ; i++ ) if ( avl[order[i]] ) final[order[k]][order[i]] = MIN(final[order[k]][order[i]], adj[order[k]][order[i]]);

			for ( int i = n-1 ; i >= k ; i-- ){
				if ( avl[order[i]] == 0 ) continue;
				for ( int j = n-1 ; j >= k ; j-- ){
					if ( avl[order[j]] == 0 ) continue;
					if ( final[order[i]][order[k]] > final[order[i]][order[j]] + final[order[j]][order[k]] )
					final[order[i]][order[k]] = final[order[i]][order[j]] + final[order[j]][order[k]];
					if ( final[order[k]][order[i]] > final[order[k]][order[j]] + final[order[j]][order[i]] )
					final[order[k]][order[i]] = final[order[k]][order[j]] + final[order[j]][order[i]];
				}
			}
			res[k] = 0;

			for ( int i = n-1 ; i >= k ; i-- ){
				if ( avl[order[i]] == 0 ) continue;
				for ( int j = n-1 ; j >= k ; j-- ){
					if ( avl[order[j]] == 0 ) continue;
					if ( final[order[i]][order[j]] > final[order[i]][order[k]] + final[order[k]][order[j]] )
					final[order[i]][order[j]] = final[order[i]][order[k]] + final[order[k]][order[j]];
					if ( final[order[i]][order[j]] != INF ) res[k] += final[order[i]][order[j]];
				}
			}
		//	printMat();
		}
		
		for ( int i = 0 ; i < n ; i++ ){
			if ( i ) cout << ' ';
			cout << res[i];
		}
		cout << endl;
	}
	
	return 0;
}
/*
4
0 57148 51001 13357
71125 0 98369 67226
49388 90852 0 66291
39573 38165 97007 0
2 3 1 4
*/
