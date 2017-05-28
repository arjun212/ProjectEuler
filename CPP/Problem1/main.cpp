#include <iostream>

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

static int MAX_VALUE = 1000 ;


bool isMultiple( int value, int base )
{
	return (value % base == 0) ;
}



template< typename T >
void returnValue( T returnVal )
{
	cout << "\n"                            ;
	cout << "The Answer is : " << returnVal ;
	cout << "\n"                            ;
}



int main()
{

	startClock() ;

	int acc = 0 ;

	for( int i = 0; i != MAX_VALUE; ++i )
	{

		if ( isMultiple( i, 3 ) || 
			 isMultiple( i, 5 )   )
		{
			acc += i ;
		}
	}

	returnValue( acc ) ;

	endClock() ;

	return 0;
}
