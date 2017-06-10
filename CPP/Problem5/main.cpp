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


bool isFactor( int val, int base )
{
	return base % val == 0 ;
}

vector< int > getPrimeFactors( int & val )
{
	vector< int > result ;

	if ( isPrime( val ) )
	{
		result.push_back( val ) ;
		return result ;
	}

	for ( int i = 2; i <= val / 2; ++i )
	{
		if ( isPrime( i ) && isFactor( i, val ) )
			result.push_back( i ) ;
	}

	return result ;
}

int getOccurencesOfFactor( int factor, int value )
{
	int i = 0 ;
	while ( value % factor == 0 )
	{
		value = value / factor ;
		++i ;
	}
	return i ;
}

void updateFactorsMap( int value, const vector< int > & primeFactors, map< int, int > & factorsMap )
{
	for ( vector<int>::const_iterator it    = primeFactors.begin() ,
		                              itEnd = primeFactors.end()   ; it != itEnd ; ++it )
	{
		int occurences = getOccurencesOfFactor( *it, value ) ;

		if ( factorsMap.find( *it ) == factorsMap.end() )
		{
			factorsMap[ *it ] = occurences ;
		}
		else
		{
			factorsMap[ *it ] = ( factorsMap[ *it ] < occurences ) ? occurences : factorsMap[ *it ] ;
		}
	}
}

double getValueFromFactorsMap( const map< int, int > & factorsMap )
{
	double acc = 1 ;

	for ( map< int, int >::const_iterator it    = factorsMap.begin() ,
	                                      itEnd = factorsMap.end()   ; it != itEnd ; ++it )
	{
		acc *= pow( it->first, it->second ) ;
	}

	return acc ;

}

int main()
{
	startClock() ;

	map< int, int > factorsMap                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ;

	for ( int i = 2; i <= 20; ++i )
	{
		vector< int > primeFactors = getPrimeFactors( i ) ;

		updateFactorsMap( i, primeFactors, factorsMap ) ;
		
	}
	
	cout << std::fixed ;
	cout << std::setprecision( 2 ) ;
	returnValue( getValueFromFactorsMap( factorsMap ) ) ;

	endClock() ;


	return 0;
}
