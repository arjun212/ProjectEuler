#include <iostream>
#include <ctime>
#include <fstream>
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

//Map<Position, Value>
static       string FILENAME      = "data.dat" ;

double accumalateData()
{
	ifstream file ;
    file.open( FILENAME );

	double number ;
	double acc = 0;

	while ( file >> number )
	{
		acc += number ;
	}

	return acc ;
}

int main()
{
	startClock() ;

	cout << std::setprecision( 11 ) ;
	returnValue( accumalateData() ) ;

	endClock() ;


	return 0;
}
