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

int gcd(int m, int n){
	int tmp;

	while ( n ){
		tmp = m;
		m = n;
		n = tmp % m;
	}

	return m;
}

vector<int> findDivs(int n){
	stack<int> tmp;
	vector<int> final;
	for ( int i = 1 ; i * i <= n ; i++ ){
		if ( n % i == 0 ){
			final.pb(i);
			if ( i * i != n ) tmp.push(n/i);
		}
	}
	
	while ( tmp.empty() == false ){
		final.pb(tmp.top());
		tmp.pop();
	}
	
	return final;
}

int main(){
	int a, b, q, lo, hi;
	
	while ( cin >> a >> b ){
		vector<int>divisors = findDivs(gcd(a, b));
		
		cin >> q;
		while ( q-- ){
			cin >> lo >> hi;
			vector<int>::iterator ptr = upper_bound(divisors.begin(), divisors.end(), hi) - 1;
			if ( ptr == divisors.end() ) ptr--;
			int res = *ptr;
			if ( lo > res ) res = -1;
			cout << res << endl;
		}
	}
	
	return 0;
}

