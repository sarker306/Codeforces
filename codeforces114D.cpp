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

struct Pos{
	char ch;
	char isEnd;
	
	Pos *next[26];
	
	void set(char c){
		ch = c;
		isEnd = 0;
		for ( int i = 0 ; i < 26 ; i++ ) next[i] = 0;
	}
	
	Pos *insert(char c){
		if ( next[c - 'a'] == 0 ){
			next[c - 'a'] = (Pos*)malloc(sizeof(Pos));
			next[c - 'a']->set(c);
		}
		
		return next[c - 'a'];
	}
};

int clear(Pos *node){
	int isLeaf = node->isEnd, cnt = 0;
	for ( int i = 0 ; i < 26 ; i++ )
		if ( node->next[i] ){
			cnt += clear(node->next[i]);
		}

	free(node);
	return cnt + isLeaf;
}

void failure(char *str, int *fail){
	int k = 0;
	fail[0] = fail[1] = 0;
	for ( int i = 2 ; str[i] ; i++ ){
		while ( k > 0 && str[k + 1] != str[i] ) k = fail[k];
		if ( str[k+1] == str[i] ) k++;
		fail[i] = k;
	}
}

vector<int> matcher(char *inp, char *pat, int *fail, bool end){
	int m = 0;
	vector<int> matches;
	
	for ( int i = 1 ; inp[i] ; i++ ){
		while ( m > 0 && pat[m + 1] != inp[i] ) m = fail[m];
		if ( pat[m+1] == inp[i] ) m++;
		if ( pat[m+1] == 0 ) matches.pb(i + ((end) ? 0 : -m));
	}
	
	return matches;
}

int main(){
	char inp[2005], st[2005], en[2005];
	int fail[2005], enLen, stLen, res;
	unsigned hash;
	Pos *head;
	
	ios::sync_with_stdio(true);
	
	while ( scanf("%s", inp + 1) == 1 ){
		scanf("%s%s", st + 1, en + 1);
		res = 0;
  		failure(st, fail);
  		vector<int> stM = matcher(inp, st, fail, false);
  		
  		enLen = strlen(en + 1);
  		stLen = strlen(st + 1);
  		failure(en, fail);
  		vector<int> enM = matcher(inp, en, fail, true);
  		
  		head = (Pos*)malloc(sizeof(Pos));
  		head->set(0);

  		for ( int i = 0 ; i < stM.size() ; i++ ){
  			int last = 0;
			Pos *node = head;
			string str;
			hash = 0;
  			for ( ; last < enM.size() && enM[last] < stM[i] + max(enLen, stLen) ; last++ );
  			
  			for ( int j = stM[i] + 1 ; inp[j] ; j++ ){
  				if ( last == enM.size() ) break;
  				
				node = node->insert(inp[j]);
  				
  				if ( enM[last] == j ){
  					node->isEnd = 1;
					last++;
				}
  			}
  		}
  		
  		cout << clear(head) << endl;
  	}
  	
	return 0;
}

