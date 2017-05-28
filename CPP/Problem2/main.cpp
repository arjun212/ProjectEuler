
#include <iostream>
#include <map>
#include <iomanip>

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

static map< int, int > fibValueMap ;

template< typename T >
void returnValue( T returnVal )
{
	cout << "\n" ;
	cout << "The Answer is : " << returnVal ;
	cout << "\n" ;
	cout << "\n" ;
}


int fibAux( int i )
{
	if ( i == 1 )
		return 1 ;
	
	if ( i == 2 )
		return 2 ;

	return fibAux( i - 1 ) + fibAux( i - 2 ) ;
}

int fib( int i )
{
	if ( fibValueMap.find( i ) != fibValueMap.end() )
		return fibValueMap.find( i )->second ;

	if ( fibValueMap.find( i-1 ) == fibValueMap.end() )
		fibValueMap[ i-1 ] = fibAux( i-1 ) ; 

	if ( fibValueMap.find( i-2 ) == fibValueMap.end() )
		fibValueMap[ i-2 ] = fibAux( i-2 ) ; 

	return fibValueMap[ i-1 ] + fibValueMap[ i-2 ] ;

}


int main()
{

	startClock() ;

	fibValueMap[ 0 ] = 1 ;
	fibValueMap[ 1 ] = 1 ;
	fibValueMap[ 2 ] = 2 ;

	int i = 1               ;
	double acc = 0             ;
	int fibValue = fib( i ) ;


	while ( fibValue <= 4000000 )
	{
		if ( fibValue % 2 == 0 )
		{
			acc += fibValue ;
		}
		++i ;
		fibValue = fib( i ) ;
	}

	cout << std::fixed ;
	cout << std::setprecision( 2 ) ;
	returnValue( acc ) ;

	endClock() ;

	return 0;
}


