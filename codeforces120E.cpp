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

#define filer() freopen("input.txt","r",stdin)
#define filew() freopen("output.txt","w",stdout)

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main(){
	int t;
	
	filer();
	filew();
	while ( cin >> t ){
		while ( t-- ){
			int n;
			while ( cin >> n ){
				int p = (n+1)>>1, q = n>>1;
				p = p * p + q * q;
				if ( p & 1 ) puts("0");
				else puts("1");
			}
		}
	}
	
	return 0;
}

