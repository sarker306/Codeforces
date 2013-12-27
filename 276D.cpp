#include <stdio.h>
#include <iostream>

using namespace std;

char low[70], high[70];
long long dp[70][2][2][2][2];
int vis[70][2][2][2][2];
int turn = 1, len;

long long rec(int pos, int ga, int ea, int lb, int eb){
    if ( low[pos] == 0 ) return 0;
    if ( vis[pos][ga][ea][lb][eb] == turn ) return dp[pos][ga][ea][lb][eb];

    vis[pos][ga][ea][lb][eb] = turn;
    dp[pos][ga][ea][lb][eb] = 0;
    for ( char i = '0' ; i < '2' ; i++  )
        for ( char j = '0' ; j < '2' ; j++ ){
            int nga = ga, nea = ea, nlb = lb, neb = eb;

            if ( ga == 0 && i < low[pos] ) continue;
            if ( ga == 0 && i > low[pos] ) nga = 1;

            if ( ea == 0 && i > high[pos] ) continue;
            if ( ea == 0 && i < high[pos] ) nea = 1;

            if ( lb == 0 && j < low[pos] ) continue;
            if ( lb == 0 && j > low[pos] ) nlb = 1;

            if ( eb == 0 && j > high[pos] ) continue;
            if ( eb == 0 && j < high[pos] ) neb = 1;

            long long temp = rec(pos + 1, nga, nea, nlb, neb);
            if ( i != j ) temp += 1LL<<(len-pos-1);
            if ( dp[pos][ga][ea][lb][eb] < temp ) dp[pos][ga][ea][lb][eb] = temp;
        }

    return dp[pos][ga][ea][lb][eb];
}

void process(long long a, long long b){
    int len1 = 0, len2 = 0;;
    while ( a ){
        low[len1++] = (a & 1) + '0';
        a >>= 1;
    }

    while ( b ){
        high[len2++] = (b&1) + '0';
        b >>= 1;
    }

    while ( len1 < len2 ){
        low[len1++] = '0';
    }

    while ( len2 < len1 ){
        high[len2++] = '0';
    }

    int i, j;
    for ( i = 0 , j = len1 - 1; i < j ; i++, j--){
        char tmp = low[i];
        low[i] = low[j];
        low[j] = tmp;
        tmp = high[i];
        high [i] = high[j];
        high[j] = tmp;
    }

    len = len1;
    low[len1] = high[len1] = 0;
    //puts(low);
    //puts(high);
}

int main(){
    long long l, r;

    //freopen("sshh.in", "r", stdin);
    while ( cin >> l >> r ){
        process(l,r);
        cout<<rec(0, 0, 0, 0, 0)<<endl;
        turn++;
    }

    return 0;
}

