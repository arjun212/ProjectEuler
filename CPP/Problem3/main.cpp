#include <iostream>
#include <math.h> 
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
	cout << "\n" ;
	cout << "The Answer is : " << returnVal ;
	cout << "\n" ;
}


double largestValueInVector( const vector<double> & values  )
{

	double largestValSeen = 0 ;

	for ( vector<double>::const_iterator it = values.begin()  , 
		 					   	         itEnd = values.end() ; it != itEnd; ++it )
	{
		if ( *it > largestValSeen )
			largestValSeen = *it ;
	}

	return largestValSeen ;
}

bool isPrime( double val )
{
	for ( double i = 2; i <= sqrt( val ) + 1; ++i )
	{
		if ( fmod( val, i ) == 0)
			return false ;
	}
	return true ;
}


bool isFactor( double val, double base )
{
	return fmod( base, val) == 0 ;
}

vector< double > * getPrimeFactors( double & val )
{
	vector< double > * result = new vector< double >() ;

	for ( double i = 2; i < sqrt( val ); ++i )
	{
		if ( isPrime( i ) && isFactor( i, val ) )
			result->push_back( i ) ;
	}

	return result ;
}


int main()
{

	startClock() ;

	double value = 600851475143 ;
	vector< double > * primeFactors = getPrimeFactors( value ) ;

	returnValue( largestValueInVector( *primeFactors ) ) ;

	delete primeFactors ;

	endClock() ;

	return 0 ;
}
