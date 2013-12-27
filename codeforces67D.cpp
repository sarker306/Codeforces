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

map<int, int>mappng;
int tree[4000001];

int lo, hi;

void update(int node, int left, int right, int val){
	int mid = (left + right) >> 1, leftC = (node<<1) + 1, rightC = (node+1)<<1;
	
	if ( left == right ){
		tree[node] += val;
		return;
	}
	
	if ( lo <= mid ) update(leftC, left, mid, val);
	if ( hi > mid ) update(rightC, mid + 1, right, val);
	tree[node] = max(tree[leftC], tree[rightC]);
}

int read(int node, int left, int right){
	int mid = (left + right) >> 1, leftC = (node<<1) + 1, rightC = (node+1)<<1;
	int p1 = INT_MIN, p2 = INT_MIN;
	
	if ( left > hi || right < lo ) return INT_MIN;
	if ( left >= lo && right <= hi ) return tree[node];
	if ( lo <= mid ) p1 = read(leftC, left, mid);
	if ( hi > mid ) p2 = read(rightC, mid + 1, right);
	
	return max(p1, p2);
}
	
int main(){
	int n, x;
	
	while ( scanf("%d", &n) == 1 ){
		for ( int i = 1 ; i <= n ; i++ ){
			scanf("%d", &x);
			mappng.insert(pair<int, int>(x, i));
		}
		
		for ( int i = 1 ; i <= n ; i++ ){
			scanf("%d", &x);
			x = mappng.find(x)->second;
			lo = x + 1, hi = n;

			int cur;
			if ( lo > hi ) cur = 0;
			else cur = read(0, 1, n);
			lo = hi = x;
			update(0, 1, n, cur + 1);
		}
		
		lo = 1, hi = n;
		printf("%d\n", read(0, 1, n));
		for ( int i = 0 ; i <= 4*n ; i++ ) tree[i] = 0;
		mappng.clear();
	}
	
	return 0;
}

