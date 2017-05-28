#include <iostream>
#include <cmath>
#include <vector>

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


double firstPrimeAfter( double value )
{
	do
	{
		++value ;
	} while ( !isPrime( value ) ) ;

	return value ;

}


int main()
{

	startClock() ;

	vector< double > primes ;

	primes.push_back( 2 ) ;
	primes.push_back( 3 ) ;

	while ( primes.size() != 10001 )
	{
		primes.push_back( firstPrimeAfter( primes.back() ) ) ;
	}


	returnValue( primes[ 10000 ] ) ;

	endClock() ;

	return 0;
}
