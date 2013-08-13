/**
  *
  *	@author: Simon Pirkelmann
  *
  */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <time.h>

#include "impl.cpp"

void ode_init();
void ode_calc ( double * x );

int main ( int argc, char * argv[] )
{
    double total_time;

    if ( argc != 2 )
    {
        std::cout << "Usage: " << argv[0] << " <time>" << std::endl;
        exit ( 1 );
    }
    else
    {
        total_time = atof ( argv[1] );
    }

    ode_init();

    double result1[2];
    double result2[2];

    int i = 0;
    double t_end;
    double t_start = clock();

    do
    {
        i++;
        ode_calc ( result1 );
        t_end = clock();

        std::cout << ( t_end - t_start ) / CLOCKS_PER_SEC << " of " << total_time << " seconds" << "\r";
        std::flush ( std::cout );
    }
    while ( ( t_end - t_start ) / CLOCKS_PER_SEC < total_time );


    ode_calc ( result2 );

    std::cout << std::endl;

    std::cout << "count: " << i << std::endl;

    std::cout << "average time: " << std::setprecision ( 10 ) << std::fixed << ( t_end - t_start ) / ( CLOCKS_PER_SEC * i ) << " seconds " << std::endl;

    if ( result1[0] != result2[0] || result1[1] != result2[1] )
    {
        std::cout << "Fehler: Ergebnisse von zwei Aufrufen stimmen nicht ueberein!" << std::endl;
    }

    if ( abs ( round ( result1[0] * 1e9 ) / 1e9 - 1.238959350 ) < 1e-14 && abs ( round ( result1[1] * 1e9 ) / 1e9 - 0.911804391 ) < 1e-14 )
    {
        std::cout << "Das Ergebnis ist korrekt!" << std::endl;
    }
    else
    {
        std::cout << "Fehler: falsches Ergebnis" << std::endl;
    }

    return 0;
}
