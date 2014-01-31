/* Template the Final Chapter Light --- Fimbulvetr version 0.1 */
/* In this blizzard, I will find peace. */

# define LOCAL
# include <cstring>
# include <cstdio>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
using namespace std;

# define REP( i, n ) for ( int i = 1; i <= n; i ++ )
# define REP_0( i, n ) for ( int i = 0; i < n; i ++ )
# define REP_0N( i, n ) for ( int i = 0; i <= n; i ++ )
# define REP_S( i, ss ) for ( char *i = ss; *i; i ++ )
# define REP_G( i, u ) for ( int i = pos[ u ]; i; i = g[ i ].frt )
# define FOR( i, a, b ) for ( int i = a; i <= b; i ++ )
# define DWN( i, a, b ) for ( int i = b; i >= a; i -- )
# define RST( a ) memset ( a, 0, sizeof ( a ) )
# define CLR( a, x ) memset ( a, x, sizeof ( a ) )
# define CPY( a, b ) memcpy ( a, b, sizeof ( a ) )
typedef long long LL;
const int inf = 1 << 30;

inline char ReadChar () { for ( char c = ' '; 1; c = getchar () ) if ( c != ' ' && c != '\n' ) return c; }
template < typename T > inline void RD ( T &x ) 
{ 
	char c; x = 0;
	for ( c = ' '; c == ' ' || c == '\n'; c = getchar () ) ;
	for ( ; c >= '0' && c <= '9'; c = getchar () ) x = x * 10 + c - '0';
}
template < typename T > inline void RD ( T &x1, T &x2 ) { RD ( x1 ); RD ( x2 ); }
template < typename T > inline void RD ( T &x1, T &x2, T &x3 ) { RD ( x1, x2 ); RD ( x3 ); }
template < typename T > inline void ARD ( T *a, int n ) { REP ( i, n ) RD ( a[ i ] ); }

inline void PrintString ( char *s, bool ty = 0 )  { REP_S ( i, s ) putchar ( *i ); putchar ( ty ? ' ' : '\n' ); }
template < typename T > inline void PrintInt ( T x, bool ty = 0 )
{
	if ( !x ) { printf ( "0%c", ty ? ' ' : '\n' ); return ; }
	int lg = 0, mns = false;
	for ( char dig[ 20 ]; 1; x /= 10 )
	{
		if ( x < 0 ) x = -x, mns = true;
		if ( !x ) 
		{ 
			if ( mns ) putchar ( '-' );
			REP_0 ( i, lg ) putchar ( dig[ lg - i - 1 ] );
			putchar ( ty ? ' ' : '\n' );
			return ; 
		}
		dig[ lg ++ ] = x % 10 + '0';
	}
}
template < typename T > inline void OT ( T x ) { PrintInt ( x ); }
template < typename T > inline void OT ( T x1, T x2 ) { PrintInt ( x1, 1 ); OT ( x2 ); }
template < typename T > inline void OT ( T x1, T x2, T x3 ) { PrintInt ( x1, 1 ); OT ( x2, x3 ); }
template < typename T > inline void AOT ( T *a, int n ) { REP ( i, n ) PrintInt ( a[ i ], 1 ); putchar ( '\n' ); }

template < typename T > T gcd ( T a, T b )
{
	if ( a < b ) swap ( a, b );
	if ( a % b == 0 ) return b;
	return gcd ( b, a % b );
}

# ifdef BIGRAPHMATCH
namespace BiGraphMatch
{
# define PSIZE 1010
int match[ PSIZE ], N;
bool vis[ PSIZE ];
bool BiMatch ( int u )
{
	REP_G ( i, u )
		if ( !vis[ v ] )
		{
			vis[ v ] = true;
			if ( match[ v ] == -1 || BiMatch ( v ) )
			{
				match[ v ] = u;
				return true;
			}
		}
	return false;
}
int Hungary ()
{
	int ret = 0, u;
	CLR ( match, -1 );
	REP ( u, N ) RST ( vis, 0 ), ret += BiMatch ( u );
	return ret;
}
}
# endif

# ifdef NETWORKFLOW
namespace NetworkFlow
{
# define v g[ i ].y
# define PE g[ i ].fl
# define ME g[ g[ i ].rev ].fl

bool Denote ()
{
	CLR ( lv, -1 ), lv[ S ] = 0, head = 1, tail = 1, q[ 1 ] = S;
	while ( head <= tail )
	{
		int u = q[ head ];
		REP_G ( i, u )
			if ( lv[ v ] < 0 && PE > 0 )
				lv[ v ] = lv[ u ] + 1, q[ ++ tail ] = v;
		head ++;
	}
	return lv[ T ] > 0;
}
int FindPath ( int u, int maxf )
{
	int ret = 0, flow;
	if ( nof[ u ] ) return 0;
	if ( u == T ) return maxf;
	REP_G ( i, u )
		if ( maxf > 0 && PE > 0 && lv[ v ] == lv[ u ] + 1 && ( flow = FindPath ( v, min ( maxf, PE ) ) ) )
			PE -= flow, ME += flow, ret += flow, maxf -= flow;
	if ( !ret ) nof[ u ] = true;
	return ret;
}

# undef v
# undef PE
# undef ME
}
# endif

# ifdef ACM
namespace Acm
{
struct acmnode
{
	int edge[ 30 ], fail, id, fa;
	void Clean () { id = fa = fail = 0; RST ( edge ); }
};
int asz = 0, q[ SSIZE ], cnt[ NSIZE ];
acmnode acm[ SSIZE ];
char str[ SSIZE ];
# define c *i - 'a' + 1
# define v acm[ u ].edge[ c ]
# define f acm[ acm[ u ].fail ].edge[ c ]
inline void AddString ( char *str, int x )
{
	int u = 0;
	REP_S ( i, str )
	{
		if ( !v ) acm[ v = ++ asz ].Clean ();
		u = v;
	}
	acm[ u ].id = x;
}
inline int Query ( char *str )
{
	int u = 0; 
	REP_S ( i, str ) for ( int tx = u = v; tx; tx = acm[ tx ].fa ) cnt[ acm[ tx ].id ] ++;
}
# undef c
inline void BuildACM ()
{
	int head = 1, tail = 0, u = 0;
	REP ( c, 26 ) if ( v ) q[ ++ tail ] = v;
	while ( head <= tail )
	{
		u = q[ head ];
		REP ( c, 26 )
		{
			if ( v ) acm[ q[ ++ tail ] = v ].fail = f, acm[ v ].fa = acm[ f ].id ? f : acm[ f ].fa;
			else v = f;
		}
		head ++;
	}
}

# undef v
# undef f
}
# endif

# ifdef SAM
namespace Sam
{
# define v sam[ u ].edge[ c ]
struct samnode { int edge[ 30 ], par, l; } sam[ SSIZE * 2 ];
int AddNode ( int lst, int c )
{
	int w = ++ ssz, u = lst; lst = w, sam[ w ].l = sam[ u ].l + 1;
	for ( ; u != -1 && v == -1; u = sam[ u ].par ) v = w;
	if ( u == -1 ) sam[ w ].par = 1;
	else if ( sam[ u ].l + 1 == sam[ v ].l ) sam[ w ].par = v;
	else
	{
		int r = ++ gsz, tv = v;
		CPY ( sam[ r ].edge, sam[ v ].edge ), sam[ r ].par = sam[ v ].par, sam[ r ].l = sam[ u ] + 1, sam[ v ].par = sam[ w ].par = r;
		for ( ; u != -1 && v == tv; u = sam[ u ].par ) v = r;
	}
	return lst;
}
# undef v
}
# endif
