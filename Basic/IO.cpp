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