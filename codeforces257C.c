#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)
#define SIZE 100005

typedef unsigned long long llu;
typedef long long ll;

typedef struct Point{
	double x, y;
}Point;

double PI = 2*acos(0.0);

double polar(Point *p){
	double res = atan2(p->y, p->x);
	if ( res < 0 ) res += 2*PI;
	
	return res;
}

Point pts[SIZE];
Point *ptrToPts[SIZE];

int cmpPolar(const void *a, const void *b){
	Point *x= *(Point**)a, *y = *(Point**)b;
	
	return polar(x) > polar(y) ? 1 : -1;
}

int main(){
	long n, i;
	double res, tmp;
	
	while ( scanf("%ld", &n) == 1){
		for ( i = 0 ; i < n ; i++ ){
			scanf("%lf%lf", &pts[i].x, &pts[i].y);
			ptrToPts[i] = pts + i;
		}

		qsort(ptrToPts, n, sizeof(Point*), cmpPolar);
		res = (polar(ptrToPts[n-1]) - polar(ptrToPts[0]));
		if ( fabs(res) > 1e-6 && res < 0 ) res += 2*PI;
		for ( i = 0 ; i + 1 < n ; i++ ){
			/*printf("%lf %lf %lf\n", ptrToPts[i]->x, ptrToPts[i]->y, polar(ptrToPts[i]));*/
			tmp = 2*PI - (polar(ptrToPts[i+1]) - polar(ptrToPts[i]));
			if ( res > tmp ) res = tmp;
		}
		
		printf("%.10lf\n", res * 180 / PI);
	}
	
	return 0;
}

