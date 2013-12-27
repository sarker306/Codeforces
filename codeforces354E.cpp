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

char total[21];
int ks;
int vis[21][7][44];
int dp[21][7][44];
char toSet[21][7][44];
char output[7][21];
int isPossible[7][44];

void printPath(int col, int row, int sum){
	if ( col == 0 && row == 6 ) return;
	if ( row == 6 ) return printPath(col - 1, 0, sum / 10);
	else if ( dp[col][row][sum] ){
		output[row][col] = toSet[col][row][sum];
		printPath(col, row + 1, sum + toSet[col][row][sum] - '0');
	}
}

int rec(int col, int row, int sum){
	int res = 0;
	char action = 0;
	
	if ( row == 6 ){
		if ( total[col] - '0' == sum % 10 ){
			if ( col == 0 ) return sum ? 0 : 1;
			return rec(col - 1, 0, sum / 10);
		}
		else return 0;
	}
	if ( vis[col][row][sum] == ks ) return dp[col][row][sum];
	
	vis[col][row][sum] = ks;
	if ( rec(col, row + 1, sum) ) res = 1, action = '0';
	else if ( rec(col, row + 1, sum + 4) ) res = 1, action = '4';
	else if ( rec(col, row + 1, sum + 7) ) res = 1, action = '7';
	
	toSet[col][row][sum] = action;
	return dp[col][row][sum] = res;
}

int main(){
	int test;
	ll val, tmp;
	
	while ( cin >> test ){
		for ( ks = 1 ; ks <= test ; ks++ ){
			cin >> val;
			sprintf(total, "%020I64d", val);
			if ( rec(19,0,0) == 0 ){
				cout << -1 << endl;
			}
			else{
				printPath(19, 0, 0);
				for ( int i = 0 ; i < 6 ; i++ ){
					sscanf(output[i], "%I64d", &tmp);
					if ( i ) putchar(' ');
					cout << tmp;
				}
				
				puts("");
			}
		}
	}
	
	return 0;
}

