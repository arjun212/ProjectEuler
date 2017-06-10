#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <tuple>


using namespace std;

static int s_clock ;

static void startClock()
{
	s_clock = clock() ;
}

static void endClock()
{
	int e_clock = clock() ;

	cout << "Execution Time is - " << (e_clock-s_clock)/double(CLOCKS_PER_SEC)*1000 << "\n" ;
}


template< typename T >
void returnValue( T returnVal )
{
	cout << "\n"                            ;
	cout << "The Answer is : " << returnVal ;
	cout << "\n"                            ;
}

//Map<Position, Value>
static       string FILENAME      = "data.dat" ;
static const int GW               = 20         ; // GridWidth
static const int GL               = 20         ; // GridLength
static       int data[ GW ][ GL ]              ;


void populateData()
{
	ifstream file ;
    file.open( FILENAME );

	int word ;

	int x = 0 ;
	int y = 0 ;

	while ( file >> word )
	{
		data[ y ][ x ] = word ;

		++x ; 
		x %= GW ;

		if ( x == 0 )
			++y ;
	}
}

bool checkIfInvalidCoord( int x, int y )
{
	return ( x < 0 ) || ( y < 0 ) || ( x >= GW ) || ( y >= GL ) ;
}

bool checkIfValid( const vector< tuple< int, int > > & coords )
{
	for ( int i = 0 ; i < coords.size() ; ++i )
	{
		tuple< int, int > coord = coords[ i ] ;
		if ( checkIfInvalidCoord( get< 0 >( coord ), get< 1 >( coord )  ) )
			return false ;
	}
	return true ;
	
}

int multiplyCoords( const vector< tuple< int, int > > & coords )
{

	int acc = 1 ;

	for ( int i = 0 ; i < coords.size() ; ++i )
	{
		tuple< int, int > coord = coords[ i ] ;

		acc *= data[ get<0>( coord ) ][ get<1>( coord ) ] ;
	}

	return acc ;
}

int productUp( int x, int y )
{
	vector< tuple< int, int > > coords { make_tuple( x , y     ) , 
										 make_tuple( x , y + 1 ) , 
										 make_tuple( x , y + 2 ) , 
										 make_tuple( x , y + 3 ) } ;

	if ( !checkIfValid( coords ) )
		return -1 ;

	return multiplyCoords( coords ) ;

}

int productRight( int x, int y )
{
	vector< tuple< int, int > > coords { make_tuple( x     , y ) , 
										 make_tuple( x + 1 , y ) , 
										 make_tuple( x + 2 , y ) , 
										 make_tuple( x + 3 , y ) } ;

	if ( !checkIfValid( coords ) )
		return -1 ;

	return multiplyCoords( coords ) ;
}

int productDiagLeftUp( int x, int y )
{
	vector< tuple< int, int > > coords { make_tuple( x     , y     ) , 
										 make_tuple( x - 1 , y + 1 ) , 
										 make_tuple( x - 2 , y + 2 ) , 
										 make_tuple( x - 3 , y + 3 ) } ;

	if ( !checkIfValid( coords ) )
		return -1 ;

	return multiplyCoords( coords ) ;
}

int productDiagRightUp( int x, int y )
{
	vector< tuple< int, int > > coords { make_tuple( x     , y   ) , 
										 make_tuple( x + 1 , y+1 ) , 
										 make_tuple( x + 2 , y+2 ) , 
										 make_tuple( x + 3 , y+3 ) } ;

	if ( !checkIfValid( coords ) )
		return -1 ;

	return multiplyCoords( coords ) ;
}

int biggestProduct( int x, int y )
{

	int vals [ 4 ] = { productUp          ( x , y ) ,
	                   productRight       ( x , y ) ,
	                   productDiagLeftUp  ( x , y ) ,
	                   productDiagRightUp ( x , y )
	                 } ;

	int biggest = 0 ;

	for ( int i = 0 ; i < 4 ; ++i )
	{
		if ( vals[ i ] > biggest )
			biggest = vals[ i ] ;
	}

	return biggest ;
}

int main()
{
	startClock() ;

	populateData() ;

	int biggestSoFar = 0 ; 

	for( int i = 0 ; i < GW ; ++i )
	{
		for( int j = 0; j < GL ; ++j )
		{
			int product = biggestProduct( i, j ) ;
			if ( product > biggestSoFar )
				biggestSoFar = product ;
		}
	}

	returnValue( biggestSoFar ) ;

	endClock() ;


	return 0;
}
