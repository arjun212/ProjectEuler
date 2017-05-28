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



int main()
{

	startClock() ;

	int MAX = 100 ;

	int sumOfSquares = 0 ;
	int sum          = 0 ;

	for ( int i = 1 ; i <= MAX ; ++i )
	{
		sumOfSquares += pow( i, 2 ) ;

		sum += i ;
	}

	int squareOfSum = pow( sum, 2 ) ;

	returnValue( squareOfSum - sumOfSquares ) ;


	endClock() ;

	return 0;
}
