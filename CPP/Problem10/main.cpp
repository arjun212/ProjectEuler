#include <iostream>
#include <cmath>
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


template< typename T >
void returnValue( T returnVal )
{
	cout << "\n"                            ;
	cout << "The Answer is : " << returnVal ;
	cout << "\n"                            ;
}


bool isPrime( int val )
{
	if ( val == 2 || val == 3 )
		return true ;

	for ( int i = 2; i <= sqrt( val ) + 1; ++i )
	{
		if ( val % i == 0)
			return false ;
	}
	return true ;
}


int main()
{

	startClock() ;

	double acc = 0 ;

	for (int i = 2 ; i < 2000000 ; ++i )
	{
		acc += isPrime( i ) ? i : 0 ;
	}

	cout << std::fixed ;
	cout << std::setprecision( 2 ) ;
	returnValue( acc ) ;

	endClock() ;

	return 0;
}
