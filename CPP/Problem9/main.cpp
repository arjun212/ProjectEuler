#include <iostream>
#include <cmath>

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


bool isPythagoreanTriplet( int a, int b, int c )
{
	return (pow( a, 2 ) + pow( b, 2 )) == pow( c, 2 ) ;
}

int main()
{

	startClock() ;

	for ( int a = 0 ; a < 1000 ; ++a )
	{
		for ( int b = a ; b < 1000 ; ++b )
		{
			int c = 1000 - a - b ;
			if ( ( c > a ) && ( c > b ) && ( isPythagoreanTriplet( a, b, c ) ) )
			{
				returnValue( a * b * c ) ;

				endClock() ;

				return 0;
			}
		}

	}


	return 0;
}
