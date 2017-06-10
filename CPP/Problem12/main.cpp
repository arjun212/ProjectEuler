#include <iostream>
#include <ctime>
#include <cmath>
#include <vector> 
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


template< typename T >
void returnValue( T returnVal )
{
	cout << "\n"                            ;
	cout << "The Answer is : " << returnVal ;
	cout << "\n"                            ;
}

inline bool isFactor( int val, int base )
{
	return base % val == 0 ;
}

int getPrimeFactorsSize( int val )
{
	vector< int > result { 1, val } ;

	for ( int i = 2; i <= sqrt( val ) + 1; ++i )
	{
		if ( isFactor( i, val ) )
		{
			result.push_back( i ) ;

			if ( i != ( val / i ) )
				result.push_back( val / i ) ;
		}
	}

	return result.size() ;
}

int main()
{
	startClock() ;

	int i           = 2 ;
	int triangleNum = 1 ;

	while ( getPrimeFactorsSize( triangleNum ) < 500 )
	{
		triangleNum += i ;
		++i ;
	}

	returnValue( triangleNum ) ;

	endClock() ;


	return 0;
}
