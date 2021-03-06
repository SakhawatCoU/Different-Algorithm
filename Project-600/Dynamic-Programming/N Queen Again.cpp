/* 
Problem Link ::http://lightoj.com/volume_showproblem.php?problem=1061

*/

//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 100 ;
const int INF = 1 << 29 ;
int sv[NX][10][2] , idx;
int column[20] , diagonal1[40] , diagonal2[40] ;
int queen[20];
int vis[ 1 << 9 ][ 100 ][ 10 ] , row[10] , col[10] ;
int dp[ 1 << 9 ][ 100 ][ 10 ] , cs ;
char str[10][10];
void nqueen(int row)
{
    if( row == 8 )
    {
        rep( i , 8 )
        {
            sv[idx][i][0] = i ;
            sv[idx][i][1] = queen[i];
        }
        idx++;
        return ;
    }
    rep( i , 8 )
    {
        if( column[i] || diagonal1[i+row] || diagonal2[8+i-row] ) continue ;
        queen[row] = i ;
        column[i] = diagonal1[i+row] = diagonal2[8+i-row] = 1 ;
        nqueen(row+1);
        column[i] = diagonal1[i+row] = diagonal2[8+i-row] = 0 ;
    }
}
int distance( int idx , int x , int y )
{
    int x1 = sv[idx][x][0] ;
    int y1 = sv[idx][x][1] ;
    int x2 = row[y];
    int y2 = col[y];
    if( x1 == x2 && y1 == y2 ) return 0 ;
    else if ( x1 == x2 || y1 == y2 || abs( x1 - x2 ) == abs( y1 - y2 ) ) return 1 ;
    else return 2 ;
}
int DP( int row , int mask , int idx )
{
    if( row == 8 ) return 0 ;
    int &ret = dp[mask][idx][row];
    if( vis[mask][idx][row] == cs ) return ret ;
    vis[mask][idx][row] = cs ;
    ret = INF ;
    rep( i , 8 )
    {
        if( mask & ( 1 << i ) ) continue ;
        ret = min( ret , distance(idx,i,row) + DP( row + 1 , mask | ( 1 << i ) ,  idx ));
    }
    return ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    nqueen(0);
    int  t = II ;
    for( cs = 1 ; cs <= t ; cs++)
    {
        int id = 0 ;
        rep( i , 8 )
        {
            scanf("%s",str[i]);
            rep( j , 8 )
            {
                if( str[i][j] == 'q' )
                {
                    row[id] = i ;
                    col[id++] = j ;

                }
            }
        }
        int ans = INF ;
        rep( i , idx )
        {
            ans = min( ans , DP( 0 , 0 , i ) );
        }
        printf("Case %d: %d\n",cs,ans);
    }


    return 0;
}
