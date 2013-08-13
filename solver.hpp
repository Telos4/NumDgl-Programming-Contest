/**
  *
  *	@author: Simon Pirkelmann
  *
  */
#ifndef CProg_H
#define CProg_H

#include <cmath>    // Für fabs
#include <iostream>

class CProg
{
    public:
        static CProg solver;

        // Approximations-Methode
        void approximate ( double * x );

        /*
            Funktion für die Dgl
            Die Anzahl der Rechenoperationen wurde deutlich reduziert durch ein multivariates Hornerschema (Algorithmus liegt bei)
            */
        inline void f ( double x0, double x1, double & res0, double & res1 )
        {
            res0 =  x0 * ( 40.0 + x0 * ( x0 * ( -100.0 + x0 * ( x0 * ( 80.0 + x0 * ( x0 * -20.0 ) ) ) ) ) )
                    + x1 * ( -2.0 + x0 * 4.0 + x1 * ( 40.0 + x0 * ( -100.0 + x0 * ( 100.0 + x0 * ( 160.0 + x0 * ( -240.0 + x0 * ( -60.0 + x0 * 100.0 ) ) ) ) )
                             + x1 * ( -4.0 + x1 * ( -100.0 + x0 * ( 180.0 + x0 * ( -160.0 + x0 * ( 100.0 + x0 * ( 180.0 + x0 * -180.0 ) ) ) ) + x1 * ( x1 * ( -20.0 + x0 * ( -180.0
                                                    + x0 * ( 220.0 + x0 * ( -120.0 + x0 * 100.0 ) ) ) + x1 * ( x1 * ( 140.0 + x0 * ( -180.0 + x0 * ( -120.0 + x0 * 100.0 ) ) + x1 * ( x1 * ( 20.0
                                                            + x0 * ( 180.0 + x0 * -180.0 ) + x1 * ( x1 * ( -60.0 + x0 * 100.0 + x1 * -20.0 * x1 ) ) ) ) ) ) ) ) ) ) ) );

            res1 =  x0 * 2.0 + x1 * ( 40.0 + x0 * ( x0 * ( -100.0 + x0 * ( x0 * ( 80.0 + x0 * ( x0 * -20.0 ) ) ) ) )
                                      + x1 * ( -2.0 + x1 * ( -100.0 + x0 * ( 200.0 + x0 * ( 160.0 + x0 * ( -320.0 + x0 * ( -60.0 + x0 * 120.0 ) ) ) )
                                               + x1 * ( x1 * ( -20.0 + x0 * ( -320.0 + x0 * ( 420.0 + x0 * ( 240.0 + x0 * -300.0 ) ) ) + x1 * ( + x1 * ( 140.0
                                                       + x0 * ( -200.0 + x0 * ( -360.0 + x0 * 400.0 ) ) + x1 * ( x1 * ( 20.0 + x0 * ( 240.0 + x0 * -300.0 )
                                                               + x1 * ( x1 * ( -60.0 + x0 * 120.0 + x1 * -20.0 * x1 ) ) ) ) ) ) ) ) ) ) );
        }


    private:

        // Schrittweite
        double m_h;

        // Vektoren für beide berechnete Lösungen x_1 und x_2, sowie Startvektor
        double x_1[2], x_2[2], x_start[2];

        // Variablen für die Zeit
        double t_temp;
        double t_neu;

        // Variablen für die Fehlerschätzung
        double err;
        double temp;

        // Vektoren für die k's
        double k0[2], k1[2], k2[2], k3[2], k4[2], k5[2], k6[2], k7[2], k8[2], k9[2], k10[2], k11[2], k12[2];
};

#endif // CProg
