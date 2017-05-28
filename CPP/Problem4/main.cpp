#include <iostream>
#include <string> 
#include <vector> 
#include <ctime>

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

void splitString2( const string & valString, string & top, string & bottom )
{
	top    = valString.substr( 0, valString.size() / 2 ) ;
	bottom = valString.substr(    valString.size() / 2 ) ;
}

void splitString3( const string & valString, string & top, string & bottom )
{
	top    = valString.substr( 0, valString.size() / 2      ) ;
	bottom = valString.substr(   (valString.size() / 2) + 1 ) ;
}

void splitString( const string & valString, string & top, string & bottom )
{
	if ( valString.size() % 2 == 0 )
	{
		splitString2( valString, top, bottom ) ;
	}
	else
	{
		splitString3( valString, top, bottom ) ;
	}
}

void flip( string & bottom )
{
	string reversed( bottom.rbegin(), bottom.rend() ) ;
	bottom = reversed ;
}

bool isPalindrome( int value )
{

	string valString = std::to_string( value ) ;

	string top    ;
	string bottom ;

	splitString( valString, top, bottom ) ;

	flip( bottom ) ;

	return top == bottom ;
}


template< typename T >
T largestValueInVector( const vector<T> & values  )
{

	T largestValSeen = values.at( 0 ) ;

	for ( typename vector<T>::const_iterator it    = values.begin()  , 
		 		          			   	     itEnd = values.end() ; it != itEnd; ++it )
	{
		if ( *it > largestValSeen )
			largestValSeen = *it ;
	}

	return largestValSeen ;
}


int main()
{

	startClock() ;

	vector< int > palindromes ;

	for ( int i = 100; i < 999; ++i )
	{
		for ( int j = i; j < 999; ++j )
		{
			int ij = i * j ;

			if ( isPalindrome( ij ) )
			{
				palindromes.push_back( ij ) ;
			}
		}
	}

	returnValue( largestValueInVector( palindromes ) ) ;

	endClock() ;

	return 0;
}
