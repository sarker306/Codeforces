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

int srt[1000002];
int val[1000002], n;
ll sqnc[3][1000002];

void add(ll *arr, int ind, ll val){
	while ( ind <= n ){
		arr[ind] += val;
		ind += ind & -ind;
	}
}

ll read(ll *arr, int ind){
	ll sum = 0;
	
	while ( ind ){
		sum += arr[ind];
		ind -= ind & -ind;
	}
	
	return sum;
}

int main(){
	while ( cin >> n ){
		memset(sqnc, 0, sizeof(sqnc));
		for ( int i = 0 ; i < n ; i++ ){
			cin >> val[i];
			srt[i] = val[i];
		}
		
		srt[n] = 1000000009;
		sort(srt, srt + n);
		for ( int i = 0 ; i < n ; i++ ){
			int p = upper_bound(srt, srt + n, val[i]) - srt;
			//printf("%d\n", p);
			add(sqnc[0], p, 1);
			for ( int j = 1 ; j < 3 ; j++ ){
				ll res = read(sqnc[j-1], n) - read(sqnc[j-1], p);
				add(sqnc[j], p, res);
			}
		}
		
		cout << read(sqnc[2], n) << endl;
	}
	
	return 0;
}

