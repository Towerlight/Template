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