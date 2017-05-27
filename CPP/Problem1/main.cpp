#include <iostream>

using namespace std;

static int MAX_VALUE = 1000 ;


bool isMultiple( int value, int base )
{
	return (value % base == 0) ;
}



template< typename T >
void returnValue( T returnVal )
{
	cout << "\n" ;
	cout << "The Answer is : " << returnVal ;
	cout << "\n" ;
}



int main()
{

	int acc = 0 ;

	for( int i = 0; i != MAX_VALUE; ++i )
	{

		if ( isMultiple( i, 3 ) || isMultiple( i, 5 ) )
		{
			acc += i ;
		}
	}

	returnValue( acc ) ;

	return 0;
}
